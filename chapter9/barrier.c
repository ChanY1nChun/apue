#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_barrier_t barrier;



void *th_fn(void*);

int main() {
	
	pthread_t td[10];

	printf("PTHREAD_BARRIER_SERIAL_THREAD = %d\n", PTHREAD_BARRIER_SERIAL_THREAD);

	pthread_barrier_init(&barrier, NULL, 11);
	
	int n, res;
	for(n = 0; n < 10; ++n) {
		pthread_create(&td[n], NULL, th_fn, (void*)n);
		sleep(1);
	}
	res = pthread_barrier_wait(&barrier);
	
	printf("thread main return %d\n", res);
	
	for(n = 0; n < 10; ++n)
		pthread_join(td[n], NULL);

	pthread_barrier_destroy(&barrier);

	return 0;
}


void *th_fn(void *arg)
{
	int i = (int)arg;
	int res;

	printf("Hello, I am thread %d\n", i);
	res	= pthread_barrier_wait(&barrier);

	printf("thread %d return %d\n", i, res);
	pthread_exit(NULL);
}
