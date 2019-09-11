#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
	
	key_t key = strtoll(argv[2], NULL, 16);
	char type = argv[1][0];
	char buf[64] = {0};
	int id;

	if(type == '0') {
		id = shmget(key,0,0);
		strcpy(buf,"shared memory!\n");
	}

	else if(type == '1') {
		id = msgget(key,0);
		strcpy(buf,"message queue!\n");
	}

	else if(type == '2') {
		id = semget(key,0,0);
		strcpy(buf,"semaphore!\n");
	}

	printf("get %s at 0x%x, id is %d\n", buf, key, id);
	

	return 0;
}
