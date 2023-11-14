#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid, ppid, c_pid;

	/*get the current process ID */
	pid = getpid();
	ppid = getppid();


	printf("Process ID is: %d\n", pid);
	printf("Parent Process ID is: %d\n", ppid);

	c_pid = fork();

	if (c_pid == 0)
	{
	printf("This is a child process\n");
        printf("Parent process ID (PPID): %d\n", getppid());
        printf("Current process ID (PID): %d\n\n", getpid());    
	printf("=====================================\n");
	}
	else if (c_pid > 0)
	{
	 printf("Is a Parent process\n");
         printf("Is child process ID (PID): %d\n\n", c_pid);
           printf("=================================\n");
	}
           else
	   {

	  printf("wrong");
            return (1);
	}

	return (0);

}

