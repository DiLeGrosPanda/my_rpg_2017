/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Draw functions
*/

#include "my.h"

void draw_lightning(sfRenderWindow *window, player_t *player, float seconds)
{
	sfIntRect rect = sfSprite_getTextureRect(player->spells[4].sprite);
	static float elapsed_time;

	if (rect.left > 50 * 5)
		return;
	sfRenderWindow_drawSprite(window, player->spells[4].sprite, NULL);
	if (seconds - elapsed_time > 0.05) {
		rect.left += 50;
		elapsed_time = seconds;
	}
	sfSprite_setTextureRect(player->spells[4].sprite, rect);
}

static void update_particules(player_t *player, float seconds)
{
	static float a = 0.1;
	static float b = 0.1;
	static float c = 0.1;
	static float time;

	if (seconds - time > 0.1) {
		time = seconds;
		a = my_rand(0, 1000) / 1000.0;
		b = my_rand(0, 1000) / 1000.0;
		c = my_rand(0, 1000) / 1000.0;
	}
	sfShader_setFloatParameter(player->shader, "toto1", a);
	sfShader_setFloatParameter(player->shader, "toto2", b);
	sfShader_setFloatParameter(player->shader, "toto3", c);
}

void draw_player(sfRenderWindow *window, player_t *player, float seconds)
{
	sfVector2f pos = sfSprite_getPosition(player->sprite);

	if (player->ath->skill_tree.is_active ||
		(pos.x > 223 && pos.x < 380 && pos.y >
		1900 && pos.y < 2075))
		return;
	update_particules(player, seconds);
	if (player->states.shader)
		sfRenderWindow_drawSprite(window, player->sprite,
		&(player->states));
	else
		sfRenderWindow_drawSprite(window, player->sprite, NULL);
}

void draw_objects_and_monsters(sfRenderWindow *window, maps_t *maps,
player_t *player)
{
	sfVertexArray *array = sfVertexArray_create();

	sfVertexArray_setPrimitiveType(array, sfQuads);
	add_objects_to_vertex_array(array, maps, player);
	add_monsters_to_vertex_array(array, maps, player);
	sfRenderWindow_drawVertexArray(window, array, &(maps->states));
	sfVertexArray_destroy(array);
}

void draw_fireballs(sfRenderWindow *window, maps_t *maps)
{
	sfVertexArray *array = sfVertexArray_create();
	sfRenderStates states = (sfRenderStates) {
		.blendMode = sfBlendAlpha,
		.transform = sfTransform_Identity,
		.texture = maps->llist_fireball->texture,
	};

	sfVertexArray_setPrimitiveType(array, sfQuads);
	add_fireball_to_vertex_array(array, maps);
	sfRenderWindow_drawVertexArray(window, array, &states);
	sfVertexArray_destroy(array);
}
