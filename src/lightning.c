/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file
*/

#include "my.h"

static void call_draw_lightning(sfRenderWindow *window, maps_t *maps,
player_t *player, float seconds)
{
	for (int i = 0; i < LIGHTNING_NBR_MAX; i++) {
		if (seconds < LIGHTNING_ITEM.pre_show_atk &&
		LIGHTNING_ITEM.is_active) {
			sfSprite_setPosition(player->spells[4].sprite,
			(sfVector2f) {LIGHTNING_ITEM.pos.x,
				LIGHTNING_ITEM.pos.y});
			sfSprite_setTextureRect(player->spells[4].sprite,
			(sfIntRect) {0, 0, 50, 220});
			sfSprite_setScale(player->spells[4].sprite,
			(sfVector2f) {1, 1});
			sfRenderWindow_drawSprite(window,
			player->spells[4].sprite, NULL);
		} else if (LIGHTNING_ITEM.pre_show_atk != -1) {
			LIGHTNING_ITEM.pre_show_atk = -1;
			LIGHTNING_ITEM.count_display = seconds + 0.05;
		}
	}
}

static void lightning_hit_player(maps_t *maps, player_t *player, float seconds,
int i)
{
	sfVector2f pos = sfSprite_getPosition(player->sprite);

	if (collision((sfIntRect) {pos.x, pos.y, 32, 32},
	(sfIntRect) {LIGHTNING_ITEM.pos.x - 10,
		LIGHTNING_ITEM.pos.y - 10, 20, 20})
	&& seconds > player->dmg_cooldown + 1) {
		player->dmg_cooldown = seconds;
		player->life -= 1;
	}
	LIGHTNING_ITEM.is_active = 0;
}

static void anime_lightning(sfRenderWindow *window, maps_t *maps,
player_t *player, int i)
{
	sfVector2f need = LIGHTNING_ITEM.pos;
	sfVector2f pos = sfSprite_getPosition(player->sprite);
	float height = need.y - (pos.y - WIN_HEIGHT / 2);
	sfVector2f scale = {1, 1.1 * (height / 220)};
	float seconds = maps->llist_monsters->seconds;

	sfSprite_setPosition(player->spells[4].sprite, (sfVector2f)
	{LIGHTNING_ITEM.pos.x, LIGHTNING_ITEM.pos.y - WIN_HEIGHT / 2});
	sfSprite_setTextureRect(player->spells[4].sprite, LIGHTNING_ITEM.rect);
	sfSprite_setScale(player->spells[4].sprite, scale);
	sfRenderWindow_drawSprite(window, player->spells[4].sprite, NULL);
	if (pos.y > need.y)
		sfSprite_move(player->spells[4].sprite, (sfVector2f) {0, 20});
	LIGHTNING_ITEM.count_display = seconds + 0.05;
	if ((LIGHTNING_ITEM.rect.left += 50) == 50 * 6)
		lightning_hit_player(maps, player, seconds, i);
}

void display_lightning(sfRenderWindow *window, maps_t *maps, player_t *player,
float seconds)
{
	call_draw_lightning(window, maps, player, seconds);
	for (int i = 0; i < LIGHTNING_NBR_MAX; i++) {
		if (!LIGHTNING_ITEM.is_active ||
			LIGHTNING_ITEM.pre_show_atk != -1 ||
			seconds < LIGHTNING_ITEM.count_display)
			continue;
		anime_lightning(window, maps, player, i);
	}
}
