/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to manage the events
*/

#include "my.h"

static void (*player_spells[])(sfRenderWindow *window, maps_t*, player_t*,
float) = {
	simple_fireball,
	multi_dir_fireballs,
	multi_fireballs,
	buff_player,
	use_lightning,
};

static void manage_keyboard_key(sfRenderWindow *window, sfEvent event,
maps_t *maps, player_t *player)
{
	if (SF_KEY == sfKeyI)
		display_inventory(window, player);
	if (SF_KEY == sfKeyN)
		add_item(player, 0);
	if (SF_KEY == sfKeyB)
		add_item(player, 1);
	if (SF_KEY == sfKeyH)
		display_player_infos(window, player);
	if (SF_KEY == sfKeyF)
		display_quest(window, player, sfSprite_create(), 1);
	if (SF_KEY == sfKeyP)
		player->ath->skill_tree.is_active = 1;
	if (SF_KEY == sfKeyL)
		talk_npc(player, maps);
	if (SF_KEY == sfKeyO)
		reset_skill_tree(player);
}

static int manage_keyboard_evt(sfRenderWindow *window, sfEvent event,
maps_t *maps, player_t *player)
{
	float seconds = maps->llist_monsters->seconds;

	update_player_dir(event, player);
	if (SF_KEY == sfKeyEscape && player->ath->skill_tree.is_active) {
		player->ath->skill_tree.is_active = 0;
		return (0);
	}
	if (SF_KEY == sfKeyEscape)
		return (my_pause(window, sfRenderWindow_getView(window), -1));
	manage_keyboard_key(window, event, maps, player);
	for (int i = 0; i < SPELL_NBR; i++)
		if (SF_KEY == player->spells[i].key &&
				player->spells[i].unlocked)
			player->spells[i].fnptr(window, maps, player, seconds);
	return (0);
}

static void manage_mouse_clic(sfRenderWindow *window, player_t *player,
maps_t *maps, sfEvent event)
{
	sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords((window),
			(sfVector2i) {event.mouseButton.x, event.mouseButton.y},
			sfRenderWindow_getView(window));
	sfVector2u pos = sfRenderWindow_getSize(window);
	sfVector2f pos_player = sfSprite_getPosition(player->sprite);
	sfVector2f pos_ath = POS_SPELLS_VERTICE_1;
	sfVector2f hitbox = {70, 70};
	float seconds = maps->llist_monsters->seconds;

	pos_ath.x += 33;
	pos_ath.y += 27;
	for (int i = 0; i < SPELL_NBR; i++) {
		if (mouse_in_rect(mouse_pos, pos_ath, hitbox) &&
				player->spells[i].unlocked)
			player_spells[i](window, maps, player, seconds);
		pos_ath.x += 75;
	}
}

void manage_events(sfRenderWindow *window, maps_t *maps, player_t *player,
		float seconds)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		maps->llist_monsters->seconds = seconds;
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type == sfEvtKeyPressed)
			maps->game_open = manage_keyboard_evt(window,
					event, maps, player);
		if (event.type == sfEvtMouseButtonPressed
				&& (manage_skill_tree_mouse(window,
				event, player) || manage_ath_mouse(window,
				event, player)))
			return;
		if (event.type == sfEvtMouseButtonPressed)
			manage_mouse_clic(window, player, maps, event);
		if (event.type == sfEvtResized)
			manage_window_resize(window, player, event);
	}
}
