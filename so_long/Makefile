# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 17:57:42 by lguisado          #+#    #+#              #
#    Updated: 2023/03/29 14:29:43 by lguisado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
CFLAGS  = -Wall -Wextra -Werror

SRC		= src
SRCS	= main.c \
		  check_path.c \
		  draw.c \
		  check.c \
		  error.c \
		  exit.c \
		  init.c \
		  map.c \
		  move.c \
		  player_move.c
SRC_FILES = ${addprefix ${SRC}/, ${SRCS}}

OBJ		= obj
OBJS	= ${SRCS:.c=.o}
OBJ_FILES = $(addprefix $(OBJ)/, $(OBJS))

LIBFT = libft/libft.a
INC = -I libft

MLX = MLX42/libmlx42.a

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_END=\033[0m

BREW = "/Users/$(USER)/.brew/opt/glfw/lib/"

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ_FILES)
	@gcc $(CFLAGS) $(OBJ_FILES) $(MLX) -lglfw -L $(BREW) $(INC) -o $(NAME) $(LIBFT)
	@echo "$(COLOUR_GREEN)Compiling$(COLOUR_END)"

$(OBJ)/%.o: $(SRC)/%.c obj
	@$(CC) $(CFLAGS) -c $< -o $@

obj:
	@mkdir obj

$(LIBFT):
	@make -C libft

$(MLX):
	@make -C MLX42/
clean:
	@rm -rf $(OBJ)
	@make -C MLX42/ clean
	@make -C libft/ clean
	@echo "$(COLOUR_RED)Deleting all .o Files$(COLOUR_END)"
fclean: clean
	@rm -f $(NAME)
	@make -C MLX42/ fclean
	@make -C libft/ fclean
	@echo "$(COLOUR_RED)Deleting .a File$(COLOUR_END)"

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re mlx42