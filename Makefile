# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaude <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 16:19:29 by mnaude            #+#    #+#              #
#    Updated: 2020/02/01 13:15:02 by mnaude           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_check.c \
				ft_ctoa.c \
				ft_cut.c \
				ft_dup_flags.c \
				ft_each_type.c \
				ft_each_type2.c \
				ft_fill_struct.c \
				ft_get.c \
				ft_itoa.c \
				ft_print.c \
				ft_printf.c \
				ft_ptoa.c \
				ft_type.c \
				ft_utoa.c \
				ft_xtoa.c \
				utils.c

AR				= ar rc

CFLAGS			= -Wall -Wextra -Werror

OBJS			= $(SRCS:.c=.o)

RM				= rm -rf

all :
				@make $(NAME)

$(NAME)	:		$(OBJS)
				$(AR) $(NAME) $(OBJS)

clean :
				$(RM) $(OBJS)

fclean :		clean
				$(RM) $(NAME)

re :			fclean all
