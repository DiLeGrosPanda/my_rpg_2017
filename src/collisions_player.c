/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** file to check collisions on the player
*/

#include "my.h"

int check_collisions_player_ennemy(player_t *player,
maps_t *maps, float seconds)
{
	static float elapsed_time;
	sfIntRect box1 = {sfSprite_getPosition(player->sprite).x,
		sfSprite_getPosition(player->sprite).y, 32, 32};
	sfIntRect box2 = {0, 0, 32, 32};
	sfVector2f pos;

	if (seconds - 1.0 < elapsed_time)
		return (0);
	for (monster_t *iter = maps->llist_monsters->first; iter;
	iter = iter->next) {
		pos = iter->pos;
		box2 = (sfIntRect) {pos.x, pos.y, 32, 32};
		if (collision(box1, box2) && seconds >
		player->dmg_cooldown + 1) {
			player->life -= 1;
			player->dmg_cooldown = seconds;
			elapsed_time = seconds;
			break;
		}
	}
	return (player->life == 0 ? 1 : 0);
}

int player_hit_object2(player_t *player, maps_t *maps, objects_t *obj)
{
	switch (obj->value) {
	case XP_POT_VAL:
		add_item(player, 1);
		remove_object(maps->llist_objects, obj);
		return (1);
	case HP_POT_VAL:
		add_item(player, 0);
		remove_object(maps->llist_objects, obj);
		return (1);
	default:
		return (0);
	}
}

int player_hit_object(player_t *player, maps_t *maps, objects_t *obj)
{
	switch (obj->value) {
	case BLOOD_VAL:
		return (1);
	case HEART_VAL:
		player->life += 1;
		remove_object(maps->llist_objects, obj);
		return (1);
	case COIN_VAL:
		player->golds += my_rand(5, 25);
		remove_object(maps->llist_objects, obj);
		return (1);
	default:
		return (player_hit_object2(player, maps, obj));
	}
}

int check_distance(sfVector2f un, sfVector2f deux, int dist)
{
	int dist_x = un.x - deux.x;
	int dist_y = un.y - deux.y;

	if (dist_x > dist || dist_x < -dist || dist_y > dist || dist_y < -dist)
		return (1);
	if (DISTANCE_PLAYER_ENNEMY(un, deux) > dist)
		return (1);
	return (0);
}

int check_collision_player_objects(player_t *player, maps_t *maps,
sfIntRect rect)
{
	sfVector2f pos = sfSprite_getPosition(player->sprite);
	sfVector2f pos_player = sfSprite_getPosition(player->sprite);
	objects_t *keep;
	int ret = 1;
	int temp = 1;

	rect.left += pos.x - 26;
	rect.top += pos.y - 10;
	if (rect.left < 0 || rect.top < 0 || rect.left > COL_NBR * 32
		|| rect.top > LINES_NBR * 32)
		return (0);
	for (objects_t *tmp = maps->llist_objects->first; tmp; tmp = keep) {
		keep = tmp->next;
		pos = tmp->pos;
		if (check_distance(pos_player, pos, 100))
			continue;
		if (collision(rect, (sfIntRect) {pos.x, pos.y, 0, 0}))
			temp = player_hit_object(player, maps, tmp);
		ret = !temp ? 0 : ret;
	}
	return (ret);
}
