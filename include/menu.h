/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** menu.h
*/

#include "structs.h"

#pragma once

int get_settings(sfRenderWindow *, int button_clicked,
		char key_binding[SPELL_NBR]);
int menu(sfRenderWindow *, char key_binding[SPELL_NBR], textures_t *, int);
void menu_hoover(sfMouseMoveEvent, button_t **buttons, sfRenderWindow *, int);
void destroy_menu(button_t **buttons, textures_t *);
void my_intro(sfRenderWindow *);
textures_t *get_menu_textures(void);
button_t **get_menu_buttons(textures_t *);
button_t **get_pause_buttons(void);
int my_pause(sfRenderWindow *, sfView const *view2, int);
