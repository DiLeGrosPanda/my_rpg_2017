/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** display.h
*/

#include "structs.h"

#pragma once

void draw_objects_and_monsters(sfRenderWindow *, maps_t *, player_t *);
void draw_fireballs(sfRenderWindow *, maps_t *);
void draw_lightning(sfRenderWindow *, player_t *, float);
void draw_background(sfRenderWindow *, maps_t *);
void draw_player(sfRenderWindow *, player_t *, float);
void draw_npc(sfRenderWindow *, player_t *, maps_t *);
void draw_ath(sfRenderWindow *, player_t *, ath_t *, float);
void display_dialogue_quest(sfRenderWindow *, player_t *);
void display_inventory(sfRenderWindow *, player_t *);
void display_player_infos(sfRenderWindow *, player_t *);
void display_lightning(sfRenderWindow *, maps_t *, player_t *, float);
void add_monsters_to_vertex_array(sfVertexArray *, maps_t *, player_t *);
void add_fireball_to_vertex_array(sfVertexArray *, maps_t *);
void add_ath_to_vertex_array(sfVertexArray *, player_t *);
void add_objects_to_vertex_array(sfVertexArray *, maps_t *, player_t *);
void add_spells_to_vertex_array(sfRenderWindow *, sfVertexArray *,
player_t *, float);
void add_spells_to_vertex_array(sfRenderWindow *, sfVertexArray *,
player_t *, float);
void add_skill_tree_to_vertex_array(sfRenderWindow *, const sfTexture *);
void display_dialogue(sfRenderWindow *window, player_t *player,
dialogue_display_t *dial);
void add_help_skill_tree(sfRenderWindow *, ath_t *, sfVertexArray *);
int get_selected_skill(sfVector2u size, sfVector2f clic);
void display_dialogue_quest(sfRenderWindow *window, player_t *player);
void display_skill_tree(sfRenderWindow *, ath_t *, player_t *, sfView const *);
void display_skills_point(sfRenderWindow *, player_t *, sfText *);
