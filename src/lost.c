/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file
*/

#include "my.h"

static void manage_lost_event(sfRenderWindow *window, int *is_open)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type == sfEvtKeyPressed && SF_KEY == sfKeyEscape)
			*is_open = 0;
	}
}

void check_lost(sfRenderWindow *window, player_t *player)
{
	sfTexture *texture;
	sfSprite *sprite;
	int is_open = 1;

	if (player->life)
		return;
	texture = sfTexture_createFromFile("sprites/you_lost.jpg", sfFalse);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfFalse);
	sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
	while (sfRenderWindow_isOpen(window) && is_open) {
		manage_lost_event(window, &is_open);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_display(window);
	}
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
}
