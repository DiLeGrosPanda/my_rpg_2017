/*
** EPITECH PROJECT, 2017
** my_world
** File description:
** ...
*/

#pragma once

#include "structs.h"

#define BUTTON_RESIZE_STANDART (sfIntRect) {0, 0, 400, 280}
#define BUTTON_RESIZE_1_HOVER (sfIntRect) {400, 0, 400, 280}
#define BUTTON_RESIZE_2_HOVER (sfIntRect) {800, 0, 400, 280}
#define BUTTON_RESIZE_1_HIT (sfIntRect) {1200, 0, 400, 280}
#define BUTTON_RESIZE_2_HIT (sfIntRect) {1600, 0, 400, 280}

#define HIT_FIRST_RESIZE_BUTTON mouse.x > 570 && mouse.x < 670\
	&& mouse.y > 140 && mouse.y < 210
#define HIT_SECOND_RESIZE_BUTTON mouse.x > 730 && mouse.x < 830\
	&& mouse.y > 140 && mouse.y < 210

#define MAP_TRUE_COORDS(pos, size) (sfVector2f) {pos.x * size.x / 1280\
	,pos.y * size.y / 960}
#define MAP_PIXEL_COORDS(pos) sfRenderWindow_mapPixelToCoords(window\
	,(sfVector2i) pos, sfRenderWindow_getView(window))
#define CORD_X(pos, size) (float) (pos * size.x / 1280)
#define CORD_Y(pos, size) (float) (pos * size.y / 960)

sfVector2f get_offset(sfRenderWindow *window);
sfVector2f get_spells_pos(sfRenderWindow *window, player_t *player);
sfVector2f get_pos_spells_blank_hud(sfRenderWindow *, player_t *, int);
sfVector2f get_spells_pos(sfRenderWindow *window, player_t *player);
