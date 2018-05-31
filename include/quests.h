/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** quests.h
*/

#include "structs.h"

#pragma once

void check_quests(sfRenderWindow *, maps_t *maps, player_t *player);
void display_quest(sfRenderWindow *, player_t *, sfSprite *, int);
void spawn_object(maps_t *maps, sfVector2f pos);
void talk_npc(player_t *player, maps_t *maps);
void player_kill_monster(player_t *player, maps_t *maps, monster_t *monster);
