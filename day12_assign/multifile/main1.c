#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
int main(void)
{
    int pid2, pid,s,err,err1,a;

    pid = fork();

    if(pid == 0)
    {
      err = execl("/usr/bin/gcc","gcc","circle.c","rectangle.c","square.c","main.c",NULL);  
      if(err<0)
      {
        perror("exec() failed");
        _exit(1);
      }
    }
    wait(&s);
    if(WEXITSTATUS(s)==0)
    {
         pid2 =fork();
        if(pid2 == 0)
        { 
            err1 = execl("/home/sameer/sunbeam/eos/Day-12/class_work/multifile/a.out","./a.out",NULL);
            if(err1<0)
            {
                perror("exec() failed");
                _exit(1);
            }
        }
        
    }
    wait(&a);
    if(WEXITSTATUS(a)==0)
    {
        printf("child exit status : %d \n",WEXITSTATUS(a));
    }
    

    printf("completed\n");
    return 0;
}