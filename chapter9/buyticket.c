#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/shm.h>
#include <unistd.h>
struct ticket {
	int remain;
	pthread_mutex_t mutex;
};

int main(int argc, char **argv) {

	int id = shmget(0x7777, 0, 0);
	char *name = argv[1];
	int flag = 1;

	struct ticket *t = (struct ticket*)shmat(id, NULL, 0);

	while(flag) {
		pthread_mutex_lock(&t->mutex);
		int remain = t->remain;
		if(remain > 0) {
			sleep(1);
			printf("%s buy a ticket\n", name);
			--remain;
			sleep(3);
			t->remain = remain;
		}
		else flag = 0;
		pthread_mutex_unlock(&t->mutex);
		sleep(2);
	}


	shmdt((void*)t);

	return 0;
}
