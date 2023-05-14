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
	int				rdrt; // redirections
	int				bg;// background
	int				pipe;// pipe
	struct s_spcmd	*next;
}	t_spcmd;

typedef struct s_minishell
{
	char	**tokens;
	char	**env;
	t_spcmd	spcmd;
}	t_msh;

//Part 1 : Lexer
bool	lexer(char *line, t_msh *msh);
bool	valid_syntax(char *line);
bool	tokenization(char *line, char ***tokens);
bool	valid_tokens(char **tokens);
//Part 2 : Paser
int		parser(char **tokens);
char	**expander(char **tokens);
//Part 3 : Executor
//Part 4 : Built-in

//### Environment ###//
char	**set_env(char **env);
char	**get_env(void);


//Debug
int		checker_2d_arr(char **str, char *title);

#endif