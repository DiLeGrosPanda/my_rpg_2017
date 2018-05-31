/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to create base structs
*/

#include "my.h"

static const char *const intro[] = {"Once upon a time, there were a world "
	"where war does not exist...\nHumans where living peacefully, "
	"with nothing to be woried about...",
	"But one night, Humans were attacked by Orcs....",
	"Their villages went up in flames....",
	"And the villagers where killed...",
	"Some villagers take their weapon to fight back...\n"
	"You are one of them, fighting for the Human freedom.",
	NULL
};

textures_t *get_menu_textures(void)
{
	textures_t *textures = malloc(sizeof(textures_t));

	textures->buttons = sfTexture_createFromFile(PATH_BUTTONS, NULL);
	textures->village = sfTexture_createFromFile(PATH_VILLAGE, NULL);
	textures->villager = sfTexture_createFromFile(PATH_VILLAGER, NULL);
	textures->village_burning = sfTexture_createFromFile(PATH_BURN, NULL);
	textures->fire = sfTexture_createFromFile(PATH_FIRE, NULL);
	textures->orc = sfTexture_createFromFile(PATH_ORC, NULL);
	return (textures);
}

void destroy_blur_text(blur_text_t *text)
{
	sfText_destroy(text->text);
	sfFont_destroy(text->font);
	sfClock_destroy(text->clock);
	free(text);
}

blur_text_t *new_blur_text(sfVector2f pos, const char * const str,
float times[4], sfColor color)
{
	blur_text_t *text = malloc(sizeof(blur_text_t));

	text->font = sfFont_createFromFile("sprites/arial.ttf");
	text->text = sfText_create();
	text->clock = sfClock_create();
	for (int i = 0; i < 4; i = i + 1)
		text->times[i] = times[i];
	sfText_setString(text->text, str);
	sfText_setColor(text->text, color);
	sfText_setPosition(text->text, pos);
	sfText_setFont(text->text, text->font);
	sfText_setCharacterSize(text->text, 32);
	return (text);
}

blur_text_t **get_intro_texts(void)
{
	sfVector2f pos[] = {{20, 850}, {20, 850}, {20, 850}, {20, 900},
		{20, 850}};

	float times[][4] = {{0, 1, 3, 1}, {5, 1, 1, 1}, {8, 1, 2, 1},
		{9, 1, 1, 1}, {12, 1, 4, 1}};
	sfColor color[] = {sfWhite, sfWhite, sfWhite, sfWhite, sfWhite};
	blur_text_t **texts = NULL;

	for (int i = 0; intro[i] != NULL; i = i + 1)
		realloc_tab((void ***)&texts, new_blur_text(pos[i],
		intro[i], times[i], color[i]));
	return (texts);
}
