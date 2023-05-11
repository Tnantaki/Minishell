### Executable ###
NAME	= minishell

### Directory ###
LIBFT_DIR	= libft/
GNL_DIR		= get_next_line/
MANDA_DIR	= mandatory/
BONUS_DIR	=

### Compilation ###
CC			= gcc
RM			= rm -f
MAN_HEAD	= -Iincludes
# CFLAGS		= -Wall -Wextra -Werror

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
MANDA_SRCS	= minishell.c split_ws.c split_ro.c\
				lexer.c utils_have.c utils_is.c

SRCS	=	$(addprefix $(MANDA_DIR), $(MANDA_SRCS))

### Object Files ###
OBJS	=	$(SRCS:.c=.o)

### Compilation Rule ###
%.o:%.c
	$(CC) $(CFLAGS) $(MAN_HEAD) $(FT_HEAD) $(RL_HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(RL_FLAGS) $(OBJS) -o $(NAME)
#Don't Forget to delete
	$(RM) $(OBJS)

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

