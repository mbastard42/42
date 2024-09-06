BDIR	:=	bin/
NAME	:=	$(BDIR)libasm.a

SDIR	:=	src/
FILE	:=	.s
ODIR	:=	.obj/
COMP	:=	.o

CC		:=	nasm
CFLG	:=	-felf64
LK		:=	ar
LFLG	:=	rcs

SRCS	:=	$(shell find $(SDIR) -name "*$(FILE)")
OBJS	:=	$(subst $(SDIR),$(ODIR), ${SRCS:$(FILE)=$(COMP)})

$(ODIR)%$(COMP) : $(SDIR)%$(FILE)
	@mkdir -p $(subst $(SDIR),$(ODIR), $(shell dirname $<)/)
	$(CC) $(CFLG) $< -o $@

${NAME} : $(OBJS)
	@mkdir -p $(BDIR)
	$(LK) $(LFLG) $(NAME) $(OBJS) 

build : ${NAME}

clean :	
	rm -rf $(ODIR)

fclean : clean
	rm -rf $(BDIR)

re : fclean build

all : build clean

docker :
	docker build -t libasm . && docker run -it -v ./:/data libasm

test : build
	clang test/main.c -L$(BDIR) -l$(subst $(BDIR)lib,,$(subst .a,,$(NAME))) -o $(BDIR)test.out

.PHONY : build clean fclean re all docker test
