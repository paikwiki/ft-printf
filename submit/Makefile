# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/18 10:03:37 by cbaek             #+#    #+#              #
#    Updated: 2020/08/21 13:35:09 by cbaek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFTA		= libft.a

SRCS		= ./ft_printf.c \
				./put_c_type.c \
				./put_di_type.c \
				./put_p_type.c \
				./put_percent_type.c \
				./put_s_type.c \
				./put_u_type.c \
				./put_xx_type.c \
				./ft_utils.c

OBJS		= $(SRCS:.c=.o)
INCS		= .
LIBC		= ar rc
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFTA) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY: all clean fclean re .c.o
