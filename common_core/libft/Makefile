# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbastard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 16:17:12 by mbastard          #+#    #+#              #
#    Updated: 2021/11/29 16:17:14 by mbastard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_SRCS	=	ft_atoi.c			ft_bzero.c			ft_calloc.c			ft_isalnum.c		ft_isalpha.c		\
					ft_isascii.c		ft_isdigit.c		ft_isprint.c		ft_itoa.c			ft_memchr.c			\
					ft_memcmp.c			ft_memcpy.c			ft_memmove.c		ft_memset.c			ft_putchar_fd.c		\
					ft_putendl_fd.c		ft_putnbr_fd.c		ft_putstr_fd.c		ft_split.c			ft_strchr.c			\
					ft_strdup.c			ft_striteri.c		ft_strjoin.c		ft_strlcat.c		ft_strlcpy.c		\
					ft_strlen.c			ft_strmapi.c		ft_strncmp.c		ft_strnstr.c		ft_strrchr.c		\
					ft_strtrim.c		ft_substr.c			ft_tolower.c		ft_toupper.c

MANDATORY_OBJS	=	${MANDATORY_SRCS:.c=.o}

NAME			=	libft.a

CC				=	cc

FLAGS			=	-Wall -Wextra -Werror

.c.o			:
				@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}			:	${MANDATORY_OBJS}
				@ar rc libft.a ${MANDATORY_OBJS}
				@ranlib libft.a

mandatory		:	${MANDATORY_OBJS}
				@ar rc libft.a ${MANDATORY_OBJS}
				@ranlib libft.a

clean			:
				@rm -f ${MANDATORY_OBJS}

all				:	${NAME} clean
				
fclean			:	clean
				@rm -f libft.a
				@rm -f libft.h.gch

re				: 	fclean all
				@rm -f ${MANDATORY_OBJS}

.PHONY			: 	mandatory clean all fclean re
