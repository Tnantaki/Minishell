# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 11:35:05 by tnantaki          #+#    #+#              #
#    Updated: 2023/02/10 16:35:07 by tnantaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

FLAGS	= -Wall -Werror -Wextra

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_memcpy.c ft_strlen.c\
		ft_strchr.c ft_strncmp.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c\
		ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%o:%c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus