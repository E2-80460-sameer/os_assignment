#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>


int main(void)
{
	int sigid,prid;
	printf("Enter the process id : ");
	scanf("%d",&prid);

	printf("Enter the signal no . : ");
	scanf("%d",&sigid);

 	kill(prid,sigid);
	
	printf("process killed successfully !!!\n");

return 0;
}


