#include <pthread.h>
#include <unistd.h>
#include <stdio.h>


void *name1(void*);
void *name2(void*);

int tickets = 10;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {

	pthread_t td1, td2;
	
	pthread_create(&td1, NULL, name1, NULL);
	pthread_create(&td2, NULL, name2, NULL);

	pthread_join(td1, NULL);
	pthread_join(td1, NULL);

	return 0;
}

void *name1(void *arg)
{
	int flag = 1;
	while(flag) {
		pthread_mutex_lock(&mutex);

		int t = tickets;
		usleep(1000*20);
		if(t > 0) {
			printf("name1 buy a ticket.\n");
			--t;
			usleep(1000*20);
			tickets = t;
		}

		else flag = 0;

		pthread_mutex_unlock(&mutex);
		usleep(1000*20);
	}

	pthread_exit(NULL);
}


void *name2(void *arg)
{
	int flag = 1;
	while(flag) {
		pthread_mutex_lock(&mutex);

		int t = tickets;
		usleep(1000*20);
		if(t > 0) {
			printf("name2 buy a ticket.\n");
			--t;
			usleep(1000*20);
			tickets = t;
		}
	
		else flag = 0;

		pthread_mutex_unlock(&mutex);
		usleep(1000*20);
	}

	pthread_exit(NULL);
}
