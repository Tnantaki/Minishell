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
C_FLAGS		= -Wall -Wextra -Werror
MAN_HEAD	= -Iincludes

### Libft Flags ###
FT_FLAGS	= -Llibft -lft
FT_HEAD		= -Ilibft

### GNL Flags ###
GNL_FLAGS	= -Lget_next_line -lgnl
GNL_HEAD	= -Iget_next_line

### Source Files ###
MANDA_SRCS	= minishell.c

SRCS	=	$(addprefix $(MANDA_DIR), $(MANDA_SRCS))

### Object Files ###
OBJS	=	$(SRCS:.c=.o)

### Rule ###
# %.o:%.c
# 	$(CC) $(C_FLAGS) $(MAN_HEAD) $(FT_HEAD) $(GNL_HEAD) -c $< -o $@

#For Testing //don't forget to remove
%.o:%.c
	$(CC) $(FLAGS) $(MAN_HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
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

.PHONY: all clean fclean re
