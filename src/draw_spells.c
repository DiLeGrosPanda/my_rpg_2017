/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to fill the vertex arrays
*/

#include "my.h"

static void draw_blank_spell(sfRenderWindow *window, sfVertexArray *array,
player_t *player)
{
	sfVector2f points[4] = {
		get_pos_spells_blank_hud(window, player, 0),
		get_pos_spells_blank_hud(window, player, 1),
		get_pos_spells_blank_hud(window, player, 2),
		get_pos_spells_blank_hud(window, player, 3),
	};

	sfVertexArray_append(array, (sfVertex) {points[0],
		sfWhite, {0, 250}});
	sfVertexArray_append(array, (sfVertex) {points[1],
		sfWhite, {0 + 375, 250}});
	sfVertexArray_append(array, (sfVertex) {points[2],
		sfWhite, {0 + 375, 250 + 75}});
	sfVertexArray_append(array, (sfVertex) {points[3],
		sfWhite, {0, 250 + 75}});
}

static void draw_spells_sprites(sfVertexArray *array, sfVector2f pos_ath,
int sprite_offset)
{
	sfVertexArray_append(array, (sfVertex)
	{pos_ath, sfWhite, {sprite_offset, 560}});
	sfVertexArray_append(array, (sfVertex)
	{{pos_ath.x, pos_ath.y + 77}, sfWhite, {sprite_offset, 560 + 40}});
	sfVertexArray_append(array, (sfVertex)
	{{pos_ath.x + 70, pos_ath.y + 77}, sfWhite,
		{sprite_offset + 40, 560 + 40}});
	sfVertexArray_append(array, (sfVertex)
	{{pos_ath.x + 70, pos_ath.y}, sfWhite, {sprite_offset + 40, 560}});
}

static void add_undeblocked_sprite(sfVertexArray *array, sfVector2f pos_ath)
{
	sfVertexArray_append(array,
			(sfVertex) {pos_ath, sfWhite,
			{300, 550}});
	sfVertexArray_append(array,
			(sfVertex) {{pos_ath.x, pos_ath.y + 77}, sfWhite,
			{300, 550 + 40}});
	sfVertexArray_append(array,
			(sfVertex) {{pos_ath.x + 70, pos_ath.y + 77}, sfWhite,
			{300 + 40, 550 + 40}});
	sfVertexArray_append(array,
			(sfVertex) {{pos_ath.x + 70, pos_ath.y}, sfWhite,
			{300 + 40, 550}});
}

static void add_spell_cooldown(sfVertexArray *array, sfVector2f pos_ath,
		player_t *player, int i)
{
	float seconds = player->seconds;

	sfVertexArray_append(array,
			(sfVertex) {pos_ath, sfWhite,
			{200, 350}});
	sfVertexArray_append(array,
			(sfVertex) {{pos_ath.x, pos_ath.y + 77 * PERCENT_CD},
			sfWhite,
			{200, 350 + 40}});
	sfVertexArray_append(array,
			(sfVertex) {{pos_ath.x + 70,
			pos_ath.y + 77 * PERCENT_CD},
			sfWhite, {200 + 40, 350 + 40}});
	sfVertexArray_append(array,
			(sfVertex) {{pos_ath.x + 70, pos_ath.y}, sfWhite,
			{200, 350 + 40}});
}

void add_spells_to_vertex_array(sfRenderWindow *window, sfVertexArray *array,
player_t *player, float seconds)
{
	sfVector2f pos_ath = get_spells_pos(window, player);
	int sprite_offset = 0;

	draw_blank_spell(window, array, player);
	for (int i = 0; i < SPELL_NBR; i++) {
		if (player->spells[i].unlocked) {
			player->seconds = seconds;
			draw_spells_sprites(array, pos_ath, sprite_offset);
			add_spell_cooldown(array, pos_ath, player, i);
		} else {
			add_undeblocked_sprite(array, pos_ath);
		}
		sprite_offset += 40;
		pos_ath.x += 75;
	}
}
