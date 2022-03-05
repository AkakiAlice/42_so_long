# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 21:26:57 by alida-si          #+#    #+#              #
#    Updated: 2022/03/05 20:09:28 by alida-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		so_long

LIBFT_DIR =	./libft
LIBFT =		./libft/libft.a

SRC_DIR =	./src
OBJ_DIR =	./obj

SRC_FILES =	so_long.c \
			error_msg.c \
			check_map.c \
			check_mp_utils_I.c \
			check_mp_utils_II.c \
			create_matrix.c \
			init_game.c \
			key_events.c \
			init_values.c \
			close.c \
			load_map.c \

SRC =		$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ =		$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC =		gcc
CCFLAGS =	-Wall -Wextra -Werror
MLXFLAGS =	-lmlx -lXext -lX11
LIBFLAGS =	-L./libft -lft

RM =		rm -f
RM_DIR =	rm -rf

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
			$(CC) $(CCFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS) $(LIBFLAGS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				mkdir -p $(OBJ_DIR)
				$(CC) $(CCFLAGS) -c $< -o $@

$(LIBFT):
			make -C ./libft

clean:
			make clean -C $(LIBFT_DIR)
			$(RM_DIR) $(OBJ_DIR)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)

re:			fclean all