#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void *query(void *arg);
void *buy(void *arg);

int remain = 1000;

pthread_rwlock_t rwlock;

int main() {

	int n;
	int name[100];
	pthread_t td[100];
	pthread_rwlock_init(&rwlock, NULL);

	for(n = 0; n < 100; ++n) name[n] = n;

	for(n = 0; n < 100; ++n) {
		if(n%10 == 0)
			pthread_create(&td[n], NULL, buy, (void*)name[n]);
		else
			pthread_create(&td[n], NULL, query, (void*)name[n]);
	}

	for(n = 0; n < 100; ++n)
		pthread_join(td[n], NULL);
		
	



	pthread_rwlock_destroy(&rwlock);
	printf("remain %d\n", remain);
	return 0;
}


void *query(void *arg)
{
	int name = (int)arg;
	sleep(rand()%5 + 1);
	
	pthread_rwlock_rdlock(&rwlock);
	
	int myremain = remain;
	sleep(1);
	printf("%03d query:%d\n", name, myremain);
	

	pthread_rwlock_unlock(&rwlock);

	pthread_exit(NULL);
}


void *buy(void *arg)
{
	int name = (int)arg;
	
	pthread_rwlock_wrlock(&rwlock);

	int myremain = remain;
	myremain -= 10;
	sleep(1);
	remain = myremain;
	printf("%03d buy 10 tickets, remain:%d\n",name, myremain);

	pthread_rwlock_unlock(&rwlock);

	sleep(rand()%5 + 1);
	pthread_exit(NULL);
	
}
