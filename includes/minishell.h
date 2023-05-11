#ifndef MINISHELL_H
# define MINISHELL_H

// # include "libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
//# include <readline/history.h>
# include <readline/readline.h>
// # include <readline/readline.h> // for readline_library

//Part 1 : Lexer
char	**lexer(char *line);
//split white-space
char	**split_ws(char *line);
//have utils
int		have_quote(char *line);
int		have_optr(char *line);
int		have_cmd(char *line);
//is utils
bool	ft_isspace(int c);
bool	ft_isquote(int c);
bool	ft_isoptr(int c);
bool	ft_iscmd(int c);
//Part 2 : Paser
//Part 3 : Executor
//Part 4 : Built-in

#endif