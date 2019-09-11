#include <stdio.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


void create();
void show();
void set();
void rm();
void at_dt();


int main(int argc, char **argv) {

	printf("I am %d\n", getpid());
	
	if(!strcmp(argv[1],"-c"))
		create();
	else if(!strcmp(argv[1],"-v"))
		show();
	else if(!strcmp(argv[1],"-s"))
		set();
	else if(!strcmp(argv[1],"-d"))
		rm();
//	else if(!strcmp(argv[1],"-a"))
	//	at_dt();



	return 0;
}


void create()
{
	int id = shmget(0x7777, 4096, IPC_CREAT | IPC_EXCL | 0664);
	printf("create shm ID %d\n", id);
}


void show()
{
	struct shmid_ds buf;
	int id = shmget(0x7777,0,0);
	shmctl(id, IPC_STAT, &buf);
	
	printf("size of segment in bytes is %u\n", buf.shm_segsz);
	printf("pid of last shmop() is %d\n", buf.shm_lpid);
	printf("pid of creator is %d\n", buf.shm_cpid);
	
	printf("last-attach time is %s\n", ctime(&buf.shm_atime));
	printf("last-detach time is %s\n", ctime(&buf.shm_dtime));
	printf("last-change time is %s\n", ctime(&buf.shm_ctime));

	printf("owner's effective user id is %d\n", buf.shm_perm.uid);
	printf("owner's effective group id is %d\n", buf.shm_perm.gid);
	printf("creator's effective user id is %d\n", buf.shm_perm.cuid);
	printf("creator's effective group id is %d\n", buf.shm_perm.cgid);
	printf("mode is 0%o\n", buf.shm_perm.mode);
}


void rm()
{
	int id = shmget(0x7777,0,0);
	shmctl(id, IPC_RMID, NULL);
	printf("rm %d done!\n", id);
}

void set()
{
	struct shmid_ds buf;
	int id = shmget(0x7777, 0, 0);
	shmctl(id, IPC_STAT, &buf);
	buf.shm_perm.mode = 0600;
	shmctl(id, IPC_SET, &buf);
	printf("%d set\n",id);
}

void ad_dt() {
	int id = shmget(0x7777,4096,IPC_CREAT | 0664);
	char *buf = shmat(id,NULL,0);
	printf("shmat done!\n");
	sleep(5);
	shmdt(buf);
	printf("shmdt done!\n");
}
























