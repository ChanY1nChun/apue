#include <stdio.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	
	typedef struct mymesg {
		long mtype;
		int age;
	}Msg;


	int id = msgget(0x7777,IPC_CREAT | 0664);
	
	Msg msg[7] = {
		{1,10},
		{1,17},
		{1,19},
		{2,20},
		{2,29},
		{5,52},
		{5,59}
	};

	int i;
	for(i = 0; i < 7; ++i) {
		msgsnd(id,&msg[i],sizeof(int),0);
	}

	return 0;
}
