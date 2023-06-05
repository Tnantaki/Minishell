#include "minishell.h"

// There are 2 signal You have to handle
// 1. Ctrl+C (Interrupt signal) : Display new prompt on new line.
// 2. Ctrl+/ (Quit signal) : does nothing, So I sent sig ignore to it.

void	sigint_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
	}
}

void	set_signal(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	sigemptyset(&sigint.sa_mask);
	sigemptyset(&sigquit.sa_mask);
	sigint.sa_handler = &sigint_handler;
	sigquit.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
}

// int main()
// {
// 	set_signal();
// 	printf("pid :%d\n", getpid());
// 	while (1)
// 	{
// 		sleep(1);
// 	}
// 	return (0);
// }
