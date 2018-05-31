/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file
*/

#include "my.h"

static void remove_out_of_range_fireballs(maps_t *maps, fireball_t *fireball)
{
	sfVector2f pos = sfSprite_getPosition(fireball->sprite);

	if ((pos.x > fireball->dest.x && fireball->move.x > 0) ||
		(pos.x < fireball->dest.x && fireball->move.x < 0) ||
		(pos.y > fireball->dest.y && fireball->move.y > 0) ||
		(pos.y < fireball->dest.y && fireball->move.y < 0))
		remove_fireballs(maps->llist_fireball, fireball);
}

void move_fireball(player_t *player, maps_t *maps, float seconds)
{
	static float elapsed_time;
	fireball_t *keep;
	sfIntRect temp;

	if (seconds - elapsed_time < 0.01)
		return;
	elapsed_time = seconds;
	for (fireball_t *tmp = maps->llist_fireball->first; tmp; tmp = keep) {
		keep = tmp->next;
		if (seconds > tmp->sprite_timer + 0.1) {
			tmp->sprite_timer = seconds;
			temp = sfSprite_getTextureRect(tmp->sprite);
			temp.left = temp.left >= 225 ? 0 : temp.left + 75;
			sfSprite_setTextureRect(tmp->sprite, temp);
		}
		sfSprite_move(tmp->sprite, tmp->move);
		if (check_collision_bdf_monsters(player, maps, tmp) ||
			check_collision_bdf_objects(maps, tmp))
			continue;
		remove_out_of_range_fireballs(maps, tmp);
	}
}
