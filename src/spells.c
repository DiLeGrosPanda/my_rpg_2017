/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to manage the events
*/

#include "my.h"

void simple_fireball(UNUSED sfRenderWindow *window, maps_t *maps,
player_t *player, float seconds)
{
	if (!(seconds >= player->spells[0].iter_timer +
		player->spells[0].cd_time))
		return;
	add_fireball(maps, player);
	player->spells[0].iter_timer = seconds;
}

void multi_fireballs(UNUSED sfRenderWindow *window, maps_t *maps,
player_t *player, float seconds)
{
	if (!(seconds >= player->spells[2].iter_timer +
		player->spells[2].cd_time))
		return;
	add_tri_fireball(maps, player);
	player->spells[2].iter_timer = seconds;
}

void multi_dir_fireballs(UNUSED sfRenderWindow *window, maps_t *maps,
player_t *player, float seconds)
{
	if (!(seconds >= player->spells[1].iter_timer +
		player->spells[1].cd_time))
		return;
	add_mult_dir_fireball(maps, player);
	player->spells[1].iter_timer = seconds;
}

void buff_player(UNUSED sfRenderWindow *window, UNUSED maps_t *maps,
player_t *player, float seconds)
{
	if (!(seconds >= player->spells[3].iter_timer +
		player->spells[3].cd_time))
		return;
	player->is_buffed = 1;
	player->states.shader = player->shader;
	player->movement_speed += 2;
	player->spells[3].iter_timer = seconds;
}

void use_lightning(sfRenderWindow *window, maps_t *maps, player_t *player,
float seconds)
{
	if (!(seconds >= player->spells[4].iter_timer +
		player->spells[4].cd_time))
		return;
	player->spells[4].iter_timer = seconds;
	player->buffer = new_part_buffer(2);
	for (uint i = 0; i <= 2; i++) {
		if (i >= player->buffer->size) {
			check_lightning_hit(window, maps, player);
			return;
		}
		create_lightning_particules(window, player, i);
	}
}
