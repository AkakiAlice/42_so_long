# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 21:26:57 by alida-si          #+#    #+#              #
#    Updated: 2022/03/04 19:29:44 by alida-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	=	so_long.c \
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

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CCFLAGS	= -Wall -Wextra -Werror -g

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CCFLAGS} -o ${NAME} ${OBJS} -lmlx -lXext -lX11 -L./libft -lft

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all