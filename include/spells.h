/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** spells.h
*/

#include "structs.h"

#pragma once

void simple_fireball(sfRenderWindow *, maps_t *, player_t *, float);
void multi_fireballs(sfRenderWindow *, maps_t *, player_t *, float);
void multi_fireballs(sfRenderWindow *, maps_t *, player_t *, float);
void multi_dir_fireballs(sfRenderWindow *, maps_t *, player_t *, float);
void buff_player(sfRenderWindow *, maps_t *, player_t *, float);
void use_lightning(sfRenderWindow *, maps_t *, player_t *, float);
void debuff_player(player_t *player, float seconds);
void heal_player(player_t *player, float amount);
void xp_player(player_t *player, float amount);
void reset_skill_tree(player_t *player);
