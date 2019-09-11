#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {

	int id = atoi(argv[2]);
	
	key_t key = ftok(argv[1], id);

	printf("key = 0x%08x\n",key);


	return 0;
}
