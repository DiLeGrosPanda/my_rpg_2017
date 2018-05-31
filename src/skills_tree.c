/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to manage the events
*/

#include "my.h"

static sfVector2f hitbox = {60, 60};
static skill_point_t point1 = {{500, 740}, 0};
static skill_point_t point2 = {{500, 612}, 0};
static skill_point_t point3 = {{360, 470}, 1};
static skill_point_t point4 = {{640, 470}, 1};
static skill_point_t point5 = {{356, 300}, 5};
static skill_point_t point6 = {{500, 340}, 6};
static skill_point_t point7 = {{640, 300}, 6};
static skill_point_t point8 = {{500, 200}, 7};

static void unlock_spells(sfVector2f clic, player_t *player)
{
	if (mouse_in_rect(clic, point2.pos, hitbox))
		player->spells[1].unlocked = 1;
	if (mouse_in_rect(clic, point3.pos, hitbox))
		player->movement_speed += 1;
	if (mouse_in_rect(clic, point4.pos, hitbox))
		player->life_max += 2;
	if (mouse_in_rect(clic, point5.pos, hitbox))
		player->spells[2].unlocked = 1;
	if (mouse_in_rect(clic, point6.pos, hitbox))
		for (int i = 0; i < 5; i++)
			player->spells[i].cd_time *= 0.5;
	if (mouse_in_rect(clic, point7.pos, hitbox))
		player->spells[3].unlocked = 1;
	if (mouse_in_rect(clic, point8.pos, hitbox))
		player->spells[4].unlocked = 1;
}

int manage_skill_tree_mouse2(player_t *player, int i)
{
	if (!player->ath->skill_tree.skills_point ||
	player->ath->skill_tree.unlocked[i]) {
		return (0);
	} else {
		player->ath->skill_tree.unlocked[i] = 1;
		player->ath->skill_tree.skills_point -= 1;
		return (1);
	}
	return (1);
}

int get_tree_on_spell(sfVector2f clic, sfVector2u size, player_t *player)
{
	int check = 1;
	skill_point_t points[8] = {
		point1, point2, point5, point7, point8,
		point3, point4, point6,
	};

	for (int i = 0; i < ARRAY_SIZE(points); i++)
		if (mouse_in_rect(clic, MAP_TRUE_COORDS(points[i].pos,
		size), hitbox) &&
		player->ath->skill_tree.unlocked[points[i].previous]) {
			check = manage_skill_tree_mouse2(player, i);
			break;
		} else if (i + 1 == ARRAY_SIZE(points))
			return (0);
	if (check == 0)
		return (0);
	return (1);

}

int manage_skill_tree_mouse(sfRenderWindow *window, sfEvent event,
		player_t *player)
{
	sfVector2f clic = {event.mouseButton.x, event.mouseButton.y};
	sfVector2u size = sfRenderWindow_getSize(window);

	if (!player->ath->skill_tree.is_active)
		return (0);
	if (!get_tree_on_spell(clic, size, player))
		return (0);
	unlock_spells(clic, player);
	return (1);
}

void display_skill_tree(sfRenderWindow *window, ath_t *ath, player_t *player,
		sfView const *view)
{
	sfRenderWindow_setView(window, view);
	add_skill_tree_to_vertex_array(window, (ath->states.texture));
	add_help_skill_tree(window, ath, ath->array);
	sfRenderWindow_drawVertexArray(window, ath->array,
			&(ath->states));
	sfVertexArray_clear(ath->array);
	display_skills_point(window, player, ath->dialogue.text);
}
