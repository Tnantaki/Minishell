### Executable ###
NAME	= minishell

### Directory ###
LIBFT_DIR	= libft/
GNL_DIR		= get_next_line/
MANDA_DIR	= mandatory/
LEXER_DIR	= lexer/
PARSER_DIR	= parser/
EXCUTE_DIR	= executor/
BUILT_DIR	= built_in/
UTILS_DIR	= utils/
ENV_DIR		= environment/
BONUS_DIR	=

### Compilation ###
CC			= gcc
RM			= rm -f
MAN_HEAD	= -Iincludes
CFLAGS		= -Wall -Wextra -Werror

### Libft Flags ###
FT_HEAD		= -Ilibft
FT_FLAGS	= -Llibft -lft

### Readline Flags ###
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	RL_HEAD 	= 
	RL_FLAGS	= -lreadline
else
	RL_HEAD 	= -I/usr/local/Cellar/readline/8.2.1/include
	RL_FLAGS	= -L/usr/local/Cellar/readline/8.2.1/lib -lreadline
endif

### Source Files ###
LEXER_SRCS	= ft_tokenization.c valid_syntax.c

PARSER_SRCS	= expander.c parser.c classify_token.c allocate_spcmd.c\
				valid_tokens.c

EXCUTE_SRCS	= executor.c manage_files.c pipe_utils.c

BUILT_SRCS	= 

UTILS_SRCS	= ft_free.c ft_exit.c ft_is_char.c ft_is_deli_char.c\
				ft_is_special_char.c ft_is_type_str.c ft_itoa.c\
				ft_string.c len_lexer.c ft_strjoin.c ft_strjoinfree.c\
				ft_split.c

ENV_SRCS	= env.c

MANDA_SRCS	= main.c checker.c\
				$(addprefix $(UTILS_DIR), $(UTILS_SRCS))\
				$(addprefix $(ENV_DIR), $(ENV_SRCS))\
				$(addprefix $(LEXER_DIR), $(LEXER_SRCS))\
				$(addprefix $(PARSER_DIR), $(PARSER_SRCS))\
				$(addprefix $(EXCUTE_DIR), $(EXCUTE_SRCS))
#				$(addprefix $(BUILT_DIR), $(BUILT_SRCS))

SRCS	=	$(addprefix $(MANDA_DIR), $(MANDA_SRCS))

### Object Files ###
OBJS	=	$(SRCS:.c=.o)

### Compilation Rule ###
%.o:%.c
	$(CC) $(CFLAGS) $(MAN_HEAD) $(RL_HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(RL_FLAGS) -o $(NAME)
#Don't Forget to delete
#$(RM) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
#For Testing //don't forget to remove

#######################################################################
# all: $(NAME)

# $(NAME): $(OBJS)
# 	@make -C $(LIBFT_DIR)
# 	@make -C $(GNL_DIR)
# 	$(CC) $(C_FLAGS) $(OBJS) $(FT_FLAGS) $(GNL_FLAGS) -o $(NAME)

# clean:
# 	@make fclean -C $(LIBFT_DIR)
# 	@make fclean -C $(GNL_DIR)
# 	$(RM) $(OBJS)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean all
### GNL Flags ###
# GNL_FLAGS	= -Lget_next_line -lgnl
# GNL_HEAD	= -Iget_next_line

