# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 13:04:15 by dukim             #+#    #+#              #
#    Updated: 2024/03/07 14:07:16 by dukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRV_NAME	=	server
CLT_NAME	=	client
LIBFT		=	libft
LIBFT_LIB	=	libft.a

SRV_DIR		= 	srv
CLT_DIR		=	clt

SRV_SRC		= 	$(SRV_DIR)/main.c $(SRV_DIR)/sig_handler.c $(SRV_DIR)/utils.c
CLT_SRC		= 	$(CLT_DIR)/main.c $(CLT_DIR)/send_msg.c

ifdef BONUS
	SRV_SRC_B = $(SRV_SRC:.c=_bonus.c)
	CLT_SRC_B = $(CLT_SRC:.c=_bonus.c)
else
	SRV_SRC_B = $(SRV_SRC)
	CLT_SRC_B = $(CLT_SRC)
endif

SRV_OBJS	=	$(SRV_SRC_B:.c=.o)
CLT_OBJS	=	$(CLT_SRC_B:.c=.o)

.PHONY:		all bonus clean fclean re

all		:	$(LIBFT_LIB) $(SRV_NAME) $(CLT_NAME)

$(LIBFT_LIB)	:
	@make all -C $(LIBFT)/

$(SRV_NAME)	:	$(SRV_OBJS)
	$(CC) $(CFLAGS) $(SRV_OBJS) $(LIBFT)/$(LIBFT_LIB) -o $(SRV_NAME)

$(SRV_OBJS)	:	$(SRV_SRC_B)
	$(CC) $(CFLAGS) -c $(SRV_SRC_B)
	@mv *.o $(SRV_DIR)/

$(CLT_NAME)	:	$(CLT_OBJS)
	$(CC) $(CFLAGS) $(CLT_OBJS) $(LIBFT)/$(LIBFT_LIB) -o $(CLT_NAME)

$(CLT_OBJS)	:	$(CLT_SRC_B)
	$(CC) $(CFLAGS) -c $(CLT_SRC_B)
	@mv *.o $(CLT_DIR)/

bonus:
	@make BONUS=1 all

clean:
	@rm -f $(SRV_DIR)/*.o $(CLT_DIR)/*.o
	make clean -C $(LIBFT)

fclean:		clean
	@rm -f $(SRV_NAME) $(CLT_NAME)
	make fclean -C $(LIBFT)

re:			fclean all
