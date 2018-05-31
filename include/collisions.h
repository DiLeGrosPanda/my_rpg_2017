/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** collisions.h
*/

#include "structs.h"

#pragma once

short collision(sfIntRect box1, sfIntRect box2);
short mouse_in_rect(sfVector2f mouse, sfVector2f target, sfVector2f hitbox);
int check_collision_bdf_objects(maps_t *maps, fireball_t *iter);
int check_collision_bdf_monsters(player_t *, maps_t *, fireball_t *);
void check_lightning_hit(sfRenderWindow *window, maps_t *maps, player_t *);
int check_collision_ennemy_decor(const monster_t * const monster,
const objects_t * const iter, sfVector2f move);
int check_collision_ennemy_ennemy(monster_t *un, monster_t *deux, sfVector2f);
int check_collision_player_objects(player_t *player, maps_t *, sfIntRect rect);
int check_collisions_player_ennemy(player_t *player, maps_t *maps, float);
