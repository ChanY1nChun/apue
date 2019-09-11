#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char **argv) {
	char buf[64] = {0};
	int len;
	pid_t pid = atoi(argv[1]);
	int fd = open("hello",O_WRONLY | O_NONBLOCK);
	while(1) {
		len = read(0,buf,64);
		if(*buf == 'q') {
			close(fd);
			exit(0);
		}
		write(fd,buf,len);
	}

	return 0;	
}
