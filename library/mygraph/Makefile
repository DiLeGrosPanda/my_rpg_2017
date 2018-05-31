##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Task01
##

SRC	=	new_sf_vectors.c	\
		display_res.c	\
		resize_event.c	\
		ratio.c

CFLAGS	=	-Wall -Wextra -I ../../include

LDFLAGS	+=	-l c_graph_prog

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmygraph.a

all:	$(NAME)

YELLOW		=	\033[0;103m
RED             =       \033[0;31m
GREEN           =       \033[0;32m
NC              =       \033[0m
GREY            =       \033[90m
BLUE            =       \033[0;94m
PURPLE          =       \033[0;95m
BG_COLOR        =       \033[46m####\033[m
IRED            =       \033[0;91m

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../
	@cp mygraph.h ../../include/
	@echo -e '${NC}${BG_COLOR}Libs: $(LDFLAGS)${NC}'
	@echo -e '${BG_COLOR}Flags: $(CFLAGS)${NC}'
	@echo -e '${BLUE}Create${NC}: ${YELLOW}${GREY}./$(NAME)${NC}'

%.o:	%.c
	@-$(CC) -o $@ -c $< $(CFLAGS)\
		&& echo -e '${GREEN} [ OK ]${NC} Build $<'\
		|| echo -e '${RED}[ FAILED ]${NC} __Build__ $<'

clean:
	@find . -name "*~" -delete -o -name "#*#" -delete
	@rm -rf $(OBJ)
	@echo -e '${BLUE}Clean${NC} : OK'

fclean:
	@find . -name "*~" -delete -o -name "#*#" -delete
	@rm -rf $(OBJ)
	@rm -rf ./$(NAME)
	@rm -rf ../$(NAME)
	@echo -e '${BLUE}Fclean${NC}: ./$(NAME) removed'

re:	fclean	all

.PHONY:	all	$(NAME)	clean	fclean	re
