/*
** EPITECH PROJECT, 2017
** new_sf_vectors
** File description:
** CSFML usefull fonction to create new vectors
*/

#include "mygraph.h"

sf_vector2u_t new_vector2u(int x, int y)
{
	sfVector2u res;

	res.x = x;
	res.y = y;
	return (res);
}

sf_vector2f_t new_vector2f(float x, float y)
{
	sfVector2f res;

	res.x = x;
	res.y = y;
	return (res);
}

sfIntRect new_int_rect(int left, int top, int width, int height)
{
	sfIntRect rect = {left, top, width, height};

	return (rect);
}
