#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <pthread.h>

struct ticket {
	int remain;
	pthread_mutex_t mutex;
};

void printshared(pthread_mutexattr_t*);


int main() {
	
	int id = shmget(0x7777, 4096, IPC_CREAT | IPC_EXCL | 0644);

	struct ticket *t = (struct ticket*)shmat(id, NULL, 0);

	t->remain = 5;

	pthread_mutexattr_t mutexattr;
	pthread_mutexattr_init(&mutexattr);

	printshared(&mutexattr);

	int shared = PTHREAD_PROCESS_SHARED;

	pthread_mutexattr_setpshared(&mutexattr, shared);

	printshared(&mutexattr);

	pthread_mutex_init(&t->mutex, &mutexattr);

	pthread_mutexattr_destroy(&mutexattr);

	shmdt((void*)t);

	return 0;
}

void printshared(pthread_mutexattr_t *attr)
{
	int shared;
	pthread_mutexattr_getpshared(attr, &shared);
	
	if(shared == PTHREAD_PROCESS_SHARED)
		printf("pthread_process_shared\n");
	else if(shared == PTHREAD_PROCESS_PRIVATE)
		printf("pthread_process_private\n");
}
