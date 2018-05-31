/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** pos.h
*/

#pragma once

#define POS_SPELLS_X (pos_player.x - 240)
#define POS_SPELLS_Y (pos_player.y + pos.y / 2 - 150)
#define POS_SPELLS_VERTICE_1 (sfVector2f) {POS_SPELLS_X, POS_SPELLS_Y}
#define POS_SPELLS_VERTICE_2 (sfVector2f) {POS_SPELLS_X + (375 * 2.)\
, POS_SPELLS_Y}
#define POS_SPELLS_VERTICE_3 (sfVector2f) {POS_SPELLS_X + (375 * 2.)\
, POS_SPELLS_Y + (75 * 2.)}
#define POS_SPELLS_VERTICE_4 (sfVector2f) {POS_SPELLS_X, POS_SPELLS_Y +\
(75 * 2.)}
#define FIRST_PNJ_POS {970, 600}
#define POINT_Z (sfVector2f) {700, 250}
