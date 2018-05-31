/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file
*/

#include "my.h"

static void clean_player(player_t *player)
{
	sfTexture_destroy(player->texture);
	sfShader_destroy(player->shader);
	sfSprite_destroy(player->sprite);
	sfView_destroy(player->view);
	sfTexture_destroy(player->llist_item->none);
	sfSprite_destroy(player->llist_item->sprite);
	sfTexture_destroy(player->llist_item->base);
	sfMusic_destroy(player->music);
	free(player->llist_item);
}

static void clean_maps(maps_t *maps)
{
	sfSoundBuffer_destroy(maps->fire_sound);
	sfVertexArray_destroy(maps->array_bg);
	sfSprite_destroy(maps->llist_fireball->sprite);
	sfTexture_destroy(maps->llist_fireball->texture);
	sfTexture_destroy(maps->texture_full);
}

static void clean_ath(ath_t *ath)
{
	sfShader_destroy(ath->shader);
	sfVertexArray_destroy(ath->array);
	sfTexture_destroy(ath->ath_base);
	sfFont_destroy(ath->dialogue.font);
	sfText_destroy(ath->dialogue.text);
	sfSprite_destroy(ath->dialogue.sprite);
	sfTexture_destroy(ath->dialogue.texture);
}

static void clean_llist(maps_t *maps)
{
	fireball_t *keep;
	objects_t *keep2;
	monster_t *keep3;

	for (int i = 0; i < SPRITE_BG_NBR; i++)
		sfSprite_destroy(maps->sprite_array[i]);
	for (fireball_t *tmp = maps->llist_fireball->first; tmp; tmp = keep) {
		keep = tmp->next;
		remove_fireballs(maps->llist_fireball, tmp);
	}
	for (objects_t *tmp = maps->llist_objects->first; tmp; tmp = keep2) {
		keep2 = tmp->next;
		remove_object(maps->llist_objects, tmp);
	}
	for (monster_t *tmp = maps->llist_monsters->first; tmp; tmp = keep3) {
		keep3 = tmp->next;
		remove_monster(maps->llist_monsters, tmp);
	}
	free(maps->llist_fireball);
	free(maps->llist_objects);
	free(maps->llist_monsters);
}

void clean_ressources(ath_t *ath, maps_t *maps, player_t *player)
{
	clean_ath(ath);
	clean_maps(maps);
	clean_player(player);
	clean_llist(maps);
}
