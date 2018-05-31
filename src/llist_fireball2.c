/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg
*/

#include "my.h"

void sound_fireball(fireball_t *new, maps_t *maps, sfVector2f pos)
{
	sfSound_setBuffer(new->sound, maps->fire_sound);
	sfSound_play(new->sound);
	new->buffer = init();
	new->dest = (sfVector2f) {pos.x, pos.y};
}

void destroy_fireball(fireball_t *iter, fireball_t *to_remove)
{
	iter->next = iter->next->next;
	sfSprite_destroy(to_remove->sprite);
	sfSound_stop(to_remove->sound);
	sfSound_destroy(to_remove->sound);
	free(to_remove);
}
