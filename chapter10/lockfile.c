#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
void lock(int,int,int);
void unlock(int,int,int);

int main(int argc, char **argv) {
	
	int fd = open(argv[1], O_WRONLY);
	int start = atoi(argv[2]);
	int len = atoi(argv[3]);
	printf("I am %d\n",getpid());
	lock(fd, start, len);
	sleep(10);
	unlock(fd, start, len);
	sleep(10);

	return 0;
}


void lock(int fd, int start, int len)
{
	printf("locking\n");
	struct flock lock;
	
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = start;
	lock.l_len = len;

	fcntl(fd, F_SETLKW, &lock);
	printf("locked\n");
}


void unlock(int fd, int start, int len)
{
	printf("unlocking\n");
	struct flock lock;

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = start;
	lock.l_len = len;

	fcntl(fd, F_SETLKW, &lock);
	printf("unlocked\n");
}

