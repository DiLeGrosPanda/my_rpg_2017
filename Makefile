##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/collisions_player.c	\
		src/update_on_event.c	\
		src/reset_spells.c	\
		src/collisions.c	\
		src/get_next_line.c	\
		src/events.c	\
		src/dialogues.c	\
		src/lost.c	\
		src/init_maps.c	\
		src/buttons.c	\
		src/quest.c	\
		src/player.c	\
		src/dialogues_content.c	\
		src/spells.c	\
		src/get_keybinding.c	\
		src/fn_collisions_check.c	\
		src/init_player.c	\
		src/display_player_infos.c	\
		src/collisions_fireballs.c	\
		src/draw_gui.c	\
		src/create_npc.c	\
		src/get_ennemy_direction.c	\
		src/fireballs.c	\
		src/vertex_array.c	\
		src/callbacks.c	\
		src/struct.c	\
		src/draw.c	\
		src/lib.c	\
		src/ath.c	\
		src/menu.c	\
		src/intro.c	\
		src/main.c	\
		src/change_settings.c	\
		src/move_ennemy.c	\
		src/lightning.c	\
		src/add_particules.c	\
		src/update_particules.c	\
		src/draw_particules.c	\
		src/lightning_particules.c	\
		src/npc.c	\
		src/vertex_array2.c	\
		src/draw_spells.c	\
		src/new_wave.c	\
		src/resize.c	\
		src/llist_monsters.c	\
		src/display_inventory.c	\
		src/inventory.c	\
		src/llist_fireball.c	\
		src/llist_fireball2.c	\
		src/my_pause.c	\
		src/skills_tree.c	\
		src/llist_objects.c	\
		src/check_quests_done.c	\
		src/load_map.c	\
		src/init_maps2.c	\
		src/clean_ressources.c	\
		src/move_ennemy_tools.c	\
		src/dialogues2.c	\
		src/tools.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	+=	-Wall -Wextra -I include -O

LDFLAGS	=	-L library/ -l mygraph -l my -l c_graph_prog -l m

all:	my	maps	graph	$(NAME)

YELLOW          =       \033[0;103m
RED             =       \033[0;31m
GREEN           =       \033[0;32m
NC              =       \033[0m
GREY            =       \033[90m
BLUE            =       \033[0;94m
PURPLE          =       \033[0;95m
BG_COLOR        =       \033[46m####\033[m
IRED            =       \033[0;91m

$(NAME):	$(OBJ)
	@echo -e '${NC}${BG_COLOR}Libs: $(LDFLAGS)${NC}'
	@echo -e '${BG_COLOR}Flags: $(CFLAGS)${NC}'
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) 2>>errors_build.txt\
		&& echo -e '${BLUE}Create${NC}: ${YELLOW}${GREY}./$(NAME)${NC}'\
		|| echo -e '${RED}[ FAILED ]${NC}: __Create__${GREY} ./$(NAME)${NC}'
	$(if $(wildcard maps/map_background.csv), @mv maps/map_background.csv maps/map_bg)
	$(if $(wildcard maps/map_object.csv), @mv maps/map_object.csv maps/map_objects)

need:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_T)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@echo -e '${BLUE}Clean${NC} : OK'

graph:
	@make --no-print-directory -C library/mygraph
my:
	@make --no-print-directory -C library/my

%.o:            %.c
	@-$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS) 2>>errors_build.txt\
		&& echo -e '${GREEN} [ OK ]${NC} Build $<'\
		|| echo -e '${RED}[ FAILED ]${NC} __Build__ $<'\
		&& echo -ne '${PURPLE}' && grep  $< errors_build.txt |\
		grep warning |cut -d':' -f2- |cut -d'[' -f-1\
		&& echo -ne '${IRED}' && grep  $< errors_build.txt |\
		grep error |cut -d':' -f2-\
		||:
	@echo -ne '${NC}'

clean:
	@make -C library/my clean
	@make -C library/mygraph clean
	@find . -name "*~" -delete -o -name "#*#" -delete
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_T)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@echo -e '${BLUE}Clean${NC} : OK'


fclean:         clean
	@rm -rf $(NAME)
	@rm -rf errors_build.txt
	@make -C library/my fclean
	@make -C library/mygraph fclean
	@echo -e '${BLUE}Fclean${NC}: ./$(NAME) removed'

re:	fclean	all

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

#A phony target should not be a prerequisite of a real target file;
#if it is, its recipe will be run every time make goes to update that file.
.PHONY:	all	$(NAME)	my	graph	clean	fclean	re
