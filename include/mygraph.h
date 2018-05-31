/*
** EPITECH PROJECT, 2017
** mygraph.h
** File description:
** Header file of the mygraph CSFML library
*/

#ifndef MYGRAPH_H_
#define MYGRAPH_H_

#include <SFML/Graphics.h>

typedef sfVector2u sf_vector2u_t;
typedef sfVector2f sf_vector2f_t;

sf_vector2u_t new_vector2u(int x, int y);
sf_vector2f_t new_vector2f(float x, float y);
void display_res(sfRenderWindow *, sfVector2f pos, sfTexture *, sfColor color);
void display_sprite(sfRenderWindow *window, sfVector2f pos, sfSprite *sprite);
void display_render(sfRenderTexture *rt, sfRenderWindow *window, int is_game);
void display_text(sfRenderWindow *, sfVector2f pos, char *, sfColor color);
double ratio_x(sfRenderWindow *window);
double ratio_y(sfRenderWindow *window);
sfVector2u manage_resize(sfRenderWindow *window, sfEvent event);
sfIntRect new_int_rect(int top, int left, int width, int height);

#endif
