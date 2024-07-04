NAME			:=	RPN
MAKEFLAGS		+=	--silent

SDIR			:=	src/
SRC				:=	$(shell find src -name "*.cpp")

ODIR			:=	obj/
OBJ				:=	$(subst $(SDIR),$(ODIR), ${SRC:.cpp=.o})

CC				:=	c++
CFLG			:=	-Wall -Wextra -Werror
LFLG			:=	-std=c++98

$(ODIR)%.o		: $(SDIR)%.cpp
				mkdir -p $(subst $(SDIR),$(ODIR), $(shell dirname $<)/)
				$(CC) $(CFLG) -c $< -o ${addprefix $(ODIR), ${<:$(SDIR)%.cpp=%.o}}

${NAME}			: $(OBJ)
				$(CC) $(LFLG) $(OBJ) -o $(NAME)

all				: $(NAME)

clean			:
				rm -rf $(ODIR)

fclean			: clean
				rm -rf $(NAME)

re				: fclean all

.PHONY			: all clean fclean re
