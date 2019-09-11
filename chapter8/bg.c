#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>

void handler(int);

int main() {
	
	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_handler = handler;

	sigaction(SIGTTOU,&act,NULL);
	sigaction(SIGTTIN,&act,NULL);

	int len;
	char buf[64] = {0};
	
	while(1) {
		len = read(0, buf, 64);
		
		write(1, buf, len);
		
	}	

	return 0;
}


void handler(int signo)
{
	if(signo == SIGTTOU) {
		printf("SIGTTOU signal!\n");
	} else if(signo == SIGTTIN) {
		printf("SIGTTIN signal!\n");
		exit(0);
	}

}
