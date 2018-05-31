/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to manage the quests
*/

#include "my.h"

static void check_first_quest(maps_t *maps, sfRenderWindow *window,
player_t *player)
{
	sfVector2f player_pos = sfSprite_getPosition(player->sprite);
	sfVector2f pnj_pos = FIRST_PNJ_POS;
	objects_t *obj = maps->llist_objects->first;
	objects_t *tmp;

	if (player_pos.x > pnj_pos.x - 30 && player_pos.x < pnj_pos.x + 80 &&
	player_pos.y > pnj_pos.y - 35 && player_pos.y < pnj_pos.y + 80) {
		for (int i = 0; i < 6; i++) {
			for (tmp = obj; tmp->value != 543; tmp = tmp->next);
			remove_object(maps->llist_objects, tmp);
		}
		player->quests[0].resolved = 1;
		display_dialogue_quest(window, player);
	}
}

static void check_second_quest(sfRenderWindow *window, player_t *player)
{
	if (player->monster_killed != 5)
		return;
	player->quests[1].resolved = 1;
	display_dialogue_quest(window, player);
}

static void check_third_quest(sfRenderWindow *window, player_t *player)
{
	if (player->monster_killed != 97)
		return;
	player->monster_killed += 1;
	display_dialogue_quest(window, player);
	player->quests[2].resolved = 1;
}

void check_quests(sfRenderWindow *window, maps_t *maps, player_t *player)
{
	switch (get_quest_nbr(player)) {
	case 0:
		check_first_quest(maps, window, player);
		break;
	case 1:
		check_second_quest(window, player);
		break;
	case 2:
		check_third_quest(window, player);
		break;
	default:
		break;
	}
}
