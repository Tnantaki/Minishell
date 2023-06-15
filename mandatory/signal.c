/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:29:08 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:29:09 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ### set_signal ###
// There are 2 signal You have to handle
// 1. Ctrl+C (Interrupt signal) : Display new prompt on new line.
// 2. Ctrl+/ (Quit signal) : does nothing, So I sent sig ignore to it.
// ### set_termios ###
// 1. get the old terminal control for restore
// 2. get the new terminal control for using in this program
// 3. set the new terminal control by disable echoctl for not display ^C

int	g_status;

void	sigint_handler(int signum)
{
	(void)signum;
	g_status = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	// rl_replace_line("", 0);
	rl_redisplay();
}

void	sigint_wait_handler(int signum)
{
	(void)signum;
	g_status = 130;
	write(1, "\n", 1);
}

bool	set_signal(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	sigemptyset(&sigint.sa_mask);
	sigemptyset(&sigquit.sa_mask);
	sigint.sa_handler = &sigint_handler;
	sigquit.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
	return (true);
}

bool	set_termios(struct termios *term)
{
	struct termios	myterm;

	g_status = 0;
	if (tcgetattr(STDIN_FILENO, term) == -1)
		return (perror("Error tcgetattr\n"), false);
	if (tcgetattr(STDIN_FILENO, &myterm) == -1)
		return (perror("Error tcgetattr\n"), false);
	myterm.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &myterm) == -1)
		return (perror("Error tcsetattr\n"), false);
	return (true);
}

bool	restore_termios(struct termios *term)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, term) == -1)
		return (perror("Error tcsetattr\n"), false);
	return (true);
}
