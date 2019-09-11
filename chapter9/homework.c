#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

int finish = 0;

void *do_homework(void*);
void *check_homework(void*);

int main() {
	
	pthread_t td1, td2;
	
	pthread_cond_init(&cond, NULL);
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&td1, NULL, do_homework, NULL);
	pthread_create(&td2, NULL, check_homework, NULL);

	pthread_join(td1, NULL);
	pthread_join(td2, NULL);
		
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);

	return 0;
}


void *do_homework(void *arg)
{
	sleep(5);

	pthread_mutex_lock(&mutex);

	finish = 1;

	pthread_mutex_unlock(&mutex);

	pthread_cond_signal(&cond);

	printf("sending the signal!\n");
}


void *check_homework(void *arg)
{
	sleep(1);
	
	pthread_mutex_lock(&mutex);

	printf("teacher:homework finish?\n");

	while(finish == 0) {
		printf("student:Not yet!\n");
		
		printf("teacher:Keep going!\n");

		pthread_cond_wait(&cond, &mutex);

		printf("teacher:homework finish?\n");
	}

	printf("student:Yep!\n");

	pthread_mutex_unlock(&mutex);

	printf("checking!\n");
}




















