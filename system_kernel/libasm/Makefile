#	COMPILED LANGUAGES ] ===========================================================================	#
#	                                           [  CONFIG  ] ========================================	#
#	======================================================================================= [  LEAVE	#
#																										#
#	                                     [  NAME AND LOCATION  ] ===================================	#
BDIR	:=	bin/
NAME	:=	$(BDIR)libasm.a
#	                                           [  FORMAT  ] ========================================	#
SDIR	:=	src/
FILE	:=	.s
ODIR	:=	.obj/
COMP	:=	.o
#	                                          [  COMPILER  ] =======================================	#
CC		:=	nasm
CFLG	:=	-f elf64
LK		:=	ar
LFLG	:=	rcs
#																										#
#	======================================================================================= [  FILES	#
#																										#
SRCS	:=	$(shell find $(SDIR) -name "*$(FILE)")
OBJS	:=	$(subst $(SDIR),$(ODIR), ${SRCS:$(FILE)=$(COMP)})
#																										#
#	============================================================================== [  MAKEFILE RULES	#
#																										#
$(ODIR)%$(COMP) : $(SDIR)%$(FILE)
	@mkdir -p $(subst $(SDIR),$(ODIR), $(shell dirname $<)/)
	$(CC) $(CFLG) $< -o ${addprefix $(ODIR), ${<:$(SDIR)%$(FILE)=%$(COMP)}}
#																										#
${NAME} : $(OBJS)
	@mkdir -p $(BDIR)
	$(LK) $(NAME) $(OBJS) $(LFLG)
#																										#
#																										#
build : ${NAME}
#																										#
clean :	
	rm -rf $(ODIR)
#																										#
fclean : clean
	rm -rf $(BDIR)
#																										#
re : fclean build
#																										#
all : build clean
#																										#
.PHONY : build clean fclean re all
#																										#
#	                                       [  CUSTOM RULES  ] ======================================	#
#																										#
docker :
	docker build -t libasm . && docker run -it -v ./:/data libasm
#																										#
test : build
	gcc test/main.c -L$(BDIR) -l$(subst $(BDIR)lib,,$(subst .a,,$(NAME))) -o $(BDIR)test.out
#																										#
.PHONY : docker test
#																										#
#	===================================================================================== [ MAKEFILE	#
