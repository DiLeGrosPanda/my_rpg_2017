/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my.h
*/

#include "my.h"

static const sfVector2f hitbox = {60, 60};

static void add_buttons_help(sfRenderWindow *window, player_t *player,
ath_t *ath)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
	sfVector2f need = MAP_PIXEL_COORDS(mouse_pos);
	sfVector2f pos_ath = get_spells_pos(window, player);
	sfSprite *sprite;

	for (int i = 0; i < SPELL_NBR; i++, pos_ath.x += 75)
		if (mouse_in_rect(need, pos_ath, hitbox)) {
			sprite = sfSprite_create();
			sfSprite_setPosition(sprite, (sfVector2f)
			{pos_ath.x, pos_ath.y - 120});
			sfSprite_setTexture(sprite, ath->ath_base, sfFalse);
			sfSprite_setTextureRect(sprite, (sfIntRect)
			{ath->skill_tree.unlocked[i] ? 0 : 250, 620 + i * 76,
				250, 80});
			sfRenderWindow_drawSprite(window, sprite, NULL);
		}
}

void add_help_skill_tree(sfRenderWindow *window, ath_t *ath,
sfVertexArray *array)
{
	sfVector2u size = sfRenderWindow_getSize(window);
	sfVector2f pos = MAP_TRUE_COORDS(POINT_Z, size);
	sfVector2f clic = GET_CLIC_POS(window);
	int i = get_selected_skill(size, clic);
	int pos_x;

	if (i == -1)
		return;
	pos_x = ath->skill_tree.unlocked[i] ? 0 : 250;
	sfVertexArray_append(array, (sfVertex) {{pos.x, pos.y},
		sfWhite, {pos_x, 618 + i * 75}});
	sfVertexArray_append(array, (sfVertex) {{pos.x + 250, pos.y},
		sfWhite, {pos_x + 250, 618 + i * 75}});
	sfVertexArray_append(array, (sfVertex) {{pos.x + 250, pos.y + 80},
		sfWhite, {pos_x + 250, 618 + i * 75 + 75}});
	sfVertexArray_append(array, (sfVertex) {{pos.x, pos.y + 80},
		sfWhite, {pos_x, 618 + i * 75 + 75}});
}

static void draw_buttons_vertex_array(sfRenderWindow *window,
		player_t *player, sfSprite *sprite)
{
	sfIntRect rect = {0, 1248, 128, 128};
	sfVector2f pos = {8, 300};
	sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
	sfVector2u size = sfRenderWindow_getSize(window);
	sfVector2f mouse_pos = {mouse.x, mouse.y};
	sfVector2f hitbox = {100, 100};

	for (int i = 0; i < 4; i++, pos.y += 100, rect.left += 145) {
		sfSprite_setTextureRect(sprite, rect);
		sfSprite_setPosition(sprite, pos);
		if (mouse_in_rect(mouse_pos, MAP_TRUE_COORDS(pos, size),
					hitbox)) {
			player->ath->states.shader = player->ath->shader;
			sfRenderWindow_drawSprite(window,
					sprite, &(player->ath->states));
			player->ath->states.shader = NULL;
		} else
			sfRenderWindow_drawSprite(window, sprite, NULL);
	}
}

static void add_interface_buttons_to_vertex_array(sfRenderWindow *window,
		player_t *player)
{
	sfSprite *sprite = sfSprite_create();

	sfSprite_setTexture(sprite, player->ath->ath_base, sfFalse);
	sfSprite_setScale(sprite, (sfVector2f) {0.7, 0.7});
	draw_buttons_vertex_array(window, player, sprite);
}

void draw_ath(sfRenderWindow *window, player_t *player, ath_t *ath,
		float seconds)
{
	sfView const *view = sfRenderWindow_getDefaultView(window);

	add_ath_to_vertex_array(ath->array, player);
	sfRenderWindow_setView(window, view);
	sfRenderWindow_drawVertexArray(window, ath->array, &(ath->states));
	sfVertexArray_clear(ath->array);
	add_interface_buttons_to_vertex_array(window, player);
	sfRenderWindow_setView(window, player->view);
	add_spells_to_vertex_array(window, ath->array, player, seconds);
	add_buttons_help(window, player, ath);
	sfRenderWindow_drawVertexArray(window, ath->array, &(ath->states));
	sfVertexArray_clear(ath->array);
	if (ath->skill_tree.is_active)
		display_skill_tree(window, ath, player, view);
}
