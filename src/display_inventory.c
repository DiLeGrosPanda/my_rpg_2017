/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** file to manage the player
*/

#include "my.h"

static int print_inventory(sfRenderWindow *window, player_t *player,
sfTexture **textures, int check)
{
	sfSprite *sprite = sfSprite_create();
	sfVector2f pos = {30, 130};

	sfSprite_setPosition(sprite, (sfVector2f) {0, 0});
	sfSprite_setTexture(sprite, textures[1], sfTrue);
	sfSprite_setScale(sprite, (sfVector2f) {1 / ratio_x(window),
		1 / ratio_y(window)});
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfSprite_setScale(sprite, (sfVector2f) {1.7, 1.7});
	sfSprite_setPosition(sprite, pos);
	sfSprite_setTexture(sprite, textures[0], sfTrue);
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfSprite_setPosition(player->llist_item->sprite, (sfVector2f) {});
	sfSprite_destroy(sprite);
	if (check == 1)
		return (-1);
	else if (check == 2)
		return (1);
	return (0);
}

int print_items(sfRenderWindow *window, player_t *player, int offset)
{
	item_t *iter = player->llist_item->first;
	int count = 0;
	sfVector2f pos = {148 * 2, 93 * 2};
	sfTexture *temp = sfTexture_createFromFile("sprites/item.png", NULL);
	sfSprite *sprite = sfSprite_create();

	sfSprite_setTexture(sprite, temp, sfFalse);
	sfSprite_setScale(sprite, (sfVector2f) {1.7, 1.7});
	for (int i = 0; i < 50 * offset && iter; i = i + 1)
		iter = iter->next;
	for (; iter && count < 50; iter = iter->next) {
		pos = (sfVector2f) {158 * 2 + (40.5 * 2) * (count % 10), 148 *
			2 + (39 * 2) * (int)(count / 10)};
		sfSprite_setTextureRect(sprite,
		(sfIntRect) {0, iter->id * 34, 34, 34});
		sfSprite_setPosition(sprite, pos);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		count += 1;
	}
	return ((count == 50 ? 1 : 0));
}

void display_inventory_text(sfRenderWindow *window, player_t *player,
int offset)
{
	sfFont *font = sfFont_createFromFile("sprites/arial.ttf");
	sfText *text = sfText_create();
	char *str = nb_to_str(offset);

	sfText_setString(text, str);
	sfText_setFont(text, font);
	sfText_setPosition(text, (sfVector2f) {670, 197});
	sfRenderWindow_drawText(window, text, NULL);
	free(str);
	str = nb_to_str(player->golds);
	sfText_setString(text, str);
	sfText_setPosition(text, (sfVector2f) {670 + 350, 197});
	sfRenderWindow_drawText(window, text, NULL);
	free(str);
	sfText_destroy(text);
	sfFont_destroy(font);
}

void inventory_display(sfRenderWindow *window, player_t *player,
button_t **buttons, int offset)
{
	sfIntRect r = sfRectangleShape_getTextureRect(buttons[1]->rect);
	sfVector2i pos = sfMouse_getPositionRenderWindow(window);

	sfSprite_setPosition(player->llist_item->sprite, (sfVector2f)
	{pos.x + 20, pos.y - 80});
	display_inventory_text(window, player, offset);
	r.left = (print_items(window, player, offset) == 1 ?
	(r.left == 227 ? 0 : r.left) : 227);
	sfRectangleShape_setTextureRect(buttons[1]->rect, r);
	r = sfRectangleShape_getTextureRect(buttons[0]->rect);
	r.left = (offset == 0 ? 227 : (r.left == 227 ? 0 : r.left));
	sfRectangleShape_setTextureRect(buttons[0]->rect, r);
	sfRenderWindow_drawRectangleShape(window, buttons[0]->rect, NULL);
	sfRenderWindow_drawRectangleShape(window, buttons[1]->rect, NULL);
	sfRenderWindow_drawSprite(window, player->llist_item->sprite, NULL);
	sfRenderWindow_display(window);
	sfRenderWindow_clear(window, sfBlack);
}

void display_inventory(sfRenderWindow *window, player_t *player)
{
	int check = 1;
	button_t **buttons;
	sfTexture **textures = get_inventory_textures(window, &buttons);
	sfView const *view = sfRenderWindow_getDefaultView(window);
	sfView const *view2 = sfRenderWindow_getView(window);
	int offset = 0;

	sfRenderWindow_setView(window, view);
	while (sfRenderWindow_isOpen(window) && check != -1) {
		check = inventory_event(window, buttons, (sfEvent) {0}, player);
		inventory_display(window, player, buttons, offset);
		offset += print_inventory(window, player, textures, (check > 0 ?
		(sfRectangleShape_getTextureRect(buttons[check - 1]->rect).left
		== 227 ? 0 : check) : 0));
	}
	sfRenderWindow_setView(window, view2);
	sfTexture_destroy(textures[0]);
	sfTexture_destroy(textures[1]);
	free(textures);
	destroy_menu(buttons, NULL);
}
