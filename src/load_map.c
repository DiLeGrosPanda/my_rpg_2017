/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to init the whole map
*/

#include "my.h"

void fill_maps_values(maps_t *maps)
{
	maps->texture_full = sfTexture_createFromFile(PATH_BG, sfFalse);
	maps->llist_objects = malloc(sizeof(*(maps->llist_objects)));
	maps->llist_objects->first = NULL;
	maps->llist_objects->last = NULL;
	maps->llist_fireball = malloc(sizeof(*(maps->llist_fireball)));
	maps->llist_fireball->texture = sfTexture_createFromFile(PATH_FIREBALL,
	sfFalse);
	maps->llist_fireball->first = NULL;
	maps->llist_fireball->last = NULL;
	maps->llist_fireball->sprite = sfSprite_create();
	for (int i = 0; i < LIGHTNING_NBR_MAX; i++)
		maps->llist_fireball->lightning[i] = (lightning_t) {0};
	maps->llist_monsters = malloc(sizeof(*(maps->llist_monsters)));
	maps->llist_monsters->first = NULL;
	maps->llist_monsters->last = NULL;
}

void fill_render_states(maps_t *maps)
{
	maps->states = (sfRenderStates) {0};
	maps->states.texture = maps->texture_full;
	maps->states.blendMode = sfBlendAlpha;
	maps->states.transform = sfTransform_Identity;
}
