/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Big file lol
*/

#include "my.h"

void remove_fireballs(llist_fireball_t *entry, fireball_t *to_remove)
{
	fireball_t *iter = entry->first;

	if (iter == to_remove) {
		sfSprite_destroy(to_remove->sprite);
		sfSound_stop(to_remove->sound);
		sfSound_destroy(to_remove->sound);
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
	destroy_fireball(iter, to_remove);
}

static void get_fireball_direction(player_t *player, fireball_t *new)
{
	if (player->move == BOT) {
		new->dest.y += FIREBALL_RANGE;
		new->move.y = MOVEMENT_SPEED_FIREBALL;
	}
	if (player->move == TOP) {
		new->dest.y -= FIREBALL_RANGE;
		new->move.y = -MOVEMENT_SPEED_FIREBALL;
	}
	if (player->move == LEFT) {
		new->dest.x -= FIREBALL_RANGE;
		new->move.x = -MOVEMENT_SPEED_FIREBALL;
	}
	if (player->move == RIGHT) {
		new->dest.x += FIREBALL_RANGE;
		new->move.x = MOVEMENT_SPEED_FIREBALL;
	}
}

void add_fireball(maps_t *maps, player_t *player)
{
	fireball_t *new = malloc(sizeof(*new));
	sfVector2f pos = sfSprite_getPosition(player->sprite);

	*new = (fireball_t) {.sprite = sfSprite_copy(
		maps->llist_fireball->sprite), .sound = sfSound_create()};
	sfSprite_setPosition(new->sprite, (sfVector2f)
	{pos.x - 20, pos.y - 20});
	sound_fireball(new, maps, pos);
	sfSprite_setTextureRect(new->sprite,
	(sfIntRect) {0, 76 * player->move, 75, 75});
	get_fireball_direction(player, new);
	if (!maps->llist_fireball->first) {
		maps->llist_fireball->first = new;
		maps->llist_fireball->last = new;
		return;
	}
	if (maps->llist_fireball->last)
		maps->llist_fireball->last->next = new;
	maps->llist_fireball->last = new;
}

void add_mult_dir_fireball(maps_t *maps, player_t *player)
{
	move_t keep = player->move;

	player->move = TOP;
	add_fireball(maps, player);
	player->move = BOT;
	add_fireball(maps, player);
	player->move = RIGHT;
	add_fireball(maps, player);
	player->move = LEFT;
	add_fireball(maps, player);
	player->move = keep;
}

void add_tri_fireball(maps_t *maps, player_t *player)
{
	sfVector2f keep = sfSprite_getPosition(player->sprite);
	sfVector2f pos_less = {keep.x - 32, keep.y - 32};
	sfVector2f pos_more = {keep.x + 32, keep.y + 32};

	add_fireball(maps, player);
	sfSprite_setPosition(player->sprite, pos_less);
	add_fireball(maps, player);
	sfSprite_setPosition(player->sprite, pos_more);
	add_fireball(maps, player);
	sfSprite_setPosition(player->sprite, keep);
}
