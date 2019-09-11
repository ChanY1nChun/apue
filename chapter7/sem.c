#include "sem.h"



int c(int count)
{
	int id;
	if(count > 0) {
		id = semget(0x7777, count, IPC_CREAT | IPC_EXCL | 0644);
	}	
	else if(count == 0) {
		id = semget(0x7777,0,0);
	}

	return id;
}


void s(int id, int semnum, int val)
{
	semctl(id, semnum, SETVAL, val);
}


void d(int id)
{
	semctl(id, 0, IPC_RMID);
}


void P(int id, int semnum)
{
	struct sembuf op = {semnum, -1, 0};
	semop(id, &op, 1);
}

void V(int id, int semnum)
{
	struct sembuf op = {semnum, +1, 0};
	semop(id, &op, 1);
}

int g(int id, int semnum)
{
	return semctl(id, semnum, GETVAL);
}
