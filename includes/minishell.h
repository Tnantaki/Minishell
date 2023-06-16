/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:30:17 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/13 17:30:19 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <termios.h>
# include "msh_utils.h"

// # define D_PROMPT "\e[0;32m\e[1mmsh: \e[0m"

extern int	g_status;

typedef enum e_type_rdrt
{
	e_input,
	e_heredoc,
	e_output,
	e_append,
}	t_rdrt;

typedef enum e_type_token
{
	e_void,
	e_rdrt,
	e_pipe,
	e_filename,
	e_argument,
}	t_type;

typedef enum e_built_in //intager: order from 0 onward
{
	e_echo,
	e_cd,
	e_pwd,
	e_export,
	e_unset,
	e_env,
	e_exit,
}	t_buin;

typedef struct s_input_output
{
	int		fd;
	t_rdrt	rdrt;
	char	*filename;
}	t_io;

typedef struct s_number_struct
{
	int	arg;
	int	io;
	int	pipe;
}	t_nb;

typedef struct s_spcmd
{
	char	**arg;
	t_io	*io;
	t_nb	nb;
}	t_spcmd;

typedef struct s_pipex
{
	pid_t	*pid;
	int		pipefd[2];
	int		infd;
	int		outfd;
	int		i;
	int		std_in;
	int		std_out;
	int		pipeout;
	t_buin	buin;
}	t_pipe;

typedef struct s_buin_cmd
{
	char	*cur_dir;
	char	*old_dir;
	char	*tmp;
	char	**exp;
	char	**tmp_env;
	char	**env;
	int		index;
}	t_buin_cmd;

typedef struct s_minishell
{
	char	**env;
	char	**tokens;
	t_type	*tk_type;
	t_spcmd	*spcmd;
	int		nb_tk;
	int		nb_cmd;
}	t_msh;

//Signal
void	sigint_handler(int signum);
void	sigint_wait_handler(int signum);
bool	set_signal(void);
bool	set_termios(struct termios *term);
bool	restore_termios(struct termios *term);
//Debuger
int		debug_tokens(char **str);
int		debug_type(t_type *type, int nb_tk);
int		debug_spcmd(t_spcmd *spcmd, int nb_cmd);
//Part 1 : Lexer
bool	valid_syntax(char *line);
bool	tokenization(char *line, t_msh *msh);
bool	classify_token(t_msh *msh);
bool	valid_tokens(char **token, int nb_tk, t_type *type);
//Part 2 : Paser
bool	expander(char **tokens);
bool	allocate_spcmd(t_msh *msh, int nb_cmd);
bool	allocate_sub_spcmd(t_spcmd *spcmd, int nb_cmd, t_type *type, int nb_tk);
void	free_spcmd(t_spcmd *spcmd, int nb_cmd);
bool	parser(t_msh *msh);
//Part 3 : Executor
bool	executor(t_spcmd *spcmd, int nb_cmd);
bool	open_heredoc(t_spcmd *spcmd, int nb_cmd);
bool	redirection(t_io *io, int nb_io, t_pipe *px);
bool	cmd_execution(char **arg, t_pipe *px);
bool	save_stdio(t_pipe *px);
bool	restore_stdio(t_pipe *px);
bool	close_stdio(t_pipe *px);
//Part 4 : Built-in
bool	is_built_in(char *cmd, t_buin *buin);
bool	buin_execution(t_buin built, char **arg);
int		ft_cd(char **arg);
int		ft_echo(char **arg);
int		ft_pwd(void);
int		ft_export(char **arg);
int		ft_unset(char **arg);
int		ft_env(void);
int		ft_exit(char **arg);
// int 	ft_env(char **arg, t_buin_cmd *buin);
int		store_env(t_buin_cmd *buin);
// 4.5 : Built-in (utils)
char	*ft_substr(char *s, unsigned int start, size_t len);

//### Environment ###//
char	**set_env(char **env);
char	**get_env(void);
char	*get_env_value(char *var);

#endif
