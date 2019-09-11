#include <stdio.h>
#include <stdlib.h>

void my_exit1();
void my_exit2();

int main() {

	atexit(my_exit2);
	atexit(my_exit1);
	atexit(my_exit1);


	printf("main is done\n");


	exit(0);
}

void my_exit1()
{
	printf("first exit handler\n");
}


void my_exit2()
{
	printf("second exit handler\n");
}
