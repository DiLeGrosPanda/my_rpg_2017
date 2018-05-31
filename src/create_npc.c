/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to init the whole map
*/

#include "my.h"

static const char *const dialogues_npc_1[] = {
	"Please help our priest killing this monsters !",
	"Go go go ! We trust in you !",
	"Did you talk to our priest ? He's really clever !",
};
static const char *const dialogues_npc_2[] = {
	"We're both priest followers !",
	"You are going to help us, right ?",
	"Huh, you look so strong !\n... But be carefull, they hurt",
};
static const char *const dialogues_npc_3[] = {
	"Fight them to improve yourself over and over !",
	"Are you strong enought ? I think you are. Are you ?",
	"You have my blessing !",
};
static const char *const dialogues_npc_4[] = {
	"There was a time i was human too..",
	"They disrupt nature's laws. Look around you !",
	"I wish you good luck, stranger !",
};
static const char *const *const dialogues_npc[] = {
	dialogues_npc_1,
	dialogues_npc_2,
	dialogues_npc_3,
	dialogues_npc_4,
};

npc_t *create_npc(npc_t *npc, objects_t *obj, int i)
{
	npc->sprite = obj->sprite;
	npc->pos = sfSprite_getPosition(npc->sprite);
	if (obj->value != 31) {
		npc->pos.y -= 32;
		npc->hitbox = (sfVector2f) {32, 96};
	} else {
		npc->hitbox = (sfVector2f) {64, 64};
	}
	npc->pos.y -= 16;
	npc->near_player = -1;
	npc->dialogues = dialogues_npc[i];
	return (npc);
}

void fill_npc(maps_t *maps)
{
	int i = 0;

	for (objects_t *obj = maps->llist_objects->first; obj; obj = obj->next)
		if (obj->value == 255 || obj->value == 435 || obj->value == 507
			|| obj->value == 363)
			i++;
	maps->npc = malloc(sizeof(npc_t *) * (i + 1));
	i = 0;
	for (objects_t *obj = maps->llist_objects->first; obj; obj = obj->next)
		if (obj->value == 255 || obj->value == 435 || obj->value == 507
		|| obj->value == 363) {
			maps->npc[i] = create_npc(malloc(sizeof(npc_t)),
			obj, i);
			i++;
		}
	maps->npc[i] = NULL;
}
