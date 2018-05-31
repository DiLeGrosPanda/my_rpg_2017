/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** file to manage the player
*/

#include "my.h"

void debuff_player(player_t *player, float seconds)
{
	if (player->is_buffed && seconds - player->spells[3].iter_timer > 5.) {
		player->is_buffed = 0;
		player->movement_speed -= 2;
		player->states.shader = NULL;
	}
}

static void animate_player(player_t *player, float seconds)
{
	static float elapsed_time;

	if (seconds - elapsed_time < 0.15)
		return;
	elapsed_time = seconds;
	sfSprite_setTextureRect(player->sprite, (sfIntRect)
	{player->sprite_count * 32, player->move * 32, 32, 32});
	if (player->sprite_count == 2)
		player->sprite_count = -1;
	player->sprite_count += 1;
}

void move_player(float seconds, player_t *player, sfRenderWindow *window,
maps_t *maps)
{
	sfVector2f move[] = {{0, player->movement_speed},
		{-player->movement_speed, 0},
		{player->movement_speed, 0},
		{0, -player->movement_speed}
	};
	sfIntRect rect = {move[player->move].x, move[player->move].y, 45, 40};
	static float elapsed_time;

	debuff_player(player, seconds);
	if (player->is_moving == 0 || seconds - elapsed_time < 0.01)
		return;
	elapsed_time = seconds;
	if (check_collision_player_objects(player, maps, rect))
		sfSprite_move(player->sprite, move[player->move]);
	else
		player->is_moving = 0;
	animate_player(player, seconds);
	sfView_destroy(player->view);
	player->view = sfView_copy(sfRenderWindow_getView(window));
	sfView_setCenter(player->view, sfSprite_getPosition(player->sprite));
	sfRenderWindow_setView(window, player->view);
}
