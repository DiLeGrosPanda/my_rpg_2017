/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg
*/

#include "my.h"

int get_state(sfRenderWindow *window, int state, char key_binding[SPELL_NBR])
{
	if (state == 1)
		return (get_settings(window, state, key_binding));
	else if (state == 2)
		return (how_to_play(window));
	return (state);
}

sfVector2f get_offset(sfRenderWindow *window)
{
	sfVector2f tmp = {640, 750};
	sfVector2u size = sfRenderWindow_getSize(window);
	sfVector2f need = MAP_TRUE_COORDS(tmp, size);
	sfVector2f pos = {size.x / 2 - need.x / 2, size.y / 2 - need.y / 2};

	if (size.x == 932)
		return ((sfVector2f) {pos.x + 100, pos.y + 30});
	if (size.x == 1036)
		return ((sfVector2f) {pos.x + 50, pos.y + 10});
	if (size.x == 1152)
		return ((sfVector2f) {pos.x + 20, pos.y + 5});
	if (size.x == 1408)
		return ((sfVector2f) {pos.x - 40, pos.y - 10});
	if (size.x == 1548)
		return ((sfVector2f) {pos.x - 75, pos.y - 20});
	return (pos);
}

void add_skill_tree_to_vertex_array(sfRenderWindow *window,
const sfTexture *texture)
{
	sfIntRect rect = {500, 500, 680, 750};
	sfSprite *sprite = sfSprite_create();
	sfVector2f pos = get_offset(window);

	sfSprite_setTexture(sprite, texture, sfFalse);
	sfSprite_setTextureRect(sprite, rect);
	sfSprite_setPosition(sprite, pos);
	sfRenderWindow_drawSprite(window, sprite, NULL);
}
