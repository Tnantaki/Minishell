#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include "msh_utils.h"

# define HEREDOC ".here_doc"

typedef enum e_type_rdrt
{
	input,
	output,
	heredoc,
	append,
}	t_rdrt;

typedef enum e_type_token
{
	VOID = -1,
	RDRT_IN,
	RDRT_OUT,
	PIPE,
	FILENAME,
	COMMAND,
	ARGUMENT,
}	t_type;

typedef enum e_built_in // intager: order from 0 onward
{
	NON,
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
}	t_buin;

typedef struct s_input_output
{
	t_rdrt	rdrt;
	char	*filename;
}	t_io;

typedef struct s_number_struct
{
	int	arg;
	int	in;
	int	out;
	int	pipe;
}	t_nb;

typedef struct s_spcmd
{
	char	*cmd;
	char	**arg;
	t_io	*in;
	t_io	*out;
	t_nb	nb;
}	t_spcmd;

typedef struct s_pipex
{
	char	**env;
	char	**path;
	int		*pipefd;
	int		*pid;
	int		infd;
	int		outfd;
	int		nb_pipe;
	int		status;
	int		i;
	t_buin	built;
}	t_pipe;

typedef struct s_buin_cmd
{
	char	*old_dir;
	char	*cur_dir;
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

void	set_signal(void);
//Part 1 : Lexer
// bool	lexer(char *line, t_msh *msh);
bool	valid_syntax(char *line);
bool	tokenization(char *line, t_msh *msh);
//Part 2 : Paser
bool	expander(char **tokens);
bool	classify_token(t_msh *msh);
bool	valid_tokens(char **token, int nb_tk, t_type *type);
bool	parser(t_msh *msh);
bool	allocate_spcmd(t_msh *msh, int	nb_cmd);
bool	allocate_sub_spcmd(t_spcmd *spcmd, int nb_cmd, t_type *type, int nb_tk);
//Part 3 : Executor
bool	executor(t_spcmd *spcmd, int nb_cmd, int nb_pipe);
bool	findpath(t_pipe *px);
bool	create_pipe(t_pipe *px, int nb_cmd);
bool	close_pipe(t_pipe *px);
bool	open_infile(t_io *in, int nb_in, int *infd);
bool	open_outfile(t_io *out, int nb_out, int *outfd);
//Part 4 : Built-in
t_buin	is_built_in(char *cmd);
bool	built_exec(t_buin built, char **arg);
int		ft_cd(char **arg);

//### Environment ###//
char	**set_env(char **env);
char	**get_env(void);


//Debug
int		debug_tokens(char **str, char *title);
int		debug_type(t_type *type, int ct, char *title);
int		debug_spcmd(t_spcmd *spcmd, int nb_cmd);

#endif