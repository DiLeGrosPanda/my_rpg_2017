/*
** EPITECH PROJECT, 2017
** display_res
** File description:
** CSFML function to display resources at a given pos on a given window
*/

#include "mygraph.h"

void display_text(sfRenderWindow *window, sfVector2f pos, char *str,
sfColor color)
{
	sfText *text = sfText_create();
	sfFont *font = sfFont_createFromFile("sprites/arial.ttf");

	sfText_setString(text, str);
	sfText_setColor(text, color);
	sfText_setPosition(text, pos);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 32);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
	sfFont_destroy(font);
}

void display_res(sfRenderWindow *window, sfVector2f pos, sfTexture *texture,
sfColor color)
{
	sfSprite *sprite = sfSprite_create();

	sfSprite_setPosition(sprite, pos);
	sfSprite_setColor(sprite, color);
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfSprite_destroy(sprite);
}

void display_sprite(sfRenderWindow *window, sfVector2f pos, sfSprite *sprite)
{
	sfSprite_setPosition(sprite, pos);
	sfRenderWindow_drawSprite(window, sprite, NULL);
}
