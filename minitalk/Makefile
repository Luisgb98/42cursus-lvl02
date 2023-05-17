# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 17:29:13 by lguisado          #+#    #+#              #
#    Updated: 2022/11/15 17:41:32 by lguisado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Werror -Wall -Wextra
RM		=	rm -f
SRCS	=	server.c client.c
OBJS	=	${SRCS:.c=.o}
LIBFT	=	libft/libft.a

all		:	${LIBFT} server client

.c.o	:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIBFT}	:
		make -C ./libft

server	: ${OBJS}
			${CC} ${CFLAGS} server.o ${LIBFT} -o server

client	: ${OBJS}
			${CC} ${CFLAGS} client.o ${LIBFT} -o client

clean	:
		${RM} ${OBJS}
			make clean -C ./libft
	
fclean	:	clean
		${RM} server client
		${RM} libft/libft.a

re:	fclean server client

.PHONY: all clean fclean re