#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *th_fn1(void*);
void destructor(void*);

pthread_key_t key;

int main() {
	
	pthread_t td1, td2;

	pthread_key_create(&key, destructor);
	pthread_create(&td1, NULL, th_fn1, (void*)5);
	pthread_create(&td2, NULL, th_fn1, (void*)10);

	
	pthread_join(td1, NULL);
	pthread_join(td2, NULL);

	return 0;
}

void *th_fn1(void *arg)
{
	pthread_setspecific(key, (void*)arg);
    int data = (int)pthread_getspecific(key);
	printf("data is %d\n", data);
	return NULL;
}

void destructor(void *arg)
{
	printf("destructor %d\n", (int)arg);
}
