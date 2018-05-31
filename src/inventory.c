/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** file to manage the player
*/

#include "my.h"

sfTexture **get_inventory_textures(sfRenderWindow *window, button_t ***buttons)
{
	sfImage *image = sfRenderWindow_capture(window);
	sfTexture **textures = malloc(sizeof(sfTexture *) * 2);
	sfTexture *texture = sfTexture_createFromFile("sprites/arrows.png", 0);
	sfTexture *texts[] = {texture, texture, NULL};
	sfVector2f pos[] = {{50 * 2, 160 * 2}, {50 * 2, 260 * 2}};
	sfVector2f size[] = {{113, 70}, {113, 70}};
	int (*callbacks[])() = {&get_id, &get_id, NULL};
	sfIntRect rect[] = {{0, 0, 113, 70}, {0, 70, 113, 70}};

	*buttons = new_buttons(pos, size, texts, callbacks);
	for (int i = 0; (*buttons)[i] != NULL; i = i + 1)
		sfRectangleShape_setTextureRect((*buttons)[i]->rect, rect[i]);
	textures[0] = sfTexture_createFromFile("sprites/inv.png", NULL);
	textures[1] = sfTexture_createFromImage(image, NULL);
	sfImage_destroy(image);
	return (textures);
}

void inventory_hoover(sfMouseMoveEvent event, player_t *player,
sfRenderWindow *window)
{
	sfSprite *sprite = player->llist_item->sprite;
	item_t *iter = player->llist_item->first;
	sfFloatRect rect = {0};
	sfVector2f pos = {0};

	for (int i = 0; iter && i < 50; iter = iter->next) {
		pos = (sfVector2f) {ratio_x(window) * (158 * 2 + (40.5 * 2) *
			(i % 10)), ratio_y(window) * (148 * 2 + (39 * 2) *
			(int)(i / 10))};
		rect = (sfFloatRect) {pos.x, pos.y, 34 * 2, 34 * 2};
		if (sfFloatRect_contains(&rect, event.x, event.y)) {
			sfSprite_setTexture(sprite, player->llist_item->base,
			0);
			sfSprite_setTextureRect(sprite, (sfIntRect)
			{0, 75 * iter->id, 249, 75});
			return;
		}
		i = i + 1;
	}
	sfSprite_setTexture(sprite, player->llist_item->none, 1);
}

void inventory_click(sfMouseButtonEvent event, player_t *player,
sfRenderWindow *window)
{
	item_t *iter = player->llist_item->first;
	int i = 0;
	sfFloatRect rect = {0};
	sfVector2f pos = {0};
	void (*callback[MAX_ITEM]) (player_t *player,
	float amount) = {&heal_player, &xp_player};

	for (i = 0; iter && i < 50; iter = iter->next) {
		pos = (sfVector2f) {ratio_x(window) * (158 * 2 + (40.5 * 2) *
			(i % 10)), ratio_y(window) * (148 * 2 + (39 * 2) *
			(int)(i / 10))};
		rect = (sfFloatRect) {pos.x, pos.y, 34 * 2, 34 * 2};
		if (sfFloatRect_contains(&rect, event.x, event.y) &&
		iter->id < MAX_ITEM) {
			callback[iter->id](player, 0.3);
			remove_item(player->llist_item, iter);
			break;
		}
		i = i + 1;
	}
}

int inventory_event2(sfRenderWindow *window, button_t **buttons, sfEvent event,
player_t *player)
{
	int i = 0;

	switch (event.type) {
	case sfEvtMouseButtonPressed:
		inventory_click(event.mouseButton, player, window);
		i = menu_click(event.mouseButton, buttons, window) + 1;
		break;
	default:
		break;
	}
	return (i);
}

int inventory_event(sfRenderWindow *window, button_t **buttons, sfEvent event,
player_t *player)
{
	int i = 0;

	while (sfRenderWindow_pollEvent(window, &event))
		switch (event.type) {
		case sfEvtClosed:
			sfRenderWindow_close(window);
			break;
		case sfEvtKeyPressed:
			return (-1);
		case sfEvtMouseMoved:
			inventory_hoover(event.mouseMove, player, window);
			menu_hoover(event.mouseMove, buttons, window, 113);
			break;
		default:
			i = inventory_event2(window, buttons, event, player);
			break;
		}
	return (i);
}
