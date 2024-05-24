# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dukim <dukim@student.42gyeonsan.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 17:54:40 by dukim             #+#    #+#              #
#    Updated: 2024/05/23 15:50:43 by dukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
LIBFT		= ../libft
LIBFT_LIB	= libft.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRC		= 	ft_printf.c format.c buffer_utils.c spec_char.c spec_str.c spec_nbr.c spec_hex.c spec_addr.c
OBJS	=	$(SRC:.c=.o)

.PHONY:		all clean fclean re bonus

all		:	$(NAME)

bonus:
	@make all

$(NAME) : $(OBJS)
	@make all -C $(LIBFT)/
	@cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rc $(NAME) $(OBJS)

$(OBJS)	:	$(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	@rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean:		clean
	@rm -f $(NAME) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

re:			fclean all
