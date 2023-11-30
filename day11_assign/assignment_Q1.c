#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>




int main() 
{
    int i, pid[5], s,count ;
    printf("program started!\n");
	for(int i = 1 ; i<=5 ;i++)
	{
    		pid[i] = fork();
    		if(pid[i] == 0)
		 { // child process
		  
           	   printf("child: %d\n", i);
		   printf("child pid: %d\n",getpid()) ;
		   printf("child ppid : %d\n",getppid());
           	    sleep(1);
		   _exit(3); // child is terminated with exit status=3
		   
        	 }
                else
                  { // parent process
        	    // for(int j=1; j<=5; j++)
                      // {
            		 printf("parent: %d\n", i);
            		 sleep(1);
			
        	         waitpid(pid[i], &s, 0);
            		 if(i == 5) 
                           {
               		   //  waitpid(pid[i], &s, 0);
                             printf("parent: child's exit status: %d\n", WEXITSTATUS(s));
		             printf("parent pid = %d\n ",getpid());
                            }
                      // }
                  }
	    count ++;
          }
    printf("child count = %d \n",count);
    printf("program completed!\n");
    return 0;
}

