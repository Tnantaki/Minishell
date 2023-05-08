#ifndef MINISHELL_H
# define MINISHELL_H

// # include "libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
// # include <readline/readline.h> // for readline_library

//Part 1 : Lexer
//split white-space
char	**split_ws(char *line);
//is utils
int	ft_isspace(int c);
int	ft_isquote(int c);
//Part 2 : Paser
//Part 3 : Executor
//Part 4 : Built-in

#endif