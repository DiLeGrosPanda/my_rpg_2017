/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Check collisions
*/

#include "my.h"

int bdf_on_objects(maps_t *maps, fireball_t *iter, objects_t *obj)
{
	sfVector2f pos = sfSprite_getPosition(iter->sprite);

	if (collision((sfIntRect)
	{(int) obj->pos.x - 20, (int)
		obj->pos.y - 30, 32, 32},
	(sfIntRect) {(int) pos.x, (int) pos.y, 40, 40}) &&
	obj->value != HEART_VAL && obj->value != HP_POT_VAL &&
	obj->value != COIN_VAL && obj->value != XP_POT_VAL &&
	obj->value != BLOOD_VAL) {
		remove_fireballs(maps->llist_fireball, iter);
		if (!(obj->life -= 1))
			remove_object(maps->llist_objects, obj);
		return (1);
	}
	return (0);
}

int check_collision_bdf_objects(maps_t *maps, fireball_t *iter)
{
	for (objects_t *obj = maps->llist_objects->first; obj; obj = obj->next)
		if (bdf_on_objects(maps, iter, obj))
			return (1);
	return (0);
}

static int bdf_hit_monster(player_t *player, maps_t *maps, fireball_t *iter,
monster_t *monster)
{
	sfVector2f pos = sfSprite_getPosition(iter->sprite);

	if (collision((sfIntRect) {(int) monster->pos.x
		- 20, (int)monster->pos.y - 30,
		32, 32}, (sfIntRect) {(int) pos.x, (int) pos.y, 40, 40})) {
		remove_fireballs(maps->llist_fireball, iter);
		monster->life -= 1;
		if (!monster->life || monster->life == -1)
			player_kill_monster(player, maps, monster);
		return (1);
	}
	return (0);
}

int check_collision_bdf_monsters(player_t *player, maps_t *maps,
fireball_t *iter)
{
	for (monster_t *monster = maps->llist_monsters->first; monster;
		monster = monster->next)
		if (bdf_hit_monster(player, maps, iter, monster))
			return (1);
	return (0);
}
