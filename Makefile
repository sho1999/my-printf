# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smuramat <smuramat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 10:17:26 by smuramat          #+#    #+#              #
#    Updated: 2022/05/06 20:32:31 by smuramat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  src/ft_printf.c \
		src/ft_cv_HEX.c \
		src/ft_cv_int.c \
		src/ft_cv_pointer.c \
		src/ft_cv_unsigned.c \
		src/ft_put_char.c

SRCS_O = 	ft_cv_HEX.o \
		ft_printf.o \
		ft_cv_int.o \
		ft_cv_pointer.o \
		ft_cv_unsigned.o \
		ft_put_char.o


CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SRCS_O) 
	rm -rf $(OBJS)
	rm -rf $(B_SRCS_O) 
	rm -rf $(B_OBJS)


fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all