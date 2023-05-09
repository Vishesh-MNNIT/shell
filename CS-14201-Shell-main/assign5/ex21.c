#include <stdio.h>
#include <sys/file.h>
#include <error.h>
#include <sys/sem.h>
#define MAXBUF 100
#define KEY 1216
#define SEQFILE "seq_file"
int semid,fd;
void my_lock(int);
void my_unlock(int);

struct sembuf {
	short sem_num;
	short sem_op;
	short sem_flg;
}sbuf;

union semnum
{
    int val;
    struct semid_ds *buf;
    short *array;
}arg;

int main()
{
    int child, i,n, pid, seqno;
    char buff[MAXBUF+1];
    pid=getpid();

    if((semid=semget(KEY, 1, IPC_CREAT | 0666)) == -1)
    {
        perror("semget");
        exit(1);
    }

    arg.val=1;
    if(semctl(semid,0,SETVAL,arg)<0)
    	perror("semctl");
    if((fd=open(SEQFILE,2))<0)
    {
        perror("open");
        exit(1);
    }
    pid=getpid();
    
	for(i=0;i<2;i++)
    {
        my_lock(fd);
        lseek(fd,01,0);
		if((n=read(fd,buff,MAXBUF))<0)
        {
            perror("read");
            exit(1);
        }
        
		printf("pid:%d, Seq no:%dn", pid, seqno);
        seqno++;
        sprintf(buff,"%dn", seqno);
        n=strlen(buff);
        lseek(fd,01,0);
        
		if(write(fd,buff,n)!=n)
        {
            perror("write");
            exit(1);
        }
        sleep(1);
        my_unlock(fd);
    }
	return 0;
}

void my_lock(int fd)
{
    //struct sembuff sbuf;
	sbuf.sem_num=0;
    sbuf.sem_op=-1;
    sbuf.sem_flg=0;
    if(semop(semid, &sbuf, 1) == 0)
	    printf("Locking: Resource...\n");
    else
	    printf("Error in Lock\n");
}

void my_unlock(int fd)
{
	//struct sembuff sbuf;
    sbuf.sem_num=0; 
    sbuf.sem_op=1; 
    sbuf.sem_flg=0;
    if(semop(semid, &sbuf, 1) == 0)
    	printf("UnLocking: Resource...\n");
    else
    	printf("Error in Unlock\n");
}
