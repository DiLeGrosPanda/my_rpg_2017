/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to manage the quests
*/

#include "my.h"

static void display_quest_content(sfRenderWindow *window, player_t *player)
{
	sfText *text = sfText_create();
	sfFont *font = sfFont_createFromFile("Blacksword.otf");
	int quest_nbr = 0;

	for (; player->quests[quest_nbr].resolved; quest_nbr++);
	sfText_setFont(text, font);
	sfText_setColor(text, sfBlue);
	sfText_setString(text, player->quests[quest_nbr].content);
	sfText_setPosition(text, (sfVector2f)
	{sfSprite_getPosition(player->sprite).x - 400,
		sfSprite_getPosition(player->sprite).y - WIN_HEIGHT / 4});
	sfRenderWindow_drawText(window, text, NULL);
	sfFont_destroy(font);
	sfText_destroy(text);
}

static void event_quests(sfRenderWindow *window, int *is_open)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event))
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else if (event.type == sfEvtKeyPressed)
			*is_open = 0;
}

void display_quest(sfRenderWindow *window, player_t *player, sfSprite *sprite,
int is_open)
{
	sfTexture *texture = sfTexture_createFromFile(PATH_QUEST, sfFalse);
	sfVector2f pos = sfSprite_getPosition(player->sprite);

	sfSprite_setTexture(sprite, texture, sfFalse);
	sfSprite_setScale(sprite, (sfVector2f) {2., 2.});
	sfSprite_setPosition(sprite, (sfVector2f) {pos.x - 630, pos.y - 400});
	while (sfRenderWindow_isOpen(window) && is_open) {
		event_quests(window, &is_open);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		display_quest_content(window, player);
		sfRenderWindow_display(window);
	}
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
}
