#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	char *args[] ={"/bin/ls", "-l", "/tmp", NULL};
	int slider;

	for (slider = 0; slider < 5; slider++)
	{
		pid = fork();

		if (pid == 0)
		{
			execve("/bin/ls", args, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			perror("fork");
		}
	}
	return (0);
}
