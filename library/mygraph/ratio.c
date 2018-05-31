/*
** EPITECH PROJECT, 2017
** ratio
** File description:
** Functions to keep a correct ratio on sprite pos according to the win dim
*/

#include "mygraph.h"

double ratio_x(sfRenderWindow *window)
{
	double ratio = 1;

	ratio = ratio / ((float)(32 * 40) /
	(float)sfRenderWindow_getSize(window).x);
	return (ratio);
}

double ratio_y(sfRenderWindow *window)
{
	double ratio = 1;

	ratio = ratio / ((float)(32 * 30) /
	(float)sfRenderWindow_getSize(window).y);
	return (ratio);
}
