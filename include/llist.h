/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** llist.h
*/

#include "structs.h"

#pragma once

void add_fireball(maps_t *maps, player_t *player);
void add_mult_dir_fireball(maps_t *maps, player_t *player);
void add_tri_fireball(maps_t *maps, player_t *player);
void add_object(maps_t *maps, int value, sfVector2f pos);
void add_monster(maps_t *maps, sfVector2f pos, int value);
void remove_fireballs(llist_fireball_t *entry, fireball_t *to_remove);
void remove_object(llist_objects_t *entry, objects_t *to_remove);
void remove_monster(llist_monsters_t *entry, monster_t *to_remove);
void add_item(player_t *player, int id);
void remove_item(llist_item_t *entry, item_t *to_remove);
void destroy_fireball(fireball_t *iter, fireball_t *to_remove);
void add_new_wave(sfRenderWindow *window, maps_t *maps, player_t *player);
