/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Callbacks
*/

#include "my.h"

int get_id(int id)
{
	return (id);
}

void heal_player(player_t *player, float amount)
{
	player->life += amount * 10;
}

void xp_player(player_t *player, float amount)
{
	int keep = (int) player->xp;

	player->xp += amount;
	if ((int) player->xp > keep)
		player->ath->skill_tree.skills_point += 1;
}
