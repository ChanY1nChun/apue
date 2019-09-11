#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

void handler(int);

int main() {

	printf("I am %d\n", getpid());

	struct sigaction act;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGUSR1,&act,NULL);

	while(1)
		pause();

	return 0;
}


void handler(int signo)
{
	if(signo == SIGUSR1) {
		char buf[64] = {0};
		int fd = open("tmp", O_RDONLY);
		int len = read(fd, buf, 64);
		if(*buf == 'q')
			exit(0);
		write(1,buf,len);

		close(fd);
		unlink("tmp");

		
	}
}
