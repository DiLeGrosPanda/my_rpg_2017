/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my.h
*/

#include "my.h"

void talk_npc(player_t *player, maps_t *maps)
{
	sfIntRect rect_player = sfSprite_getTextureRect(player->sprite);

	rect_player.left = sfSprite_getPosition(player->sprite).x;
	rect_player.top = sfSprite_getPosition(player->sprite).y;
	for (int i = 0; maps->npc[i]; i++) {
		if (collision(rect_player, (sfIntRect) {maps->npc[i]->pos.x,
				maps->npc[i]->pos.y, maps->npc[i]->hitbox.x,
				maps->npc[i]->hitbox.y}))
			maps->npc[i]->to_display = 1;
	}
}

static void draw_shadered_npc(sfRenderWindow *window, player_t *player,
maps_t *maps, int i)
{
	sfVector2u size = sfRenderWindow_getSize(window);
	sfVector2f pos = {size.x / 2 - 600, size.y - 200};

	player->ath->states.shader = player->ath->shader;
	sfRenderWindow_drawSprite(window, maps->npc[i]->sprite,
	&(player->ath->states));
	player->ath->states.shader = NULL;
	if (maps->npc[i]->near_player == -1)
		maps->npc[i]->near_player = rand() % 3;
	if (!maps->npc[i]->to_display)
		return;
	sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
	sfSprite_setPosition(player->ath->dialogue.sprite, pos);
	sfRenderWindow_drawSprite(window, player->ath->dialogue.sprite, NULL);
	pos = (sfVector2f) {pos.x + 25, pos.y + 25};
	sfText_setPosition(player->ath->dialogue.text, pos);
	sfText_setFont(player->ath->dialogue.text, player->ath->dialogue.font);
	sfText_setString(player->ath->dialogue.text,
	maps->npc[i]->dialogues[maps->npc[i]->near_player]);
	sfRenderWindow_drawText(window, player->ath->dialogue.text, NULL);
	sfRenderWindow_setView(window, player->view);
}

void draw_npc(sfRenderWindow *window, player_t *player, maps_t *maps)
{
	sfIntRect rect_player = sfSprite_getTextureRect(player->sprite);

	rect_player.left = sfSprite_getPosition(player->sprite).x;
	rect_player.top = sfSprite_getPosition(player->sprite).y;
	for (int i = 0; maps->npc[i]; i++) {
		if (collision(rect_player, (sfIntRect) {maps->npc[i]->pos.x,
			maps->npc[i]->pos.y, maps->npc[i]->hitbox.x,
			maps->npc[i]->hitbox.y})) {
			draw_shadered_npc(window, player, maps, i);
		} else {
			maps->npc[i]->near_player = -1;
			maps->npc[i]->to_display = 0;
		}
	}
}
