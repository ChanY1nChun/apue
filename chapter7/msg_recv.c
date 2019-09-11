#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct myemsg {
	long type;
	int age;
} Msg;
void printfMsg(Msg*);

int main(int argc, char **argv) {
	
	long type = atoi(argv[1]);
	
	int id = msgget(0x7777,0);
	

	Msg msg;

	
	while(1) {
		msgrcv(id, &msg, sizeof(int), type, 0);
		printfMsg(&msg);
	}

	return 0;
}


void printfMsg(Msg *msg)
{
	printf("type is %u, age is %d\n", msg->type, msg->age);
}
