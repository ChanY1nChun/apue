#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/shm.h>
struct ticket {
	int remain;
	pthread_mutex_t mutex;
};

int main() {
	
	int id = shmget(0x7777, 0, 0);
	
	struct ticket *t = (struct ticket*)shmat(id, NULL, 0);

	pthread_mutex_destroy(&t->mutex);

	shmdt((void*)t);

	shmctl(id, IPC_RMID, NULL);

	return 0;
}
