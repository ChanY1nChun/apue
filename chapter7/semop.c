#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include <string.h>

void printSem(int id)
{
	unsigned short val[3];
	semctl(id, 0, GETALL, val);
	printf("R0 = %d, R1 = %d, R2 = %d\n", val[0], val[1], val[2]);
}

int main() {
	
	puts("信号量初始值（默认值）");

	int id = semget(0x7777,3,IPC_CREAT | IPC_EXCL | 0664);
	printSem(id);


	puts("1.设置R2初始值为20");

	semctl(id, 2, SETVAL, 20);
	printSem(id);

	puts("2.同时设置3个信号量为12，5，9");
	
	unsigned short val[3] = {12,5,9};
	
	semctl(id, 0, SETALL, val);
	printSem(id);

	puts("3.请求2个R0资源");
	
	struct sembuf op1 = {0, -2, 0};
	semop(id, &op1, 1);

	printSem(id);

	puts("4.请求3个R1和5个R2");
	
	struct sembuf op2[2] = {
		{1, -3, 0},
		{2, -5, 0}
	};
	semop(id, op2, 2);
	
	printSem(id);

	puts("5.释放2个R1");
	
	struct sembuf op3 = {1, 2, 0};
	semop(id, &op3, 1);

	printSem(id);

	puts("6.释放1个R0，1个R1，3个R2");
	
	struct sembuf op4[3] = {
		{0, 1, 0},
		{1, 1, 0},
		{2, 3, 0}
	};
	semop(id, op4, 3);
	printSem(id);

	puts("7.删除IPC内核对象");
	
	semctl(id, 0, IPC_RMID);



	return 0;

}
