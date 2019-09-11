#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv) {

	key_t key = strtoll(argv[2], NULL, 16);
	char type = argv[1][0];
	int id;
	char buf[64] = {0};
	if(type == '0') {
		id = shmget(key, 4096, IPC_CREAT | IPC_EXCL | 0644);
		strcpy(buf,"shared memory!\n");
	}
	if(type == '1') {
		id = msgget(key, IPC_CREAT | IPC_EXCL | 0644);
		strcpy(buf,"message queue!\n");
	}
	if(type == '2') {
		id = semget(key,5,IPC_CREAT | IPC_EXCL | 0644);
		strcpy(buf,"semaphore!\n");
	}

	printf("create %s at 0x%x, id = %d\n",buf,key,id);
		
	return 0;
}
