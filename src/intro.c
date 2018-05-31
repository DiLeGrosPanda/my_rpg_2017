/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Intro
*/

#include "my.h"

static float get_text_ratio(blur_text_t **text, int i, float time)
{
	if (text[i]->times[0] < time && text[i]->times[1] + text[i]->times[0]
	> time) {
		return ((time - text[i]->times[0]) * 255.0 /
		(text[i]->times[1]) / 255.0);
	} else if (text[i]->times[0] + text[i]->times[1] < time &&
	text[i]->times[2] + text[i]->times[1] +
	text[i]->times[0] > time) {
		return (1);
	} else {
		if (text[i]->times[2] + text[i]->times[1] + text[i]->times[0] <
		time && text[i]->times[3] + text[i]->times[2] +
		text[i]->times[1] + text[i]->times[0] > time) {
			return ((time - text[i]->times[2] - text[i]->times[1] -
			text[i]->times[0]) * 255.0 /
			(text[i]->times[3]) / 255.0 + 1);
		} else {
			return (0);
		}
	}
}

static void display_texts(sfRenderWindow *window, blur_text_t **text)
{
	float time;
	float ratio;
	sfColor col = sfWhite;

	for (int i = 0; text[i] != NULL; i = i + 1) {
		time = sfTime_asSeconds(sfClock_getElapsedTime(text[i]->clock));
		ratio = get_text_ratio(text, i, time);
		col.a = (ratio <= 1 ? 255 * ratio : 255 * (2 - ratio));
		sfText_setColor(text[i]->text, col);
		if (col.a != 0)
			sfRenderWindow_drawText(window, text[i]->text, NULL);
	}
}

static void display_intro(sfRenderWindow *window, textures_t *textures,
float elapsed_time, blur_text_t **texts)
{
	sfColor colors = {255, 255, 255, 255};

	if (elapsed_time < 5.5) {
		if (elapsed_time >= 5)
			colors.a -= colors.a *
			((elapsed_time - 5) * 255 / 0.5 / 255);
		display_res(window, (sfVector2f) {0, 150}, textures->village,
		(elapsed_time < 5 ? sfWhite : colors));
	} else if (elapsed_time < 8) {
		if (elapsed_time >= 7.5)
			colors.a -= colors.a *
			((elapsed_time - 7.5) * 255 / 0.5 / 255);
		display_res(window, (sfVector2f) {0, 150}, textures->fire,
		(elapsed_time < 7.5 ? sfWhite : colors));
	} else {
		display_res(window, (sfVector2f) {0, 150},
		textures->village_burning, sfWhite);
	}
	display_texts(window, texts);
}

static int manage_intro_events(sfRenderWindow *window)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		switch (event.type) {
		case sfEvtClosed:
			sfRenderWindow_close(window);
			break;
		case sfEvtKeyPressed:
			return ((event.key.code == sfKeySpace ? 1 : 0));
		default:
			break;
		}
	}
	return (0);
}

void my_intro(sfRenderWindow *window)
{
	textures_t *textures = get_menu_textures();
	sfClock *clock = sfClock_create();
	float time = 0;
	int state = 0;
	blur_text_t **texts = get_intro_texts();

	while (sfRenderWindow_isOpen(window) && state == 0 && time < 20) {
		sfRenderWindow_clear(window, sfBlack);
		display_text(window, (sfVector2f) {20, 20},
		"Press Space to skip...", sfWhite);
		state = manage_intro_events(window);
		display_intro(window, textures, time, texts);
		sfRenderWindow_display(window);
		time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
	}
	destroy_menu(NULL, textures);
	sfClock_destroy(clock);
	for (int i = 0; texts[i] != NULL; i = i + 1)
		destroy_blur_text(texts[i]);
	free(texts);
}
