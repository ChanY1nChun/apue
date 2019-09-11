#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo);
void setrecur(pthread_mutexattr_t*);
void printtype(pthread_mutexattr_t*);
int recur = 0;

struct ticket {
	int remain;
	pthread_mutex_t mutex;
} t;

int main(int argc, char **argv) {
	if(argc >= 2) recur = 1;
	
	t.remain = 3;
	
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	printtype(&attr);
	if(recur == 1) {
		printf("modfying!\n");
		setrecur(&attr);
		printtype(&attr);
	}		

	pthread_mutex_init(&t.mutex, &attr);
	pthread_mutexattr_destroy(&attr);

	signal(SIGUSR1, handler);
	signal(SIGINT, handler);

	printf("send SIGUSR1\n");
	kill(getpid(), SIGUSR1);

	pthread_mutex_destroy(&t.mutex);

	printf("remain is %d\n", t.remain);

	return 0;
}


void printtype(pthread_mutexattr_t *attr)
{
	int type;
	pthread_mutexattr_gettype(attr, &type);

	if(type == PTHREAD_MUTEX_NORMAL)
		printf("pthread_mutex_normal!\n");
	if(type == PTHREAD_MUTEX_ERRORCHECK)
		printf("pthread_mutex_errorcheck!\n");
	if(type == PTHREAD_MUTEX_RECURSIVE)
		printf("pthread_mutex_recursive!\n");
	if(type == PTHREAD_MUTEX_DEFAULT)
		printf("pthread_mutex_default!\n");

	
}

void setrecur(pthread_mutexattr_t *attr)
{
	int type = PTHREAD_MUTEX_RECURSIVE;
	pthread_mutexattr_settype(attr, type);
}

void handler(int signo)
{
	if(signo == SIGUSR1) printf("receive SIGUSR1!\n");
	else if(signo == SIGINT) printf("receive SIGINT\n");

	pthread_mutex_lock(&t.mutex);

	printf("%s enter handler\n", signo == SIGUSR1 ? "SIGUSR1" : "SIGINT");
	++t.remain;
	sleep(3);
	printf("%s exit handler\n", signo == SIGUSR1 ? "SIGUSR1" : "SIGINT");

	
	pthread_mutex_unlock(&t.mutex);

	
}
