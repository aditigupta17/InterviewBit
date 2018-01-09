#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	pid_t childPIDorZero = fork();//PID = Process ID
	if(childPIDorZero < 0)
	{
		perror("fork");
		exit(1);
	}
	if(childPIDorZero != 0)
	{
		printf("I'm the parent %d, my child is %d.\n", getpid(), childPIDorZero);
		wait(NULL); 	//wait for a child process to join with this parent
	}
	else{
		printf("I'm the child %d, my parent is %d.\n", getpid(), getppid());
		execl("/bin/echo", "echo", "Hello, World!", NULL);
	}
}