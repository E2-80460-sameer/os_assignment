#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

void sigint_handler(int sig);
int main(void)
{
	signal(SIGINT,sigint_handler);
	char cmd[512],*ptr,*args[32];
	int i ,ret,s,err;
	while(1)
	{
		printf("cmd->");
		gets(cmd);
		
		i = 0;
		ptr = strtok(cmd, " ");
		args[i] =ptr;
		i++;
		do
		 {
		   ptr = strtok(NULL, " ");
		   args[i] =ptr ;
		   i++;
		 }while(ptr != NULL);
	  if(strcmp(args[0],"exit")==0)
	    {
		_exit(0);//exit from the shell program
            }
	  else if(strcmp (args[0],"cd")==0)
            {
		chdir(args[1]); //change the current directory
            }

	   else 
		{
		 ret =fork();
		 if(ret == 0)
			{
			  err = execvp(args[0],args);
			  if(err < 0)
			  {
                            perror("bad command");
			   _exit(1);	
			  }
			}
		 else
		   waitpid(-1,&s,0);
		}
                               
	}


return 0;
}


void sigint_handler(int sig)
{
	printf("signal caught : %d \n",sig);

}
