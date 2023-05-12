#ifndef MINISHELL_H
# define MINISHELL_H

// # include "libft.h"

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
// # include <readline/history.h>
# include <readline/readline.h>
// # include <readline.h>

//Checker : May be delete after finish
int		checker_2d_arr(char **str, char *title);
//Part 1 : Lexer
char	**lexer(char *line);
//split white-space
char	**split_ws(char *line);
//Part 2 : Paser
//Part 3 : Executor
//Part 4 : Built-in

//### UTILS ###//
//free
char	**free2d_str(char **ptr);
char	**free2d_nstr(char **ptr, int i);
//have lexer
int		have_quote(char *line);
int		have_optr(char *line);
int		have_cmd(char *line);
//is lexer
bool	ft_isspace(int c);
bool	ft_isquote(int c);
bool	ft_isoptr(int c);
bool	ft_iscmd(int c);
//is paser
bool	ft_isalpha(int c);
bool	ft_isdigit(int c);
bool	ft_isvar(int c);

#endif