#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *th_fn(void*);

int main() {
	
	pthread_t td;
	pthread_create(&td, NULL, th_fn, NULL);
	sleep(1);
	pthread_cancel(td);
	printf("thread cancel!\n");
	pthread_join(td, NULL);

	return 0;
}


void *th_fn(void *arg)
{
	int type = PTHREAD_CANCEL_ASYNCHRONOUS;
	pthread_setcanceltype(type, NULL);
	int i, j;
	for(i = 0; i < 1000; ++i)
		for(j = 0; j < 1000000; ++j);
	printf("thread cannot be cancel!\n");
	return NULL;
}


