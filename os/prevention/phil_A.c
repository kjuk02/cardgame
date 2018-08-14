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

void reset(char *fileVar, int value) {// fileVar라는 이름의 텍스트 화일을 새로 만들고 0값을 기록한다.
	if (access(fileVar, F_OK) == -1) {
		FILE *fp = fopen(fileVar, "w");
		time_t   timer;
		time(&timer);
		fprintf(fp, "PID: %d time: %s%d\n", getpid(), ctime(&timer),value);
		fclose(fp);
	}
}

void Store(char *fileVar, int i) {// fileVar 화일 끝에 i 값을 append한다
	FILE *fp = fopen(fileVar, "a");
	fprintf(fp, "PID:%d %d\n",getpid(), i);
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

	fprintf(fp, "PID: %d time: %s%d\n", getpid(), ctime(&timer), sub_num);

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

void Take_R1(Lock *L1, CondVar *C1){//R1 젓가락을 가져오기 위한 함수
	Acquire(L1);//L1에 관하여 acquire함으로써 mutual exclisive 하게 해준다.

	while(Load("R1.txt")==0){ //남은 자원이 없으면 대기한다.
		printf("message: %d가 R1을 기다림 \n",getpid());
		Wait(C1,L1); //wait 상태로 들어간다
		printf("message: %d가 R1을 기다리다가 깨어남 \n",getpid());
	}
	Store("R1.txt",0); //젓가락을 얻었으므로 R1.txt에 0을 저장시켜준다.
	printf("message: %d가 R1을 가져옴 \n",getpid());

	Release(L1);//Take_R1을 수행하였으므로 L1을 Release 시켜준다.
}

void Take_R2(Lock *L2, CondVar *C2){//R2 젓가락을 가져오기 위한 함수
	Acquire(L2); //L2에 관하여 acquire함으로써 mutual exclisive 하게 해준다.

	while(Load("R2.txt")==0){ //남은 자원이 없으면 대기한다.
		printf("message: %d가 R2을 기다림 \n",getpid());
		Wait(C2,L2); //wait 상태로 들어간다.
		printf("message: %d가 R2을 기다리다가 깨어남 \n",getpid());
	}
	Store("R2.txt",0); //젓가락을 얻었으므로 R2.txt에 0을 저장시켜준다.
	printf("message: %d가 R2을 가져옴 \n",getpid());

	Release(L2);//Take_R2을 수행하였으므로 L2을 Release 시켜준다.
}

void Put_R1(Lock *L1, CondVar *C1){//R1 젓가락을 놓기 위한 함수 식사를 다하였을 때 수행하게된다.
	Acquire(L1); //L1에 관하여 acquire함으로써 mutual exclisive 하게 해준다.
	Store("R1.txt",1); //젓가락을 놓았으므로 R1.txt 에 1을 저장시켜준다.
	Signal(C1); //queueR1에 대기중인 철학자를 깨워준다.
	printf("message: %d가 R1을 내려둠 \n",getpid());
	Release(L1); //Put_R1을 수행하였으므로 L1을 Release 시켜준다.
}

void Put_R2(Lock *L2, CondVar *C2){ //R2 젓가락을 놓기 위한 함수 식사를 다하였을 때 수행하게된다.
	Acquire(L2); //L1에 관하여 acquire함으로써 mutual exclisive 하게 해준다.
	Store("R2.txt",1); //젓가락을 놓았으므로 R2.txt 에 1을 저장시켜준다.
	Signal(C2); //queueR1에 대기중인 철학자를 깨워준다.
	printf("message: %d가 R2을 내려둠 \n",getpid());
	Release(L2); //Put_R2을 수행하였으므로 L2을 Release 시켜준다.
}

void Phil_A(Lock *L1, CondVar *C1,Lock *L2, CondVar *C2){//A 철학자가 밥을 먹기 위해 수행하는 함수
Take_R2(L2, C2); //R2를 가져오기 위한 함수
printf("message: %d가 생각을 시작함 \n",getpid());
sleep(1);
printf("message: %d가 생각을 멈춤 \n",getpid());
Take_R1(L1,C1); //R1를 가져오기 위한 함수
printf("message: %d가 먹기 시작함 \n",getpid());
sleep(1);
printf("message: %d가 먹기를 멈춤 \n",getpid());
Put_R2(L2,C2); //R2를 내려놓기 위한 함수
Put_R1(L1,C1);  //R1를 내려놓기 위한 함수
}

int main() {
  //  서버에서 작업할 때는 자기 학번 등을 이용하여 다른 사람의 키와 중복되지 않게 해야 한다.

  //  실행하기 전에 매번 세마포들을 모두 지우거나 아니면 다른 semkey 값을 사용해야 한다.

  //  $ ipcs                 // 남아 있는 세마포 확T인

  //  $ ipcrm -s <semid>     // <semid>라는 세마포 제거


  key_t semkey = 0x100; //semkey값을 지정한다.
	key_t semkey2 = 0x200; //semkey값을 지정한다.
	key_t semkey3 = 0x300; //semkey값을 지정한다.
	key_t semkey_chopsticks1 = 0x400; //semkey_chopsticks1 값을 지정한다.
	key_t semkey_chopsticks2 = 0x500; //semkey_chopsticks2 값을 지정한다.
	key_t semkey_chopsticks3 = 0x600; //semkey_chopsticks3 값을 지정한다.


 reset("R1.txt",1); //R1.txt파일 생성 만약 있다면 생성하지않는다. 이때 1이란 자원이 존재하는 상태 0이란 자원을 누가 쓰고 있는 상태를 의미한다.
 reset("R2.txt",1); //R2.txt파일 생성 만약 있다면 생성하지않는다. 이때 1이란 자원이 존재하는 상태 0이란 자원을 누가 쓰고 있는 상태를 의미한다.
 reset("R3.txt",1); //R3.txt파일 생성 만약 있다면 생성하지않는다. 이때 1이란 자원이 존재하는 상태 0이란 자원을 누가 쓰고 있는 상태를 의미한다.

 Lock lock1;  //wait, acquire, release에 사용된다
 Lock lock2;  //wait, acquire, release에 사용된다
 Lock lock3;  //wait, acquire, release에 사용된다

 CondVar C1; //R1에 사용되는 condvar
 CondVar C2; //R2에 사용되는 condvar
 CondVar C3; //R3에 사용되는 condvar

initLock(&lock1, semkey); //lock 초기화 함수
initLock(&lock2, semkey2); //lock 초기화 함수
initLock(&lock3, semkey3); //lock 초기화 함수
initCondVar(&C1, semkey_chopsticks1, "queueR1.txt"); //R1에 사용하는 condvar 함수 초기화 이때 queueR1의 파일 명을 지정한다.
initCondVar(&C2, semkey_chopsticks2, "queueR2.txt"); //R2에 사용하는 condvar 함수 초기화 이때 queueR2의 파일 명을 지정한다.
initCondVar(&C3, semkey_chopsticks3, "queueR3.txt"); //R3에 사용하는 condvar 함수 초기화 이때 queueR3의 파일 명을 지정한다.

for(int i=0;i<100;i++)
	Phil_A(&lock1,&C1, &lock2, &C2);

  return 0;
}
