/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file
*/

#include "my.h"

static int move_player_side_left_right(maps_t *maps, monster_t *monster,
int dist_x, sfVector2f *move)
{
	reset_monster_sprite(monster);
	if (dist_x > 0) {
		if (!check_all_ennemy_collisions(maps, monster,
		(sfVector2f) {6, 0})) {
			monster->rect.top += 32 * 2;
			move->x = 6;
			return (1);
		}
	} else {
		if (!check_all_ennemy_collisions(maps, monster,
		(sfVector2f) {-6, 0})) {
			monster->rect.top += 32 * 1;
			move->x = -6;
			return (1);
		}
	}
	return (0);
}

static int move_player_side_top_bot(maps_t *maps, monster_t *monster,
int dist_y, sfVector2f *move)
{
	reset_monster_sprite(monster);
	if (dist_y > 0) {
		if (!check_all_ennemy_collisions(maps, monster,
		(sfVector2f) {0, 6})) {
			monster->rect.top += 32 * 0;
			move->y = 6;
			return (1);
		}
	} else {
		if (!check_all_ennemy_collisions(maps, monster,
		(sfVector2f) {0, -6})) {
			monster->rect.top += 32 * 3;
			move->y = -6;
			return (1);
		}
	}
	return (0);
}

static void move_ennemy_left_side(maps_t *maps, player_t *player,
monster_t *monster, sfVector2f *move)
{
	sfVector2f pos_player = sfSprite_getPosition(player->sprite);

	move_player_side_left_right(maps, monster,
	pos_player.x - monster->pos.x, move);
	if (monster->rect.left >= 64)
		monster->rect.left = 0;
	else
		monster->rect.left += 32;
}

static void move_ennemy_top_side(maps_t *maps, player_t *player,
monster_t *monster, sfVector2f *move)
{
	sfVector2f pos_player = sfSprite_getPosition(player->sprite);

	move_player_side_top_bot(maps, monster,
	pos_player.y - monster->pos.y, move);
	if (monster->rect.left >= 64)
		monster->rect.left = 0;
	else
		monster->rect.left += 32;
}

void move_ennemy_to_player(maps_t *maps, player_t *player, monster_t *monster,
sfVector2f *move)
{
	sfVector2f pos_player = sfSprite_getPosition(player->sprite);
	int dist_x = pos_player.x - monster->pos.x;
	int dist_y = pos_player.y - monster->pos.y;
	int dist = (int) DISTANCE_PLAYER_ENNEMY(pos_player, monster->pos);

	if (dist < 300) {
		if (_IS_MAGE(monster) && DISTANCE_PLAYER_ENNEMY(pos_player,
			monster->pos) < 200)
			move_mage(maps, player, move, monster);
		else if ((dist_x - dist_x < 10 && dist_x >= 10) ||
			ABS(dist_x) > ABS(dist_y))
			move_ennemy_left_side(maps, player, monster, move);
		else
			move_ennemy_top_side(maps, player, monster, move);
	} else
		pick_random_move(monster, move);
}
