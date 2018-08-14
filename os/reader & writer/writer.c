#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SEMPERM 0600
#define TRUE 1
#define FALSE 0

typedef union   _semun { //semaphore의 구조체
             int val;
             struct semid_ds *buf;
             ushort *array;
             } semun;

int initsem (key_t semkey, int n) {//semaphore를 초기화시킬때 사용
   int status = 0, semid;
//  	세마포어 값을 설정
   if ((semid = semget (semkey, 1, SEMPERM | IPC_CREAT | IPC_EXCL)) == -1)
   {
       if (errno == EEXIST)
                semid = semget (semkey, 1, 0);
   }
   else
   {
       semun arg;
       arg.val = n;
	// 세마포어 제어( setval: 값 설정 )
       status = semctl(semid, 0, SETVAL, arg);
   }
   if (semid == -1 || status == -1)
   {
       perror("initsem failed");
       return (-1);
   }
   return (semid);
}

int p (int semid) { //p연산을 하며 acquire 할 때 사용된다.
   struct sembuf p_buf;
   p_buf.sem_num = 0;
   p_buf.sem_op = -1;
   p_buf.sem_flg = SEM_UNDO;
   if (semop(semid, &p_buf, 1) == -1)
   {
      printf("p(semid) failed");
      exit(1);
   }
   return (0);
}

int v (int semid) {//v연산을 하며 release 할 때 사용된다.
   struct sembuf v_buf;
   v_buf.sem_num = 0;
   v_buf.sem_op = 1;
   v_buf.sem_flg = SEM_UNDO;
   if (semop(semid, &v_buf, 1) == -1)
   {
      printf("v(semid) failed");
      exit(1);
   }
   return (0);
}

// Shared variable by file
void reset(char *fileVar) {// fileVar라는 이름의 텍스트 화일을 새로 만들고 0값을 기록한다.
 if( access(fileVar, F_OK) == -1){
  FILE *fp = fopen(fileVar, "w");
  time_t   timer;
  time(&timer);
  fprintf(fp, "PID: %d time: %s0\n", getpid(), ctime(&timer));
  fclose(fp);
 }
}

void Store(char *fileVar, int i) {// fileVar 화일 끝에 i 값을 append한다
    FILE *fp= fopen(fileVar, "a");
  fprintf(fp, "%d\n", i);
  fclose(fp);
}

int Load(char *fileVar) {// fileVar 화일의 마지막 값을 읽어 온다.
	int num;
  FILE *fp = fopen(fileVar, "r");
	fseek(fp,-4, SEEK_END);
	while(1) {
		fscanf(fp,"%d",&num);
		if(feof(fp)){
			break;
		}
	}

	fclose(fp);
	return num;
}

void add(char *fileVar, int i) {// fileVar 화일의 마지막 값을 읽어서 i를 더한 후에 이를 끝에 append 한다.
  FILE *fp = fopen(fileVar, "a");
  time_t   timer;
  time(&timer);
  int add_num = Load(fileVar);
  add_num += i;
  fprintf(fp, "PID: %d time: %s%d\n", getpid(), ctime(&timer), add_num);
  fclose(fp);
}

void sub(char *fileVar, int i) {// fileVar 화일의 마지막 값을 읽어서 i를 뺀 후에 이를 끝에 append 한다.
  FILE *fp = fopen(fileVar, "a");
  int sub_num = Load(fileVar);
  time_t   timer;
  time(&timer);
  sub_num -= i;
  fprintf(fp, "PID: %d time: %s %d\n", getpid(), ctime(&timer), sub_num);
  fclose(fp);

}
// Class Lock
typedef struct _lock { //lock의 구조체 semid로 이루어졌다.
   int semid;
} Lock;

void initLock(Lock *l, key_t semkey) { //lock 초기화 함수로 세마포를 연결하며 만약 없다면 초기값을 1로 주면서 새로 만들어서 연결한다.
   if ((l->semid = initsem(semkey,1)) < 0)
      exit(1);
}

void Acquire(Lock *l) { //p연산을 이용해 acquire를 구현한다.
   p(l->semid);
}

void Release(Lock *l) {//v연산을 이용해 release를 구현한다.

   v(l->semid);
}

// Class CondVar
typedef struct _cond { //condvar의 구조체 대기열과 semid를 포함한다.
   int semid;
   char* queueLength;
} CondVar;

void initCondVar(CondVar *c, key_t semkey, char* queueLength) {	// queueLength를 받아 condvar queueLength로 지정한다. 또한 세마포를 연결하는데 없으면 초기값을 0로 주면서 새로 만들어서 연결한다.
   c->queueLength = queueLength;
   reset(c->queueLength); // queueLength=0
   if ((c->semid = initsem(semkey,0)) < 0)
      exit(1);
}

void Wait(CondVar *c, Lock *lock) { //condvar와 lock를 받아 wait를 구현한다. add를 통해 queueLength를 증가시켜준다.
   add(c->queueLength,1);
   Release(lock);
   p(c->semid);
   Acquire(lock);
}

void Signal(CondVar *c) { //condvar를 받아 대기 중인 queueLength가 있다면 활성화 시켜주고 sub를 통해 queueLength를 감소시켜 준다.
   if(Load(c->queueLength) > 0){
      v(c->semid);
      sub(c->queueLength,1);
   }
}

void Broadcast(CondVar *c) {//condvar를 받아 대기 중인 queueLength가 있다면 "모두" 활성화 시켜주고 sub를 통해 queueLength를 감소시켜 준다.
   while(Load(c->queueLength) > 0){
      v(c->semid);
      sub(c->queueLength,1);
   }
}

int main(int argc, char * argv[]) {
   //  서버에서 작업할 때는 자기 학번 등을 이용하여 다른 사람의 키와 중복되지 않게 해야 한다.
   //  실행하기 전에 매번 세마포들을 모두 지우거나 아니면 다른 semkey 값을 사용해야 한다.
   //  $ ipcs                 // 남아 있는 세마포 확T인
   //  $ ipcrm -s <semid>     // <semid>라는 세마포 제거

	sleep(atoi(argv[1])); //처음 sleep 인자를 받아온다.
	key_t semkey = 0x200; //semkey값을 지정한다.
	key_t semkey_writer = 0x300; //writer의 semkey값을 지정한다.
	key_t semkey_reader = 0x400; //reader의 semkey값을 지정한다.

	reset("WW.txt"); //WW.txt파일 생성 만약 있다면 생성하지않는다.
	reset("AW.txt"); //AW.txt파일 생성 만약 있다면 생성하지않는다.
	reset("WR.txt"); //WR.txt파일 생성 만약 있다면 생성하지않는다.
	reset("AR.txt"); //AR.txt파일 생성 만약 있다면 생성하지않는다.
	
   pid_t pid; //pid 값을 받기 위한 변수

   Lock lock;  //wait, acquire, release에 사용된다.
   CondVar okToWrite; //writer에 사용되는 condvar
   CondVar okToRead; //reader에 사용되는 condvar

   int AW=0,AR=0,WW=0,WR=0; //초기 값은 0으로 지정
   pid = getpid(); //getpid를 통해 pid의 값을 pid 변수에 저장

   initLock(&lock,semkey); //lock 초기화 함수
   initCondVar(&okToWrite, semkey_writer, "queueLength.txt"); //writer에 사용하는 condvar 함수 초기화 이때 queuelength의 파일 명을 지정한다.
   initCondVar(&okToRead,semkey_reader, "queueLength.txt"); //reader에 사용하는 condvar 함수 초기화 이때 queuelength의 파일 명을 지정한다.

   printf("\nprocess %d before critical section\n", pid);
   Acquire(&lock);   // lock.Acquire()
   printf("process %d in critical section\n",pid);

   AW = Load("AW.txt");
   AR = Load("AR.txt");

   while((AW + AR)>0){ //만약 Aactive Writer나 Active Reader가 존재한다면 wait 해준다.
      add("WW.txt",1);
      Wait(&okToWrite,&lock);
      sub("WW.txt",1);
      AW = Load("AW.txt");
      AR = Load("AR.txt");
   }
   add("AW.txt",1);//한번 써줬기 때문에 1을 더해준다. /* 화일에서 읽어서 1 더하기 */
   
   sleep(atoi(argv[2])); //두번째 슬립인자를 받아온다.

   printf("process %d leaving critical section\n", pid);
   Release(&lock);   // lock.Release()
   printf("process %d exiting\n",pid);
   Acquire(&lock);   // lock.Acquire()
   printf("process %d in critical section\n",pid);
   sub("AW.txt",1);

   WR = Load("WR.txt");
   WW = Load("WW.txt");

   if( WW > 0 ){ //Wating Writer가 있다면 활성화 시켜준다.
	Signal(&okToWrite);
   }
   else if(WR > 0){ //Wating Writer가 없고 Wating Reader가 있다면 현시점에서는 읽기만 하면 되기 때문에 broadcast로 전부다 활성화 시켜준다.
        Broadcast(&okToRead);
   }
   printf("process %d leaving critical section\n", pid);
   Release(&lock);   // lock.Release()
   printf("process %d exiting\n",pid);
   return 0;
}
