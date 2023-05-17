# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 11:49:45 by lguisado          #+#    #+#              #
#    Updated: 2023/03/16 18:49:35 by lguisado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CFLAGS		= -Werror -Wall -Wextra
AR			= ar -rcs

SRC			= src
SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c	\
				ft_strdup.c	\
				ft_substr.c	\
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_printf.c \
				ft_prints.c \
				ft_conts.c \
				ft_printhex.c \
				get_next_line.c \
				ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c	
SRC_FILES = ${addprefix ${SRC}/, ${SRCS}}

OBJ		= obj
OBJS	= ${SRCS:.c=.o}
OBJ_FILES = ${addprefix ${OBJ}/, ${OBJS}}

all		:	${NAME}


${NAME}	:	${OBJ_FILES}
		@ ${AR} ${NAME} ${OBJ_FILES}

$(OBJ)/%.o: $(SRC)/%.c obj
	@gcc $(CFLAGS) -c $< -o $@

obj:
	@mkdir obj

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -I includes -o $@ -c $<

re:	fclean all

.PHONY: all clean fclean re
