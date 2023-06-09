### Executable ###
NAME	= minishell

### Directory ###
LIBFT_DIR	= libft/
MANDA_DIR	= mandatory/
LEXER_DIR	= lexer/
PARSER_DIR	= parser/
EXCUTE_DIR	= executor/
BUILT_DIR	= built_in/
UTILS_DIR	= utils/

### Compilation ###
CC			= cc
RM			= rm -f
MAN_HEAD	= -Iincludes
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

### Libft Flags ###
FT_HEAD		= -Ilibft
FT_FLAGS	= -Llibft -lft

### Readline Flags ###
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	RL_HEAD		=
	RL_FLAGS	= -lreadline -lcurses
else
	RL_HEAD		= -I/usr/local/Cellar/readline/8.2.1/include
	RL_FLAGS	= -L/usr/local/Cellar/readline/8.2.1/lib -lreadline -lcurses
endif

### Source Files ###
LEXER_SRCS	= valid_quote.c tokenization.c classify_token.c valid_syntax.c

PARSER_SRCS	= expander.c trim_quote.c allocate_spcmd.c parser.c

EXCUTE_SRCS	= executor.c open_files.c redirection.c cmd_execution.c

BUILT_SRCS	= built_in.c cd.c echo.c pwd.c export.c unset.c env.c exit.c

UTILS_SRCS	= ft_isspace.c ft_isquote.c ft_isspecial.c ft_isoptr.c ft_iscmd.c\
				ft_isvar.c ft_istoken.c ft_2dstrlen.c ft_2dstrdup.c\
				ft_strndup.c ft_strcmp.c ft_strjoinfree.c ft_free2dstr.c\
				ft_free2dnstr.c ft_strinsert.c len_lexer.c ft_prterr.c

MANDA_SRCS	= main.c signal.c environment.c debuger.c\
				$(addprefix $(UTILS_DIR), $(UTILS_SRCS))\
				$(addprefix $(LEXER_DIR), $(LEXER_SRCS))\
				$(addprefix $(PARSER_DIR), $(PARSER_SRCS))\
				$(addprefix $(EXCUTE_DIR), $(EXCUTE_SRCS))\
				$(addprefix $(BUILT_DIR), $(BUILT_SRCS))

SRCS	=	$(addprefix $(MANDA_DIR), $(MANDA_SRCS))

### Object Files ###
OBJS	=	$(SRCS:.c=.o)

### Compilation Rule ###
%.o:%.c
	$(CC) $(CFLAGS) $(MAN_HEAD) $(RL_HEAD) $(FT_HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(RL_FLAGS) $(FT_FLAGS) -o $(NAME)

clean:
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
