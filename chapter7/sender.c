#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char **argv) {
	
	char buf[64] = {0};
	pid_t pid = atoi(argv[1]);
	int len;
	while(1) {

		if(len = read(0,buf,64)) {
			if(*buf == 'q') {
				kill(pid,SIGINT);
				return 0;
			}
			int fd = open("tmp", O_CREAT | O_WRONLY, 0744);

			write(fd,buf,len);

			close(fd);
			kill(pid,SIGUSR1);
		}
	}
	return 0;
} 
