#include "sem.h"
#include <string.h>
#include <sys/shm.h>

#define MUTEX 0
#define FULL 1
#define EMPTY 2

void producer();
void consumer();
void release(int);
void init();
int getsemid();
int getshmid();

int main(int argc, char **argv) {
	
	if(!strcmp("-p", argv[1]))
		producer();
	else if(!strcmp("-c", argv[1]))
		consumer();
	else if(!strcmp("-d", argv[1]))
		release(getsemid());
	else if(!strcmp("-b", argv[1]))
		init();	

	
	return 0;
}


int getsemid()
{
	return c(0);
}

int getshmid()
{
	return shmget(0x7777,0,0);
}

void init()
{
	int id = c(3);
	semctl(id, MUTEX, SETVAL, 1);
	semctl(id, FULL, SETVAL, 0);
	semctl(id, EMPTY, SETVAL, 5);
	int shmid = shmget(0x7777, sizeof(int), IPC_CREAT | IPC_EXCL | 0644);
	int *cake = shmat(shmid, NULL, 0);
	*cake = 0;
	shmdt(cake);
}

void release(int id)
{
	d(id);
	shmctl(getshmid(), IPC_RMID, NULL);
}


void producer()
{
	int id = getsemid();
	int shmid = getshmid();
	int *cake = shmat(shmid, NULL, 0);
	
	while(1) {
		
		P(id, EMPTY);
		P(id, MUTEX);

		printf("current cakes = %d, ", *cake);
		++(*cake);
		printf("produced a cake, ");
		printf("cakes = %d\n", *cake);
		
		V(id, FULL);
		V(id, MUTEX);
	
		sleep(1);
	}

	shmdt(cake);
}

void consumer()
{
	int id = getsemid();
	int shmid = getshmid();
	int *cake = shmat(shmid, NULL, 0);

	while(1) {

		P(id, FULL);
		P(id, MUTEX);

		printf("current cakes = %d, ", *cake);
		--(*cake);
		printf("consumed a cake, ");
		printf("cakes = %d\n", *cake);
		
		V(id, EMPTY);
		V(id, MUTEX);

		sleep(1);
		
	}
	
	shmdt(cake);
}

