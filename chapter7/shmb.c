#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main() {
	
	printf("I am %d\n",getpid());
	
	int id = shmget(0x8888,0,0);
	
	char *buf = shmat(id, NULL, 0);

	printf("%s\n",buf);

	shmdt(buf);

	shmctl(id, IPC_RMID, NULL);

	return 0;
}
