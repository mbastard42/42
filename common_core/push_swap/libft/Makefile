# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 16:17:12 by mbastard          #+#    #+#              #
#    Updated: 2022/04/11 15:39:02 by mbastard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			:=	src/
OBJ_DIR			:=	obj/
BIN_DIR			:=	bin/

SRC				:=	ft_char_class.c		ft_convert.c			\
					ft_getlen.c			ft_gnl.c			ft_memory.c		\
					ft_put_fd.c			ft_str_new.c		ft_str_read.c	\
					ft_str_write.c
SRC_PATH		:=	$(addprefix $(SRC_DIR), $(SRC))

OBJ				:=	${SRC_PATH:.c=.o}
OBJ_PATH		:=	$(subst $(SRC_DIR),$(OBJ_DIR), $(OBJ))

NAME			:=	libft.a
NAME_PATH		:=	$(addprefix $(BIN_DIR), $(NAME))

CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror

$(OBJ_DIR)%.o	: $(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o ${addprefix $(OBJ_DIR), ${<:$(SRC_DIR)%.c=%.o}}

${NAME_PATH}	: ${OBJ_PATH}
				@mkdir -p $(BIN_DIR)
				@ar rc $(NAME_PATH) $(OBJ_PATH)
				@ranlib $(NAME_PATH)

all				: $(NAME_PATH)

clean			:
				@rm -rf $(OBJ_DIR)

fclean			: clean
				@rm -rf $(BIN_DIR)

re				: fclean all

.PHONY			: all clean fclean re
