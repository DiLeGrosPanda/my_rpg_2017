/*
** EPITECH PROJECT, 2017
** resize_event
** File description:
** Functions to manage the resize of the CSFML window
*/

#include "mygraph.h"

sfVector2u manage_resize(sfRenderWindow *window, sfEvent event)
{
	sfVector2u size;

	size.x = event.size.width;
	size.y = event.size.height;
	if (size.x < 800)
		size.x = 800;
	else if (size.x > 1920)
		size.x = 1920;
	if (size.y < 600)
		size.y = 600;
	else if (size.y > 1080)
		size.y = 1080;
	sfRenderWindow_setSize(window, size);
	return (size);
}
