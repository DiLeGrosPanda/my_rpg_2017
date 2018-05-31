/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** buttons.h
*/

#include <SFML/Graphics.h>
#include "values.h"

#pragma once

typedef struct blur_text_s {
	sfText *text;
	sfFont *font;
	sfClock *clock;
	float times[4];
} blur_text_t;

typedef struct buttons_s {
	sfRectangleShape *rect;
	int(*callback)();
	sfTexture *texture;
	int state;
	int id;
} button_t;

typedef struct textures_s {
	sfTexture *buttons;
	sfTexture *village;
	sfTexture *village_burning;
	sfTexture *fire;
	sfTexture *orc;
	sfTexture *villager;
} textures_t;

button_t *new_button(sfVector2f, sfVector2f, sfTexture *, int(*)());
button_t **new_buttons(sfVector2f *, sfVector2f *, sfTexture **, int(**)());
int button_is_clicked(button_t *, sfVector2f , sfRenderWindow *);
button_t **cat_buttons(button_t **buttons1, button_t **buttons2);
int get_id(int id);
void destroy_blur_text(blur_text_t *text);
blur_text_t **get_intro_texts(void);
blur_text_t *new_blur_text(sfVector2f, const char *const, float[4], sfColor);
void check_keybinding_button_clicked(int *,
char keys[SPELL_NBR], sfRenderWindow *);
void switch_state_button_resize(sfRenderWindow *window, sfSprite *sprite,
		int *selected_button);
void display_keys(sfRenderWindow *window, char key_binding[SPELL_NBR]);
void check_resize_buttons_clicked(sfRenderWindow *window,
		int *selected_button, sfSprite *sprite);
