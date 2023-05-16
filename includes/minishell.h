#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "msh_utils.h"

// enum reoptr {stdin, stdout, heredoc, append, pipe};

typedef enum e_type_token
{
	VOID,
	REDIRECT,
	PIPE,
	FILENAME,
	COMMAND,
	ARGUMENT,
}	t_type;

typedef struct s_executable_command
{
	char	*cmd;
	char	**arg;
	char	**env;
	int		fd_in;
	int		fd_out;
}	t_excmd;

//Simple Command
typedef struct s_spcmd
{
	int				list[4];
	char			*cmd;// like ls, echo
	char			**arg;// like -la, "hello"
	char			*in_file;
	char			*out_file;
	int				rdrt; // redirections
	int				bg;// background
	int				pipe;// pipe
	struct s_spcmd	*next;
}	t_spcmd;

typedef struct s_minishell
{
	char	**tokens;
	char	**env;
	char	*line;
	int		ct;
	t_spcmd	spcmd;
}	t_msh;

//Part 1 : Lexer
// bool	lexer(char *line, t_msh *msh);
bool	valid_syntax(char *line);
bool	tokenization(char *line, char ***tokens);
bool	valid_tokens(char **tokens);
//Part 2 : Paser
bool	expander(char **tokens);
bool	parser(char **tokens);
t_type	*classify_token(char **tokens, int ct);
// int		parser(char **tokens);
//Part 3 : Executor
//Part 4 : Built-in

//### Environment ###//
char	**set_env(char **env);
char	**get_env(void);


//Debug
int		debug_tokens(char **str, char *title);
int		debug_type(t_type *type, int ct, char *title);

#endif