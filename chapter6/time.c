#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

	struct tm *mytm;
	time_t t = time(NULL);
	printf("time = %ld\n\n",t);

	mytm = gmtime(&t);
	printf("gmtime\n");
	printf("%d-%d-%d ", mytm->tm_year+1900, mytm->tm_mon+1, mytm->tm_mday);
	printf(" %d-%d-%d\n\n", mytm->tm_hour, mytm->tm_min, mytm->tm_sec);

	mytm = localtime(&t);
	printf("localtime\n");
	printf("%d-%d-%d ", mytm->tm_year+1900, mytm->tm_mon+1, mytm->tm_mday);
	printf(" %d-%d-%d\n\n", mytm->tm_hour, mytm->tm_min, mytm->tm_sec);

	t = mktime(mytm);
	printf("time = %ld\n\n",t);
	return 0;
}
