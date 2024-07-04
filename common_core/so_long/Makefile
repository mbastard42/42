# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 16:17:12 by mbastard          #+#    #+#              #
#    Updated: 2022/04/26 13:52:10 by mbastard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			:=	src/
OBJ_DIR			:=	obj/
LIB_DIR			:=	libft/
BIN_DIR			:=	bin/

LIB_SRC			:=	bin/libft.a
LIB_PATH		:=	$(addprefix $(LIB_DIR), $(LIB_SRC))

SRC				:=	destroy_data.c	display.c		init_data.c		main.c	\
					move.c			parsing.c		utils.c
SRC_PATH		:=	$(addprefix $(SRC_DIR), $(SRC))

OBJ				:=	${SRC_PATH:.c=.o}
OBJ_PATH		:=	$(subst $(SRC_DIR),$(OBJ_DIR), $(OBJ))

NAME			:=	so_long
NAME_PATH		:=	$(addprefix $(BIN_DIR), $(NAME))

CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror
LFLAGS			:=	-lmlx -framework OpenGL -framework AppKit

$(OBJ_DIR)%.o	: $(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o ${addprefix $(OBJ_DIR), ${<:$(SRC_DIR)%.c=%.o}}

${NAME_PATH}	: ${OBJ_PATH}
				@cd $(LIB_DIR) && make
				@mkdir -p $(BIN_DIR)
				@$(CC) $(CFLAGS) $(LFLAGS) ${LIB_PATH} $(OBJ_PATH) -o $(NAME_PATH)

all				: $(NAME_PATH)

clean			:
				@cd $(LIB_DIR) && make clean
				@rm -rf $(OBJ_DIR)

fclean			: clean
				@cd $(LIB_DIR) && make fclean
				@rm -rf $(BIN_DIR)

re				: fclean all

.PHONY			: all clean fclean re
