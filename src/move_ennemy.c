/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file
*/

#include "my.h"

void reset_monster_sprite(monster_t *monster)
{
	if (monster->rect.top < 9 * 32)
		monster->rect.top = 5 * 32;
	else if (monster->rect.top < 13 * 32)
		monster->rect.top = 9 * 32;
	else
		monster->rect.top = 13 * 32;
}

void move_mage(maps_t *maps, player_t *player, sfVector2f *move,
monster_t *monster)
{
	sfVector2f pos = sfSprite_getPosition(player->sprite);
	float seconds = maps->llist_monsters->seconds;

	move->x = 0;
	move->y = 0;
	if (seconds < monster->cd_attack + 5)
		return;
	monster->cd_attack = seconds;
	for (int i = 0; i < LIGHTNING_NBR_MAX; i++)
		if (LIGHTNING_ITEM.is_active && collision((sfIntRect) {pos.x,
		pos.y, 32, 32}, (sfIntRect) {LIGHTNING_ITEM.pos.x - 10,
		LIGHTNING_ITEM.pos.y - 10, 20, 20}))
			return;
	for (int i = 0; i < LIGHTNING_NBR_MAX; i++)
		if (!LIGHTNING_ITEM.is_active) {
			LIGHTNING_ITEM.is_active = 1;
			LIGHTNING_ITEM.pos = pos;
			LIGHTNING_ITEM.rect = (sfIntRect) {0, 0, 50, 220};
			LIGHTNING_ITEM.pre_show_atk = seconds + 2;
			break;
		}
}

void move_ennemy(player_t *player, maps_t *maps, float seconds)
{
	static float elapsed_time;
	monster_t *keep;
	sfVector2f pos_player = sfSprite_getPosition(player->sprite);

	if (seconds - elapsed_time < 0.12)
		return;
	elapsed_time = seconds;
	for (monster_t *tmp = maps->llist_monsters->first; tmp; tmp = keep) {
		keep = tmp->next;
		if (DISTANCE_PLAYER_ENNEMY(pos_player, tmp->pos) > 700)
			continue;
		move_ennemy_sprite(player, maps, tmp, seconds);
		sfSprite_setTextureRect(tmp->sprite, tmp->rect);
	}
}
