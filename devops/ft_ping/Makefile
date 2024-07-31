#	COMPILED LANGUAGES ] ===========================================================================	#
#	                                           [  CONFIG  ] ========================================	#
#	======================================================================================= [  LEAVE	#
#																										#
#	                                     [  NAME AND LOCATION  ] ===================================	#
BDIR	:=	bin/
NAME	:=	$(BDIR)ft_ping
#	                                           [  FORMAT  ] ========================================	#
SDIR	:=	src/
FILE	:=	.c
ODIR	:=	.obj/
COMP	:=	.o
#	                                          [  COMPILER  ] =======================================	#
CC		:=	gcc
CFLG	:=	-c -Wall -Wextra -Werror
LK		:=	gcc
LFLG	:=	-fsanitize=address
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
	$(LK) -o $(NAME) $(LFLG) $(OBJS)
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
	docker build -t ft_ping . && docker run -it -v ./:/data ft_ping
#																										#
bonus	:	build																						#
#																										#
ping	:
	tar -zxvf utils/inetutils-2.0.tar.gz
	cd inetutils-2.0 && ./configure \
		--prefix=/usr				\
		--localstatedir=/var 		\
		--disable-logger     		\
		--disable-whois      		\
		--disable-rcp        		\
		--disable-rexec      		\
		--disable-rlogin     		\
		--disable-rsh        		\
		--disable-servers
	cd inetutils-2.0 && make && make install
	rm -rf inetutils-2.0
#																										#
.PHONY : docker bonus ping
#																										#
#	===================================================================================== [ MAKEFILE	#
