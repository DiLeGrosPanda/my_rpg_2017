/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** file to manage the player
*/

#include "my.h"

static void display_infos(sfRenderWindow *window, player_t *player,
sfVector2f pos1)
{
	sfText *text = sfText_create();
	int vals[] = {(int) floor(player->xp), player->life,
		(int)(player->xp * 100) % 100, player->attack_dmg,
		player->movement_speed, player->golds};
	sfVector2f pos[] = {{150, 81}, {120, 116}, {120, 138}, {140, 191},
		{150, 222}, {125, 263}};
	char *str;

	sfText_setColor(text, sfWhite);
	sfText_setFont(text, player->ath->dialogue.font);
	sfText_setCharacterSize(text, 32);
	for (int i = 0; i < 6; i = i + 1) {
		str = nb_to_str(vals[i]);
		sfText_setPosition(text, (sfVector2f) {(pos1.x - 600) +
			pos[i].x * 2, (pos1.y - 400) + pos[i].y * 2});
		sfText_setString(text, str);
		sfRenderWindow_drawText(window, text, NULL);
		free(str);
	}
	sfText_destroy(text);
}

static void manage_events_player_infos(sfRenderWindow *window, int *is_open)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event))
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else if (event.type == sfEvtKeyPressed)
			*is_open = 0;
}

void display_player_infos(sfRenderWindow *window, player_t *player)
{
	sfTexture *texture = sfTexture_createFromFile(PATH_MENU, sfFalse);
	sfVector2f pos = sfSprite_getPosition(player->sprite);
	sfSprite *sprite = sfSprite_create();
	int is_open = 1;

	sfSprite_setTexture(sprite, texture, sfFalse);
	sfSprite_setScale(sprite, (sfVector2f) {2., 2.});
	sfSprite_setPosition(sprite, (sfVector2f) {pos.x - 600, pos.y - 400});
	while (sfRenderWindow_isOpen(window) && is_open) {
		manage_events_player_infos(window, &is_open);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		display_infos(window, player, pos);
		sfRenderWindow_display(window);
	}
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
}
