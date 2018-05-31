/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file
*/

#include "my.h"

void draw_part_buffer(partbuffer *this, sfRenderWindow *window)
{
	sfRenderWindow_drawPrimitives(window, this->vertex, this->size * 4,
	sfQuads, NULL);
}

void draw_part_buffer_lightning(partbuffer *this, sfRenderWindow *window)
{
	static sfRenderStates state;
	static sfTexture *texture = NULL;

	if (texture == NULL) {
		texture = sfTexture_createFromFile("sprites/"
		"lightning_player.png", NULL);
		state.shader = NULL;
		state.blendMode = sfBlendAlpha;
		state.transform = sfTransform_Identity;
		state.texture = texture;
	}
	sfRenderWindow_drawPrimitives(window, this->vertex, this->size * 4,
	sfQuads, &state);
}
