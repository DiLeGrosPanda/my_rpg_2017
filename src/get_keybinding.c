/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Menu management
*/

#include "my.h"
#include <assert.h>

static void manage_interection(sfRenderWindow *window, sfSprite *sprite,
	int *button, sfEvent event)
{

	if (event.type == sfEvtMouseButtonReleased) {
		sfIntRect rect = sfSprite_getTextureRect(sprite);
		if (*button <= -4) {
			rect.left -= 800;
			sfSprite_setTextureRect(sprite, rect);
			*button = -2;
		}
	}
	if (event.type == sfEvtMouseMoved)
		switch_state_button_resize(window, sprite, button);
}

static void manage_settings_event(sfRenderWindow *window, sfSprite *sprite,
		int *button, char key_binding[SPELL_NBR])
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtKeyPressed && SF_KEY == sfKeyEscape) {
			*button = -1;
			return;
		}
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type == sfEvtKeyPressed &&
				*button != -2)
			key_binding[*button] = SF_KEY;
		if (event.type == sfEvtMouseButtonPressed) {
			check_keybinding_button_clicked(button,
				key_binding, window);
			check_resize_buttons_clicked(window,
				button, sprite);
		}
		manage_interection(window, sprite, button, event);
	}
}

void load_key(char key_binding[SPELL_NBR])
{
	int fd = open("config.rpg", O_RDONLY);

	if (fd == -1)
		return;
	read(fd, key_binding, sizeof(char) * SPELL_NBR);
}

void get_settings_loop(sfSprite *sprite_key, sfSprite *sprite_size,
	sfRenderWindow *window, char key_binding[SPELL_NBR])
{
	int selected_button = -2;

	while (sfRenderWindow_isOpen(window) && selected_button != -1) {
		manage_settings_event(window,
			sprite_size, &selected_button, key_binding);
		sfRenderWindow_clear(window, sfWhite);
		sfRenderWindow_drawSprite(window, sprite_key, NULL);
		sfRenderWindow_drawSprite(window, sprite_size, NULL);
		display_keys(window, key_binding);
		sfRenderWindow_display(window);
		assert(selected_button < SPELL_NBR);
	}
	sfSprite_destroy(sprite_key);
	sfSprite_destroy(sprite_size);
}

int get_settings(sfRenderWindow *window, int button_clicked,
		char key_binding[SPELL_NBR])
{
	sfSprite *sprite_key;
	sfTexture *texture_key;
	sfSprite *sprite_size;
	sfTexture *texture_size;

	if (button_clicked != 1)
		return (-1);
	sprite_key = sfSprite_create();
	texture_key = sfTexture_createFromFile(PATH_KEYBINDIG, sfFalse);
	sfSprite_setTexture(sprite_key, texture_key, sfFalse);
	sprite_size = sfSprite_create();
	texture_size = sfTexture_createFromFile(PATH_RESIZE, sfFalse);
	sfSprite_setTexture(sprite_size, texture_size, sfFalse);
	sfSprite_setTextureRect(sprite_size, (sfIntRect) {0, 0, 400, 280});
	sfSprite_setPosition(sprite_size, (sfVector2f) {525, 0});
	get_settings_loop(sprite_key, sprite_size, window, key_binding);
	sfTexture_destroy(texture_key);
	sfTexture_destroy(texture_size);
	return (-1);
}
