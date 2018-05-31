/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file
*/

#include <assert.h>
#include "my.h"

void pick_random_move(monster_t *iter, sfVector2f *move)
{
	int i = 0;
	sfVector2f moves[4] = {{0, 5}, {-5, 0}, {5, 0}, {0, -5}};

	iter->rect.left = iter->rect.left >= 64 ? 0 : iter->rect.left + 32;
	if (iter->rect.left < 64) {
		get_ennemy_random_move(iter, move);
		return;
	}
	if (my_rand(0, 10) < 2) {
		get_ennemy_random_move(iter, move);
	} else if ((i = my_rand(0, 10)) < 4) {
		reset_monster_sprite(iter);
		iter->rect.top += i * 32;
		move->x = moves[i].x;
		move->y = moves[i].y;
	}
}

int get_inverse_move(monster_t *monster, objects_t *iter, sfVector2f *move)
{
	int i;

	if (check_collision_ennemy_decor(monster, iter,
		(sfVector2f) {-move->x, -move->y}))
		return (0);
	*move = (sfVector2f) {-move->x, -move->y};
	i = monster->rect.top;
	i = i - 13 * 32 >= 0 ? i - 13 * 32 : i;
	i = i - 9 * 32 >= 0 ? i - 9 * 32 : i;
	i = i - 5 * 32 >= 0 ? i - 5 * 32 : i;
	if (!(i = i / 32))
		monster->rect.top += 3 * 32;
	else if (i == 1)
		monster->rect.top += 1 * 32;
	else
		if (i == 2)
			monster->rect.top -= 1 * 32;
		else if (i == 3)
			monster->rect.top -= 3 * 32;
	return (1);
}

void get_ennemy_random_move(monster_t *monster, sfVector2f *move)
{
	int dir = ((monster->rect.top / 32) - 5) % 4;

	switch ((dir)) {
	case 0:
		move->y = 5;
		break;
	case 1:
		move->x = -5;
		break;
	case 2:
		move->x = 5;
		break;
	default:
		move->y = -5;
	}
}

int check_all_ennemy_collisions(maps_t *maps, monster_t *monster,
sfVector2f move)
{
	for (objects_t *iter = maps->llist_objects->first; iter;
		iter = iter->next)
		if (check_collision_ennemy_decor(monster, iter, move))
			return (1);
	for (monster_t *iter = maps->llist_monsters->first; iter; iter =
		iter->next)
		if (check_collision_ennemy_ennemy(monster, iter, move))
			return (1);
	return (0);
}

void move_ennemy_sprite(player_t *player, maps_t *maps, monster_t *monster,
float seconds)
{
	sfVector2f move = {0, 0};

	maps->llist_monsters->seconds = seconds;
	move_ennemy_to_player(maps, player, monster, &move);
	for (objects_t *tmp = maps->llist_objects->first; tmp; tmp = tmp->next)
		if (check_collision_ennemy_decor(monster, tmp, move))
			return;
	sfSprite_move(monster->sprite, move);
}
