#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main() {
	const char *name = NULL;
	name = getenv("PATH");	
	printf("%s\n", name);
	return 0;
}
