/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** my.h
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include "buttons.h"
#include "get_next_line.h"
#include "mygraph.h"
#include "mmy.h"
#include "values.h"

typedef struct dialogue_quest_s dialogue_quest_t;
typedef struct spells_s spells_t;
typedef struct player_s player_t;

typedef enum move {
	BOT = 0,
	LEFT = 1,
	RIGHT = 2,
	TOP = 3,
} move_t;

typedef struct s_info
{
	sfVector2f speed;
	float life;
} t_info;

typedef struct s_partbuffer
{
	sfVertex *vertex;
	t_info *info;
	uint size;
} partbuffer;

typedef struct item_s {
	int id;
	struct item_s *next;
} item_t;

typedef struct objects_s {
	int life;
	int value;
	sfSprite *sprite;
	sfVector2f pos;
	struct objects_s *next;
} objects_t;

typedef struct llist_item_s {
	sfSprite *sprite;
	sfTexture *none;
	sfTexture *base;
	item_t *first;
	item_t *last;
} llist_item_t;

typedef struct llist_objects_s {
	objects_t *first;
	objects_t *last;
} llist_objects_t;

typedef struct fireball_s {
	sfVector2f dest;
	sfVector2f move;
	sfSprite *sprite;
	struct fireball_s *next;
	float sprite_timer;
	sfSound *sound;
	partbuffer *buffer;
} fireball_t;

typedef struct lightning_s {
	sfVector2f pos;
	sfIntRect rect;
	float pre_show_atk;
	int is_active;
	float count_display;
} lightning_t;

typedef struct llist_fireball_s {
	sfTexture *texture;
	sfSprite *sprite;
	fireball_t *first;
	fireball_t *last;
	lightning_t lightning[LIGHTNING_NBR_MAX];
	sfSoundBuffer *sound_buffer;
	sfSound *sound;
} llist_fireball_t;

typedef struct monster_s {
	int life;
	float cd_attack;
	sfIntRect rect;
	sfSprite *sprite;
	sfVector2f pos;
	struct monster_s *next;
} monster_t;

typedef struct llist_monsters_s {
	monster_t *first;
	monster_t *last;
	float seconds;
} llist_monsters_t;

typedef struct npc_s {
	sfSprite *sprite;
	sfVector2f pos;
	sfVector2f hitbox;
	int near_player;
	int to_display;
	const char *const *dialogues;
} npc_t;

typedef struct skill_point_s {
	sfVector2f pos;
	int previous;
} skill_point_t;

typedef struct skill_tree_s {
	int is_active;
	int skills_point;
	int unlocked[8];
} skill_tree_t;

typedef struct dialogue_s {
	sfText *text;
	sfFont *font;
	sfTexture *texture;
	sfSprite *sprite;
} dialogue_t;

typedef struct ath_s {
	dialogue_t dialogue;
	sfTexture *ath_base;
	sfShader *shader;
	sfRenderStates states;
	sfVertexArray *array;
	skill_tree_t skill_tree;
} ath_t;

typedef struct maps_s {
	int game_open;
	sfTexture *texture_full;
	sfTexture *texture_array[SPRITE_BG_NBR];
	sfSprite *sprite_array[SPRITE_BG_NBR];
	sfSoundBuffer *fire_sound;
	llist_objects_t *llist_objects;
	llist_fireball_t *llist_fireball;
	llist_monsters_t *llist_monsters;
	npc_t **npc;
	sfVertexArray *array_bg;
	sfRenderStates states;
} maps_t;

struct dialogue_quest_s {
	const char *path;
	const char *dialogue;
	const dialogue_quest_t *const next;
};

typedef struct quests_s {
	char *content;
	int states[2];
	int resolved;
	const dialogue_quest_t const *dialogue;
} quests_t;

typedef struct dialogues_display_s {
	const dialogue_quest_t *iter;
	sfTexture *texture;
	sfTexture *texture_bg;
	sfSprite *sprite;
	sfSprite *sprite_bg;
	float seconds;
	sfClock *clock;
} dialogue_display_t;

struct spells_s {
	int unlocked;
	float iter_timer;
	float cd_time;
	char key;
	void (*fnptr)(sfRenderWindow*, maps_t*, struct player_s*, float);
	sfTexture *texture;
	sfSprite *sprite;
};

struct player_s {
	int golds;
	int life;
	int life_max;
	int movement_speed;
	int attack_dmg;
	float xp;
	float fireball_cooldown;
	float dmg_cooldown;
	float seconds;
	move_t move;
	int is_moving;
	int sprite_count;
	int monster_killed;
	sfView *view;
	sfSprite *sprite;
	partbuffer *buffer;
	sfTexture *texture;
	spells_t spells[SPELL_NBR];
	int is_buffed;
	sfShader *shader;
	sfRenderStates states;
	quests_t quests[4];
	ath_t *ath;
	llist_item_t *llist_item;
	sfMusic *music;
};
