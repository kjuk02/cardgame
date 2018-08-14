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

int initsem(key_t semkey, int n) {//semaphore를 초기화시킬때 사용
	int status = 0, semid;
	//  	세마포어 값을 설정
	if ((semid = semget(semkey, 1, SEMPERM | IPC_CREAT | IPC_EXCL)) == -1)
	{
		if (errno == EEXIST)
			semid = semget(semkey, 1, 0);
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

int p(int semid) { //p연산을 하며 acquire 할 때 사용된다.
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

int v(int semid) {//v연산을 하며 release 할 때 사용된다.
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
void reset(char *fileVar,int i) {// fileVar라는 이름의 텍스트 화일을 새로 만들고 0값을 기록한다.
	if (access(fileVar, F_OK) == -1) {
		FILE *fp = fopen(fileVar, "w");
		time_t   timer;
		time(&timer);
		fprintf(fp, "PID: %d time: %s%d\n", getpid(), ctime(&timer),i);
		fclose(fp);
	}
}

void Store(char *fileVar, int i) {// fileVar 화일 끝에 i 값을 append한다
	FILE *fp = fopen(fileVar, "a");
	fprintf(fp, "PID: %d %d\n",getpid(), i);
	fclose(fp);
}

int Load(char *fileVar) {// fileVar 화일의 마지막 값을 읽어 온다.
	int num;
	FILE *fp = fopen(fileVar, "r");
	fseek(fp, -4, SEEK_END);
	while (1) {
		fscanf(fp, "%d", &num);
		if (feof(fp)) {
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
	if ((l->semid = initsem(semkey, 1)) < 0)
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
	reset(c->queueLength,0); // queueLength=0
	if ((c->semid = initsem(semkey, 0)) < 0)
		exit(1);
}

void Wait(CondVar *c, Lock *lock) { //condvar와 lock를 받아 wait를 구현한다. add를 통해 queueLength를 증가시켜준다.
	add(c->queueLength, 1);
	Release(lock);
	p(c->semid);
	Acquire(lock);
}

void Signal(CondVar *c) { //condvar를 받아 대기 중인 queueLength가 있다면 활성화 시켜주고 sub를 통해 queueLength를 감소시켜 준다.
	if (Load(c->queueLength) > 0) {
		v(c->semid);
		sub(c->queueLength, 1);
	}
}

void Broadcast(CondVar *c) {//condvar를 받아 대기 중인 queueLength가 있다면 "모두" 활성화 시켜주고 sub를 통해 queueLength를 감소시켜 준다.
	while (Load(c->queueLength) > 0) {
		v(c->semid);
		sub(c->queueLength, 1);
	}
}

void Take_R1(Lock *L1,CondVar *C1) { //R1 젓가락을 가져오기 위한 함수
	Acquire(L1); //L1에 관하여 acquire함으로써 mutual exclisive 하게 해준다.
	while (Load("R1.txt") == 0) {
		/*만약 자원이 없으면 대기 상태에 들어가야 한다. 이때는 이미 젓가락 즉 자원을 하나 얻은 상태이므로
		이때는 자원의 개수가 2보다 작은 상태임을 고려할 필요가 없어진다.*/
		printf("message: %d R1을 기다림 \n",getpid());
		Wait(C1,L1); //wait 상태로 들어간다.
	  printf("message: %d R1을 기다리다가 깨어남 \n",getpid());
	}
	Store("R1.txt", 0); //젓가락을 얻었으므로 R1.txt에 0을 저장시켜준다.
  sub("banker_resource.txt",1); //젓가락을 C철학자가 얻음으로 써 전체 resource는 감소한다.
	add("state.txt",1); //이때 C철학자가 젓가락을 두개 얻어서 밥을 먹을 수 있으므로 state.txt에 1을 저장하여 식사를 하였음을 나타낸다.
	printf("message: %d R1을 얻음 \n",getpid());
	Release(L1); //Take_R1을 수행하였으므로 L1을 Release 시켜준다.
}

void Take_R3(Lock *L1,CondVar *C3) { //R3 젓가락을 가져오기 위한 함수
	Acquire(L1);//L1에 관하여 acquire함으로써 mutual exclisive 하게 해준다.

	while ((Load("R3.txt") == 0) ||((Load("banker_resource.txt")<2)&& (Load("state.txt")==0))) {
	 //만약 자원이 없거나, 남은 자원이 2개 보다 작고 어떤 철학자도 식사를 하지않는다면 이때 wait 상태에 들어가야한다.
		printf("message: %d R3을 기다림 \n",getpid());
		Wait(C3,L1); //wait 상태로 들어간다.
	  printf("message: %d R3을 기다리다가 깨어남 \n",getpid());
	}
	Store("R3.txt", 0); //젓가락을 얻었으므로 R3.txt에 0을 저장시켜준다.
  sub("banker_resource.txt",1); //젓가락을 C 철학자가 얻음으로 써 전체 resource는 감소한다.
	printf("message: %d R3을 얻음 \n",getpid());
	Release(L1); //Take_R3을 수행하였으므로 L1을 Release 시켜준다.
}

void Put_R1(Lock *L1,CondVar *C1) {//R1 젓가락을 놓기 위한 함수 식사를 다하였을 때 수행하게된다.
	Acquire(L1);//L1에 관하여 acquire함으로써 mutual exclisive 하게 해준다.
	Store("R1.txt", 1);//젓가락을 놓았으므로 R1.txt 에 1을 저장시켜준다.
  add("banker_resource.txt",1);//위에서 처럼 자원을 젓가락을 놓았으므로 전체 자원의 개수를 증가시켜준다.
  Signal(C1);//queueR1에 대기중인 철학자를 깨워준다.
  printf("message: %d R1을 내려놓는다.\n",getpid());
	Release(L1);  //Put_R1을 수행하였으므로 L1을 Release 시켜준다.
}

void Put_R3(Lock *L1,CondVar *C3) {//R3 젓가락을 놓기 위한 함수 식사를 다하였을 때 수행하게된다.
	Acquire(L1); //L1에 관하여 acquire함으로써 mutual exclisive 하게 해준다.
	Store("R3.txt", 1);//젓가락을 놓았으므로 R3.txt 에 1을 저장시켜준다.
  add("banker_resource.txt",1); //위에서 처럼 자원을 젓가락을 놓았으므로 전체 자원의 개수를 증가시켜준다.
	sub("state.txt",1);//젓가락을 내려놓는다는 것은 식사를 마쳤다는 의미이기 때문에 state에 1 감소 시켜준다.
	Signal(C3); //queueR3에 대기중인 철학자를 깨워준다.
  printf("message: %d R3을 내려놓는다.\n",getpid());
	Release(L1); //Put_R3을 수행하였으므로 L1을 Release 시켜준다.
}

void Phil_C(Lock *L1,CondVar *C1, CondVar *C3) { //C 철학자가 밥을 먹기 위해 수행하는 함수
 	Take_R3(L1, C3); //R3를 가져오기 위한 함수
 	printf("message: %d 생각을 시작함 \n",getpid());
	sleep(1);
	printf("message: %d 생각을 멈춤 \n",getpid());
	Take_R1(L1, C1);  //R1를 가져오기 위한 함수
	printf("message: %d 가 먹기 시작함 \n", getpid());
	sleep(1);
	printf("message: %d 다 먹었음 \n",getpid());
	Put_R3(L1,C3); //R3를 내려놓기 위한 함수
	Put_R1(L1,C1); //R1를 내려놓기 위한 함수
}

int main(int argc, char * argv[]) {//  서버에서 작업할 때는 자기 학번 등을 이용하여 다른 사람의 키와 중복되지 않게 해야 한다.

//  실행하기 전에 매번 세마포들을 모두 지우거나 아니면 다른 semkey 값을 사용해야 한다.

//  $ ipcs                 // 남아 있는 세마포 확T인

//  $ ipcrm -s <semid>     // <semid>라는 세마포 제거


key_t semkey = 0x100; //semkey값을 지정한다.
key_t semkey_chopsticks1 = 0x200; //semkey_chopsticks1 값을 지정한다.
key_t semkey_chopsticks2 = 0x300; //semkey_chopsticks2 값을 지정한다.
key_t semkey_chopsticks3 = 0x400; //semkey_chopsticks3 값을 지정한다.


reset("banker_resource.txt",3); //전체 resource 관리를 위해 banker_resource.txt 생성
reset("state.txt",0); //철학자가 밥을 먹는지 보기 위한 state.txt 생성
reset("R1.txt",1); //R1.txt파일 생성 만약 있다면 생성하지않는다. 이때 1이란 자원이 존재하는 상태 0이란 자원을 누가 쓰고 있는 상태를 의미한다..
reset("R2.txt",1); //R2.txt파일 생성 만약 있다면 생성하지않는다. 이때 1이란 자원이 존재하는 상태 0이란 자원을 누가 쓰고 있는 상태를 의미한다.
reset("R3.txt",1); //R3.txt파일 생성 만약 있다면 생성하지않는다. 이때 1이란 자원이 존재하는 상태 0이란 자원을 누가 쓰고 있는 상태를 의미한다.

Lock lock1;  //wait, acquire, release에 사용된다

CondVar C1; //R1에 사용되는 condvar
CondVar C2; //R2에 사용되는 condvar
CondVar C3; //R3에 사용되는 condvar

initLock(&lock1, semkey); //lock 초기화 함수
initCondVar(&C1, semkey_chopsticks1, "queueR1.txt"); //R1에 사용하는 condvar 함수 초기화 이때 queueR1의 파일 명을 지정한다.
initCondVar(&C2, semkey_chopsticks2, "queueR2.txt"); //R2에 사용하는 condvar 함수 초기화 이때 queueR2의 파일 명을 지정한다.
initCondVar(&C3, semkey_chopsticks3, "queueR3.txt"); //R3에 사용하는 condvar 함수 초기화 이때 queueR3의 파일 명을 지정한다.

for(int i=0;i<100;i++)
  Phil_C(&lock1,&C1, &C3);

return 0;
}
