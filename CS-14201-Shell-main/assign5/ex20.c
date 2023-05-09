#include <stdio.h>
#include <time.h>

void printTime()
{
	time_t s, val = 1;
    struct tm* curr_time;
    s = time(NULL); 
    curr_time = localtime(&s); 
    printf("%02d:%02d:%02d\n", curr_time->tm_hour, curr_time->tm_min, curr_time->tm_sec);

}

int main() {
	for(;;)
	{
		printTime();
		sleep(60);
	}

}





 #include <stdio.h>
     #include <sys/time.h>     
     #include <sys/signal.h>


/* Declarations */
         void main();
     int times_up();


     void main()
     {


        for (; ;)
{
  times_up(1);
sleep(60);


}                        
     }


 int times_up(sig)
     int sig;                            
     {
       long now;
       long  time(struct tms *ptr);
        char *ctime();


        time (&now);
        printf("It is now %s\n", ctime (&now));
return (sig);
     }


