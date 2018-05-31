/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** move.h
*/

#pragma once

#include "structs.h"

void move_ennemy_to_player(maps_t *, player_t *, monster_t *, sfVector2f *);
void move_mage(maps_t *, player_t *, sfVector2f *, monster_t *);
void reset_monster_sprite(monster_t *);
void pick_random_move(monster_t *iter, sfVector2f *);
int check_all_ennemy_collisions(maps_t *, monster_t *, sfVector2f );
void get_ennemy_random_move(monster_t *, sfVector2f *);
int get_inverse_move(monster_t *, objects_t *iter, sfVector2f *);
void move_ennemy_sprite(player_t *, maps_t *, monster_t *, float seconds);
void reset_monster_sprite(monster_t *);
void pick_random_move(monster_t *iter, sfVector2f *);
void move_fireball(player_t *, maps_t *, float seconds);
void move_ennemy(player_t *, maps_t *, float seconds);
