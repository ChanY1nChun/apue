#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void *th_fn(void*);

int main() {
	
	pthread_t td;
	pthread_create(&td, NULL, th_fn, NULL);

	pthread_cancel(td);
	printf("cancel thread!\n");
	pthread_join(td, NULL);

	return 0;
}


void *th_fn(void *arg)
{
	int i, j;
	int state = PTHREAD_CANCEL_DISABLE;
	pthread_setcancelstate(state, NULL);
	for(i = 0; i < 1000; ++i)
		for(j = 0; j < 1000000; ++j);
	printf("thread cannot be canceled!\n");

	return NULL;
}
