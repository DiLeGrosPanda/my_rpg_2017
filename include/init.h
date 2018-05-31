/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** init.h
*/

#pragma once

void fill_maps_values(maps_t *maps);
void fill_sprite_array(maps_t *maps);
void fill_npc(maps_t *maps);
void fill_render_states(maps_t *maps);
void get_maps(void);
int *resolve_line(char *line);
int get_state(sfRenderWindow *window, int state, char key_binding[SPELL_NBR]);
int init_maps(maps_t *maps);
int init_player(player_t *player, sfRenderWindow *window,
char key_binding[SPELL_NBR]);
void init_ath(ath_t *ath, player_t *player);
int how_to_play(sfRenderWindow *window);
