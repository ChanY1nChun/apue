#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main() {
	
	int id = shmget(0x8888,4096,IPC_CREAT | IPC_EXCL | 0664);
	
	printf("shm ID is %d\n",id);
	
	char *buf = shmat(id, NULL, 0);

	strcpy(buf,"Hello shared memory!\n");

	shmdt(buf);

	return 0;
}
