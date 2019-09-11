#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void *a(void*);
void *b(void*);
void *c(void*);
void *d(void*);

int i = 1;

int main() {
	
	pthread_t td1, td2, td3, td4;

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

	pthread_create(&td1, NULL, a, NULL);
	pthread_create(&td2, NULL, b, NULL);
	pthread_create(&td3, NULL, c, NULL);
	pthread_create(&td4, NULL, d, NULL);


	pthread_join(td1, NULL);
	pthread_join(td2, NULL);
	pthread_join(td3, NULL);
	pthread_join(td4, NULL);


	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	return 0;
}


void *a(void *arg)
{
	sleep(1);
	while(1) {
		if(i == 1) {

			pthread_mutex_lock(&mutex);

			int mynum = i;
			printf("%d", mynum);
			i = mynum + 1;
	
			pthread_mutex_unlock(&mutex);
		
			pthread_cond_broadcast(&cond);

		}	
	}
}


void *b(void *arg)
{
	sleep(1);
	while(1) {
		if(i == 2) {
			
			pthread_mutex_lock(&mutex);
	
			int mynum = i;
			printf("%d", mynum);
			i = mynum + 1;

			pthread_mutex_unlock(&mutex);

		}
	}
}

void *c(void *arg)
{
	sleep(1);
	while(1) {
		if(i == 3) {
			
			pthread_mutex_lock(&mutex);
	
			int mynum = i;
			printf("%d",mynum);
			i = mynum + 1;
		
			pthread_mutex_unlock(&mutex);

		}
	}
}

void *d(void *arg)
{
	sleep(1);
	while(1) {
		
		if(i == 4) {
			pthread_mutex_lock(&mutex);
			int mynum = i;
			printf("%d", mynum);
			i = mynum + 1;

			pthread_mutex_unlock(&mutex);
		
		}
	}
}
