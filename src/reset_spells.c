/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to reset spells
*/

#include "my.h"


static void reset_skill(player_t *player, int skill_nbr)
{
	player->ath->skill_tree.unlocked[skill_nbr] = 0;
	player->ath->skill_tree.skills_point += 1;
	if (skill_nbr == 5)
		player->movement_speed -= 1;
	else if (skill_nbr == 6)
		player->life_max -= 0;
	if (skill_nbr == 7)
		for (int i = 0; i < 5; i++)
			player->spells[i].cd_time *= 2;
}

void reset_skill_tree(player_t *player)
{
	for (int i = 1; i < 8; i++)
		if (player->ath->skill_tree.unlocked[i])
			reset_skill(player, i);
	for (int i = 1; i < 5; i++)
		if (player->spells[i].unlocked)
			player->spells[i].unlocked = 0;
}
