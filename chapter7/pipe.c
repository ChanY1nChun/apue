#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
int main() {
	int fd[2];
	pid_t pid;
	char buf[64] = {0};
	pipe(fd);

	pid = fork();
	
	if(pid == 0) {
		close(fd[1]);
		int len;
		while(1) {
			len = read(fd[0],buf,64);
			if(*buf == 'q') {
				close(fd[0]);
				exit(0);
			}
			write(1,buf,len);
			
		}
	} else if(pid > 0) {
		close(fd[0]);
		int len;
		while(1) {
			len = read(0,buf,64);
			if(*buf == 'q') {
				close(fd[1]);
				kill(SIGINT,pid);
				exit(0);
			}
			write(fd[1],buf,len);
		}
	}



	return 0;
}
