/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Big file lol
*/

#include "my.h"

static const int default_life_obj[500][2] = {
	{50, 1},
	{51, 1},
	{52, 1},
	{53, 1},
	{86, 1},
	{87, 1},
	{88, 1},
	{89, 1},
	{122, 1},
	{123, 1},
	{124, 1},
	{125, 1},
	{158, 1},
	{159, 1},
	{160, 1},
	{161, 1},
	{324, 3},
	{325, 3},
	{326, 3},
	{360, 3},
	{361, 3},
	{362, 3},
	{362, 3},
	{396, 1},
	{397, 3},
	{398, 3},
	{432, 3},
	{433, 3},
	{434, 3},
	{255, -2},
	{435, -2},
	{507, -2},
	{363, -2},
	{255, -2},
	{399, -2},
	{327, -2},
	{471, -2},
};

int get_default_life(int value)
{
	for (int i = 0; i < ARRAY_SIZE(default_life_obj); i++)
		if (default_life_obj[i][0] == value)
			return (default_life_obj[i][1]);
	return (0);
}

void add_monster(maps_t *maps, sfVector2f pos, int value)
{
	monster_t *new = malloc(sizeof(*new));

	*new = (monster_t) {.sprite = sfSprite_copy(maps->sprite_array[20]),
		.life = get_default_life(value), .rect = (sfIntRect) {
			0, 5 * 32, 32, 32}, .next = NULL};
	if (IS_GOBELIN(value))
		new->rect.top = 5 * 32;
	else if (IS_SOLDIER(value))
		new->rect.top = 9 * 32;
	if (IS_MAGE(value))
		new->rect.top = 13 * 32;
	sfSprite_setTextureRect(new->sprite, new->rect);
	sfSprite_setPosition(new->sprite, pos);
	if (!maps->llist_monsters->first) {
		maps->llist_monsters->first = new;
		maps->llist_monsters->last = new;
		return;
	}
	maps->llist_monsters->last->next = new;
	maps->llist_monsters->last = new;
}

void remove_monster(llist_monsters_t *entry, monster_t *to_remove)
{
	monster_t *iter = entry->first;

	if (iter == to_remove) {
		sfSprite_destroy(to_remove->sprite);
		entry->first = to_remove->next;
		if (entry->last == to_remove)
			entry->last = NULL;
		free(to_remove);
		return;
	}
	if (entry->last == to_remove)
		entry->last = NULL;
	for (iter = iter; iter && iter->next != to_remove; iter = iter->next);
	if (!iter)
		return;
	iter->next = iter->next->next;
	sfSprite_destroy(to_remove->sprite);
	free(to_remove);
}

void add_object(maps_t *maps, int value, sfVector2f pos)
{
	objects_t *new = malloc(sizeof(*new));

	*new = (objects_t) {.value = value,
		.life = get_default_life(value),
		.sprite = sfSprite_copy(maps->sprite_array[value]),
		.next = NULL,
	};
	sfSprite_setPosition(new->sprite, pos);
	if (!maps->llist_objects->first) {
		maps->llist_objects->first = new;
		maps->llist_objects->last = new;
		return;
	}
	if (maps && maps->llist_objects && maps->llist_objects->last)
		maps->llist_objects->last->next = new;
	maps->llist_objects->last = new;
}
