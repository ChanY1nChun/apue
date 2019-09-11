#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_once_t initflag = PTHREAD_ONCE_INIT;

void thread_init();
void *th_fn(void*);

int main() {

	pthread_t td1, td2;

	pthread_create(&td1, NULL, th_fn, "Cajx");
	pthread_create(&td2, NULL, th_fn, "asdq");

	pthread_join(td1, NULL);
	pthread_join(td2, NULL);

	

	return 0;
}

void thread_init()
{
	printf("Initliazing!\n");
}

void *th_fn(void *arg)
{
	pthread_once(&initflag, thread_init);
	printf("I am %s\n", (char*)arg);
	return NULL;
}
