/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** update player dir
*/

#include "my.h"

void update_player_dir(sfEvent event, player_t *player)
{
	move_t sprite_height[] = {LEFT, RIGHT, TOP, BOT};

	if (SF_KEY < sfKeyLeft || SF_KEY > sfKeyDown) {
		if (SF_KEY != sfKeySpace && SF_KEY != sfKeyZ &&
			SF_KEY != sfKeyA && SF_KEY != sfKeyE &&
			SF_KEY != sfKeyR)
			player->is_moving = 0;
		return;
	}
	player->is_moving = 1;
	player->move = sprite_height[SF_KEY - sfKeyLeft];
}
