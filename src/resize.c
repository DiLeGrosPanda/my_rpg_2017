/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** resize.c
*/

#include "my.h"

static const sfVector2f hitbox = {60, 60};
static const sfVector2f point1 = {500, 740};
static const sfVector2f point2 = {500, 612};
static const sfVector2f point3 = {360, 470};
static const sfVector2f point4 = {640, 470};
static const sfVector2f point5 = {356, 300};
static const sfVector2f point6 = {500, 340};
static const sfVector2f point7 = {640, 300};
static const sfVector2f point8 = {500, 200};

sfVector2f get_spells_pos(sfRenderWindow *window, player_t *player)
{
	sfVector2u pos = sfRenderWindow_getSize(window);
	sfVector2f pos_player = sfSprite_getPosition(player->sprite);
	sfVector2f pos_ath = POS_SPELLS_VERTICE_1;

	switch (pos.x) {
	case 932:
		return ((sfVector2f) {pos_ath.x + 33, pos_ath.y + 150});
	case 1036:
		return ((sfVector2f) {pos_ath.x + 33, pos_ath.y + 100});
	case 1152:
		return ((sfVector2f) {pos_ath.x + 33, pos_ath.y + 50});
	case 1280:
		return ((sfVector2f) {pos_ath.x + 33, pos_ath.y + 27});
	case 1408:
		return ((sfVector2f) {pos_ath.x + 33, pos_ath.y - 20});
	case 1548:
		return ((sfVector2f) {pos_ath.x + 33, pos_ath.y - 55});
	default:
		return (pos_ath);
	}
}

void manage_window_resize(sfRenderWindow *window, player_t *player,
sfEvent event)
{
	sfView *view = sfView_createFromRect((sfFloatRect) {
		0., 0., event.size.width, event.size.height});

	sfView_setCenter(view, sfSprite_getPosition(player->sprite));
	sfRenderWindow_setView(window, view);
}

static sfVector2f get_smallest_spells_blank_pos(sfVector2f points[4],
int nbr, sfVector2u pos)
{
	if (pos.x == 932)
		points[nbr].y += 122;
	if (pos.x == 1036)
		points[nbr].y += 76;
	if (pos.x == 1152)
		points[nbr].y += 25;
	return (points[nbr]);
}

sfVector2f get_pos_spells_blank_hud(sfRenderWindow *window,
player_t *player, int nbr)
{
	sfVector2u pos = sfRenderWindow_getSize(window);
	sfVector2f pos_player = sfSprite_getPosition(player->sprite);
	sfVector2f points[4] = {
		POS_SPELLS_VERTICE_1,
		POS_SPELLS_VERTICE_2,
		POS_SPELLS_VERTICE_3,
		POS_SPELLS_VERTICE_4,
	};

	if (pos.x == 1408) {
		points[nbr].y -= 40;
		return (points[nbr]);
	}
	if (pos.x == 1548) {
		points[nbr].y -= 80;
		return (points[nbr]);
	}
	return (get_smallest_spells_blank_pos(points, nbr, pos));
}

int get_selected_skill(sfVector2u size, sfVector2f clic)
{
	int i = -1;
	const sfVector2f points_array[8] = {point1, point2, point5, point7,
		point8, point3, point4, point6};

	for (int j = 0; j < ARRAY_SIZE(points_array); j++)
		i = mouse_in_rect(clic, MAP_TRUE_COORDS(points_array[j],
		size), hitbox) ? j : i;
	return (i);
}
