/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file
*/

#include "my.h"

static const int fps_max = 60;

void print_fps(float seconds)
{
        static float elapsed_time;
        static int fps;

        fps++;
        if (seconds + 5 < elapsed_time)
                elapsed_time = seconds;
        if (seconds < elapsed_time + 1)
                return;
        printf("FPS: %d/%d\n", fps, fps_max);
        fps = 0;
        elapsed_time = seconds;
}

void display_game(sfRenderWindow *window, maps_t *maps, player_t *player,
ath_t *ath)
{
	float seconds = maps->llist_monsters->seconds;
	sfIntRect rect = {0};

	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawVertexArray(window, maps->array_bg, &(maps->states));
	draw_objects_and_monsters(window, maps, player);
	for (fireball_t *tmp = maps->llist_fireball->first; tmp;
		tmp = tmp->next)
		update(window, tmp);
	draw_fireballs(window, maps);
	draw_lightning(window, player, seconds);
	display_lightning(window, maps, player, seconds);
	sfSprite_setTextureRect(player->spells[4].sprite, rect);
	draw_ath(window, player, ath, seconds);
	draw_npc(window, player, maps);
	draw_player(window, player, (int) seconds);
	update_lightning(window, player);
	sfRenderWindow_display(window);
}

void play_game_loop(sfRenderWindow *window, maps_t *maps, player_t *player,
ath_t *ath)
{
	float seconds = maps->llist_monsters->seconds;

	if (player->life > player->life_max)
		player->life = player->life_max;
	if (maps->game_open == 2)
		sfRenderWindow_close(window);
	if (!sfRenderWindow_isOpen(window) || maps->game_open == 1)
		return;
	for (monster_t *tmp = maps->llist_monsters->first; tmp; tmp = tmp->next)
		tmp->pos = sfSprite_getPosition(tmp->sprite);
	for (objects_t *tmp = maps->llist_objects->first; tmp; tmp = tmp->next)
		tmp->pos = sfSprite_getPosition(tmp->sprite);
	print_fps(seconds);
	display_game(window, maps, player, ath);
	move_fireball(player, maps, seconds);
	move_ennemy(player, maps, seconds);
	move_player(seconds, player, window, maps);
	check_collisions_player_ennemy(player, maps, seconds);
	check_quests(window, maps, player);
}

int init_myrpg(sfRenderWindow *window, char key_binding[SPELL_NBR],
sfClock *clock, float seconds)
{
	ath_t ath = {0};
	maps_t maps = {0};
	player_t player = {0};

	if (init_maps(&maps) || init_player(&player, window, key_binding))
		return (84);
	init_ath(&ath, &player);
	display_dialogue_quest(window, &player);
	display_quest(window, &player, sfSprite_create(), 1);
	while (sfRenderWindow_isOpen(window) && player.life > 0 &&
	maps.game_open != 1) {
		manage_events(window, &maps, &player, seconds);
		seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.;
		maps.llist_monsters->seconds = seconds;
		manage_events(window, &maps, &player, seconds);
		play_game_loop(window, &maps, &player, &ath);
		add_new_wave(window, &maps, &player);
	}
	check_lost(window, &player);
	clean_ressources(&ath, &maps, &player);
	return (0);
}

int play_game(sfRenderWindow *window, sfClock *clock,
char key_binding[SPELL_NBR])
{
	int result = 0;
	int state = 0;

	while (sfRenderWindow_isOpen(window) && result == 0) {
		state = menu(window, key_binding, get_menu_textures(), -1);
		if (state == 0)
			result = init_myrpg(window, key_binding, clock, 0);
		else if (state == 1)
			sfRenderWindow_close(window);
	}
	return (result);
}

int main(void)
{
	sfRenderWindow *window = sfRenderWindow_create((sfVideoMode) {WIN_WIDTH,
		WIN_HEIGHT, 32}, "SFML", sfClose, NULL);
	char key_binding[SPELL_NBR] = {
		sfKeySpace, sfKeyZ, sfKeyE, sfKeyR, sfKeyQ
	};
	sfClock *clock = sfClock_create();
	int result = 0;

	if (!window || !clock || !check_ressources_enable())
		return (84);
	sfRenderWindow_setFramerateLimit(window, fps_max);
	load_key(key_binding);
	srand(time(NULL));
	my_intro(window);
	result = play_game(window, clock, key_binding);
	sfClock_destroy(clock);
	sfRenderWindow_destroy(window);
	save_key(key_binding);
	return (result);
}
