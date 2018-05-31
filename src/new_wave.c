/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file
*/

#include "my.h"

void add_new_wave(sfRenderWindow *window, maps_t *maps, player_t *player)
{
	sfVector2f un = {2065, 580};
	sfVector2f deux = {2550, 650};
	sfVector2f trois = {2825, 555};
	sfVector2f quatre = {300, 430};
	sfVector2f cinq = {2838, 1040};

	if (maps->llist_monsters->first)
		return;
	add_monster(maps, un, 20);
	add_monster(maps, deux, 20);
	add_monster(maps, trois, 20);
	add_monster(maps, quatre, 20);
	add_monster(maps, cinq, 20);
	sfSprite_setPosition(player->sprite, PLAYER_START_POS);
	sfView_destroy(player->view);
	player->view = sfView_copy(sfRenderWindow_getView(window));
	sfView_setCenter(player->view, sfSprite_getPosition(player->sprite));
	sfRenderWindow_setView(window, player->view);
}
