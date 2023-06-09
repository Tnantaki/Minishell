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
# define HEREDOC ".here_doc"

extern int g_status;

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

typedef enum e_built_in // intager: order from 0 onward
{
	e_non,
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
	int		pipefd[2];
	int		*pid;
	int		infd;
	int		outfd;
	int		i;
	int		stdin;
	int		stdout;
	t_buin	buin;
}	t_pipe;

typedef struct s_buin_cmd
{
	char	*cur_dir;
	char	*old_dir;
	char	*tmp;
}	t_buin_cmd;

typedef struct s_minishell
{
	char	**tokens;
	char	**env;
	t_type	*tk_type;
	t_spcmd	*spcmd;
	int		nb_tk;
	int		nb_cmd;
	int		nb_pipe;
}	t_msh;

//Simple Command
// typedef struct s_spcmd
// {
// 	char	*cmd;// Command
// 	char	**arg;// flag or argumeng
// 	char	**in_file;
// 	char	**out_file;
// 	int		rdrt; // redirections
// 	// int				bg;// background
// 	int		pipe;// pipe
// }	t_spcmd;

//Signal
bool	set_signal(void);
bool	set_termios(struct termios *term);
bool	restore_termios(struct termios *term);
//Debuger
int		debug_tokens(char **str, char *title);
int		debug_type(t_type *type, int nb_tk, char *title);
int		debug_spcmd(t_spcmd *spcmd, int nb_cmd);
//Part 1 : Lexer
bool	valid_syntax(char *line);
bool	tokenization(char *line, t_msh *msh);
bool	classify_token(t_msh *msh);
bool	valid_tokens(char **token, int nb_tk, t_type *type);
//Part 2 : Paser
bool	expander(char **tokens);
bool	allocate_spcmd(t_msh *msh, int	nb_cmd);
bool	allocate_sub_spcmd(t_spcmd *spcmd, int nb_cmd, t_type *type, int nb_tk);
bool	parser(t_msh *msh);
//Part 3 : Executor
bool	executor(t_spcmd *spcmd, int nb_cmd);
bool	redirection(t_io *io, int nb_io, t_pipe *px);
bool	cmd_execution(char **arg, t_pipe *px);
bool	save_stdio(t_pipe *px);
bool	restore_stdio(t_pipe *px);
bool	close_stdio(t_pipe *px);
//Part 4 : Built-in
bool	is_built_in(char *cmd, t_buin *buin);
bool	buin_execution(t_buin built, char **arg);
int		ft_cd(char **arg);
int 	ft_echo(char **arg);
int 	ft_pwd(void);
int		ft_export(void);
// 4.5 : Built-in (utils)
char	*ft_substr(char *s, unsigned int start, size_t len);

//### Environment ###//
char	**set_env(char **env);
char	**get_env(void);

#endif