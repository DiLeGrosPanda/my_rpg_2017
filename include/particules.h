/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** particules.h
*/

#include "structs.h"

#pragma once

partbuffer *init(void);
partbuffer *new_part_buffer(int size);
uint new_part(partbuffer *this);
void set_part(partbuffer *this, uint id, sfVector2f pos, sfColor color);
void update(sfRenderWindow *window, fireball_t *fireball);
void update_lightning(sfRenderWindow *window, player_t *player);
void update_part_buffer_lightning(partbuffer *this);
void update_part_buffer(partbuffer *this);
void create_lightning_particules(sfRenderWindow *, player_t *player, int i);
void draw_part_buffer(partbuffer *this, sfRenderWindow *window);
void draw_part_buffer_lightning(partbuffer *this, sfRenderWindow *window);
