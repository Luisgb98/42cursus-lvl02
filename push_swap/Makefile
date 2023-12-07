# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 17:29:13 by lguisado          #+#    #+#              #
#    Updated: 2023/03/13 16:13:39 by lguisado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc
CFLAGS	= -Werror -Wall -Wextra
RM		= rm -f
SRC		= src
OBJ		= obj
SRCS	= $(wildcard $(SRC)/*.c)
OBJS	= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

LIBFT	= libft/libft.a

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_END=\033[0m

all		:	$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(COLOUR_GREEN)Compiling$(COLOUR_END)"

$(OBJ)/%.o: $(SRC)/%.c obj
	@$(CC) $(CFLAGS) -c $< -o $@

obj:
	@mkdir obj

$(LIBFT):
	@make -C libft

clean	:
		@${RM} ${OBJS}
		@make clean -C libft
		@echo "$(COLOUR_RED)Deleting all .o Files$(COLOUR_END)"
		
fclean	:	clean
		@rm -rf obj
		@make fclean -C libft
		@${RM} push_swap
		@echo "$(COLOUR_RED)Deleting .a File$(COLOUR_END)"

re:	fclean all

.PHONY: all clean fclean re bonus