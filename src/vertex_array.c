/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to fill the vertex arrays
*/

#include "my.h"

void add_player_xp_to_vertex_array(sfVertexArray *array, player_t *player)
{
	float xp = ((int)player->xp - player->xp) * -1;

	sfVertexArray_append(array, (sfVertex)
	{{112, 41}, sfWhite, {216, 227}});
	sfVertexArray_append(array, (sfVertex)
	{{112 + (305 - 112) * xp, 41}, sfWhite,
		{216 + (603.0 - 216) * xp, 227}});
	sfVertexArray_append(array, (sfVertex)
	{{112 + (305 - 112) * xp, 48}, sfWhite,
		{216 + (603.0 - 216) * xp, 241}});
	sfVertexArray_append(array, (sfVertex)
	{{112, 48}, sfWhite, {216, 241}});
}

void add_ath_to_vertex_array(sfVertexArray *array, player_t *player)
{
	float life = player->life / (float)player->life_max;
	sfColor color = sfWhite;

	sfVertexArray_append(array, (sfVertex) {{0, 0}, sfWhite, {0, 0}});
	sfVertexArray_append(array, (sfVertex) {{310, 0}, sfWhite, {621, 0}});
	sfVertexArray_append(array, (sfVertex) {{310, 90}, color, {621, 180}});
	sfVertexArray_append(array, (sfVertex) {{0, 90}, sfWhite, {0, 180}});
	sfVertexArray_append(array, (sfVertex)
	{{107, 22}, sfWhite, {206, 190}});
	sfVertexArray_append(array, (sfVertex)
	{{107 + (302.0 - 107) * life, 22}, sfWhite,
		{206 + (595.0 - 206) * life, 190}});
	sfVertexArray_append(array, (sfVertex)
	{{107 + (302.0 - 107) * life, 30}, sfWhite,
		{206 + (595.0 - 206) * life, 204}});
	sfVertexArray_append(array, (sfVertex)
	{{107, 30}, sfWhite, {206, 204}});
	add_player_xp_to_vertex_array(array, player);
}

void add_objects_to_vertex_array(sfVertexArray *array, maps_t *maps,
player_t *player)
{
	sfVector2f pos_player = sfSprite_getPosition(player->sprite);
	sfVector2f pos_sprite;
	sfVector2f pos;

	for (objects_t *tmp = maps->llist_objects->first; tmp;
	tmp = tmp->next) {
		pos = tmp->pos;
		if (check_distance(pos_player, pos, 700))
			continue;
		pos_sprite = (sfVector2f) {tmp->value % SPRITE_BG_WIDTH * 32,
			tmp->value / SPRITE_BG_WIDTH * 32};
		sfVertexArray_append(array, (sfVertex)
		{{pos.x, pos.y}, sfWhite, pos_sprite});
		sfVertexArray_append(array, (sfVertex) {{pos.x + 32, pos.y},
		sfWhite, {pos_sprite.x + 32, pos_sprite.y}});
		sfVertexArray_append(array, (sfVertex) {{pos.x + 32, pos.y +
			32}, sfWhite, {pos_sprite.x + 32, pos_sprite.y + 32}});
		sfVertexArray_append(array, (sfVertex) {{pos.x, pos.y + 32},
			sfWhite, {pos_sprite.x, pos_sprite.y + 32}});
	}
}
