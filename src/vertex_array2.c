/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg
*/

#include "my.h"

void add_monsters_to_vertex_array(sfVertexArray *array, maps_t *maps,
player_t *player)
{
	sfVector2f pos_player = sfSprite_getPosition(player->sprite);
	sfVector2f pos_monster;
	sfVector2f pos;

	for (monster_t *iter = maps->llist_monsters->first; iter;
	iter = iter->next) {
		pos_monster = iter->pos;
		if ((int) DISTANCE_PLAYER_ENNEMY(pos_player, pos_monster) > 700)
			continue;
		pos = iter->pos;
		sfVertexArray_append(array, (sfVertex) {{pos.x, pos.y}, sfWhite,
			{iter->rect.left, iter->rect.top}});
		sfVertexArray_append(array, (sfVertex) {{pos.x + 32, pos.y},
			sfWhite, {iter->rect.left + 32, iter->rect.top}});
		sfVertexArray_append(array, (sfVertex) {{pos.x + 32, pos.y +
		32}, sfWhite, {iter->rect.left + 32, iter->rect.top + 32}});
		sfVertexArray_append(array,
		(sfVertex) {{pos.x, pos.y + 32}, sfWhite,
			{iter->rect.left, iter->rect.top + 32}});
	}
}

void add_fireball_to_vertex_array(sfVertexArray *array, maps_t *maps)
{
	sfVector2f sprite_pos;
	sfVector2f pos;

	for (fireball_t *i = maps->llist_fireball->first; i; i = i->next) {
		pos = sfSprite_getPosition(i->sprite);
		sprite_pos.y = (i->move.y > 0 ? 150 : (i->move.y < 0 ?
		75 : (i->move.x < 0 ? 225 : 0)));
		sprite_pos.x = sfSprite_getTextureRect(i->sprite).left;
		sfVertexArray_append(array, (sfVertex) {{pos.x - 35, pos.y},
		sfWhite, {sprite_pos.x, sprite_pos.y}});
		sfVertexArray_append(array, (sfVertex)
		{{pos.x + 65, pos.y}, sfWhite,
			{sprite_pos.x, sprite_pos.y + 75}});
		sfVertexArray_append(array, (sfVertex)
		{{pos.x + 65, pos.y + 100}, sfWhite,
			{sprite_pos.x + 75, sprite_pos.y + 75}});
		sfVertexArray_append(array, (sfVertex)
		{{pos.x - 35, pos.y + 100}, sfWhite,
			{sprite_pos.x + 75, sprite_pos.y}});
	}
}
