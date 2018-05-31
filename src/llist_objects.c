/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Big file lol
*/

#include "my.h"

void remove_object(llist_objects_t *entry, objects_t *to_remove)
{
	objects_t *iter = entry->first;

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

void spawn_object(maps_t *maps, sfVector2f pos)
{
	int rand_object = rand() % 10;

	switch (rand_object) {
	case 1:
		add_object(maps, HEART_VAL, pos);
		break;
	case 2:
		add_object(maps, XP_POT_VAL, pos);
		break;
	case 3:
		add_object(maps, HP_POT_VAL, pos);
		break;
	default:
		add_object(maps, COIN_VAL, pos);
		break;
	}
	add_object(maps, BLOOD_VAL, pos);
}

void remove_item(llist_item_t *entry, item_t *to_remove)
{
	item_t *iter = entry->first;

	if (iter == to_remove) {
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
	free(to_remove);
}

void add_item(player_t *player, int id)
{
	item_t *new = malloc(sizeof(*new));

	*new = (item_t) {.id = id};
	if (!player->llist_item->first) {
		player->llist_item->first = new;
		player->llist_item->last = new;
		return;
	}
	if (player && player->llist_item && player->llist_item->last)
		player->llist_item->last->next = new;
	player->llist_item->last = new;
}
