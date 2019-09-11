#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo)
{
	if(signo == SIGALRM) {
		printf("Boom!\n");
		alarm(5);
	}
}

int main() {
	signal(SIGALRM, handler);
	alarm(5);
	
	while(1);
	return 0;
		
}
