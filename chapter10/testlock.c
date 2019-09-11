#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int testlock(int,int,int);

int main(int argc, char **argv) {
	
	int fd = open(argv[1], O_WRONLY);
	int start = atoi(argv[2]);
	int len = atoi(argv[3]);
	int res = testlock(fd, start, len);
	printf("testlock = %d\n", res);
	close(fd);

	return 0;
}

int testlock(int fd, int start, int len)
{
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = start;
	lock.l_len = len;
	
	fcntl(fd, F_GETLK, &lock);
	if(lock.l_type == F_UNLCK) return 0;
	return lock.l_pid;
}
