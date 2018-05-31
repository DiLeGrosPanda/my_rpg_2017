/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** tools.h
*/

#include "structs.h"

#pragma once

#define UNUSED __attribute__((unused))
#define ABS(x) (x < 0 ? x * -1 : x)
#define ARRAY_SIZE(x) (int) (sizeof(x) / sizeof(*x))
#define SF_KEY event.key.code
#define MOUSE_POS event.mouseButton
#define cons(x, y, z) (const dialogue_quest_t[]){{x, y, z}}
#define DISTANCE_PLAYER_ENNEMY(player, monster) sqrt((monster.x - player.x) *\
(monster.x - player.x) + (monster.y - player.y) * (monster.y - player.y))
#define GET_CLIC_POS(window) {sfMouse_getPositionRenderWindow(window).x\
, sfMouse_getPositionRenderWindow(window).y}
#define POS_PLAYER sfSprite_getPosition(player->sprite)
#define IS_GOBELIN(x) ((x >= 180 && x < 183) || (x >= 216 && x < 219)\
|| (x >= 252 && x < 255) || (x >= 288 && x < 291))
#define IS_SOLDIER(x) ((x >= 324 && x < 327) || (x >= 360 && x < 363)\
|| (x >= 396 && x < 399) || (x >= 432 && x < 435))
#define IS_MAGE(x) ((x >= 468 && x < 471) || (x >= 504 && x < 507) ||\
(x >= 540 && x < 543) || (x >= 576 && x < 579))
#define _IS_MAGE(monster) sfSprite_getTextureRect(monster->sprite).top\
>= 13 * 32 && sfSprite_getTextureRect(monster->sprite).top < 17 * 32
#define LIGHTNING_ITEM maps->llist_fireball->lightning[i]
#define GET_PERCENT_CD (((seconds - player->spells[i].iter_timer) /\
player->spells[i].cd_time * 85))
#define PERCENT_CD (GET_PERCENT_CD > 100 ? 0 : 1 - GET_PERCENT_CD / 100)

int display_error(const char *file, const char *func, int line);
void clean_ressources(ath_t *ath, maps_t *maps, player_t *player);
int check_ressources_enable(void);
int get_quest_nbr(player_t *player);
void sound_fireball(fireball_t *new, maps_t *maps, sfVector2f pos);
void load_key(char key_binding[SPELL_NBR]);
void save_key(char key_binding[SPELL_NBR]);
int check_distance(sfVector2f un, sfVector2f deux, int dist);
void print_player_infos(player_t *);
void move_player(float, player_t *, sfRenderWindow *, maps_t *);
void update_player_dir(sfEvent, player_t *);
void check_lost(sfRenderWindow *, player_t *);
sfTexture **get_inventory_textures(sfRenderWindow *, button_t ***buttons);
