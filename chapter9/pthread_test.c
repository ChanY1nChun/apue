#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *th_fn1(void*);
void *th_fn2(void*);

int main() {
	
	pthread_t td1, td2;
	void *ret;
	
	pthread_create(&td1, NULL, th_fn1, NULL);
	pthread_create(&td2, NULL, th_fn2, NULL);

	pthread_join(td1, &ret);
	printf("thread 1 exit code %d\n", (int)ret);
	pthread_join(td2, &ret);
	printf("thread 2 exit code %d\n", (int)ret);

	return 0;
	
}


void *th_fn1(void *arg)
{
	printf("thread 1 return\n");
	return (void*)10;
}

void *th_fn2(void *arg)
{
	printf("thread 2 return\n");
	pthread_exit((void*)20);
}


