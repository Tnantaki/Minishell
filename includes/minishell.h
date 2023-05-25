#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
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

typedef struct s_executable_command
{
	char	*cmd;
	char	**arg;
	char	**env;
	t_io	*in;
	t_io	*out;
	int		fd_in;
	int		fd_out;
}	t_excmd;

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

typedef struct s_minishell
{
	char	**tokens;
	char	**env;
	char	*line;
	t_type	*tk_type;
	int		nb_tk;
	int		nb_cmd;
	t_spcmd	*spcmd;
}	t_msh;

//Part 1 : Lexer
// bool	lexer(char *line, t_msh *msh);
bool	valid_syntax(char *line);
bool	tokenization(char *line, t_msh *msh);
bool	valid_tokens(char **tokens);
//Part 2 : Paser
bool	expander(char **tokens);
bool	classify_token(t_msh *msh);
bool	parser(t_msh *msh);
bool	allocate_spcmd(t_msh *msh, int	nb_cmd);
bool	allocate_sub_spcmd(t_spcmd *spcmd, int nb_cmd, t_type *type, int nb_tk);
//Part 3 : Executor
bool	executor(t_msh *msh);
//Part 4 : Built-in

//### Environment ###//
char	**set_env(char **env);
char	**get_env(void);


//Debug
int		debug_tokens(char **str, char *title);
int		debug_type(t_type *type, int ct, char *title);
int		debug_spcmd(t_spcmd *spcmd, int nb_cmd);

#endif