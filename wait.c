#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t pid1;
	pid_t pid2;
	int	stat1;
	int	stat2;

	pid1 = fork();
	if (pid1 == 0)
	{
		printf("I'm Child 1\n");
		sleep(4);
		return (1);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		printf("I'm Child 2\n");
		sleep(2);
		return (2);
	}
	waitpid(pid1, &stat1, 0);
	waitpid(pid2, &stat2, 0);
	printf("I'm Parent\n");
	printf("stat1 :%d\n", WEXITSTATUS(stat1));
	printf("stat1 :%d\n", WEXITSTATUS(stat2));
}
