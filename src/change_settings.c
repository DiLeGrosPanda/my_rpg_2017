/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Menu management
*/

#include "my.h"
#include <assert.h>

void display_keys(sfRenderWindow *window, char key_binding[SPELL_NBR])
{
	sfFont *font = sfFont_createFromFile("sprites/arial.ttf");
	sfVector2f text_pos = {348, 197};
	sfText *text = sfText_create();
	char space_key[] = "SPACE";
	char key[2] = {0};
	int offset = 75;

	sfText_setColor(text, sfBlack);
	sfText_setFont(text, font);
	for (int i = 0; i < SPELL_NBR; i++) {
		key[0] = key_binding[i] + 'A';
		sfText_setString(text, key_binding[i] == sfKeySpace ?
		space_key : key);
		sfText_setPosition(text, key_binding[i] == sfKeySpace ?
		(sfVector2f) {text_pos.x - 35, text_pos.y} : text_pos);
		sfRenderWindow_drawText(window, text, NULL);
		text_pos.y += offset;
	}
	sfText_destroy(text);
	sfFont_destroy(font);
}

void check_resize_buttons_clicked(sfRenderWindow *window,
		int *selected_button, sfSprite *sprite)
{
	sfVector2u size = sfRenderWindow_getSize(window);
	sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window,
			sfMouse_getPositionRenderWindow(window),
			sfRenderWindow_getView(window));

	if (HIT_FIRST_RESIZE_BUTTON) {
		*selected_button = -4;
		sfSprite_setTextureRect(sprite, BUTTON_RESIZE_1_HIT);
		size = (sfVector2u) {size.x * 0.9, size.y * 0.9};
		if (size.y >= 699)
			sfRenderWindow_setSize(window, size);
	}
	if (HIT_SECOND_RESIZE_BUTTON) {
		*selected_button = -5;
		sfSprite_setTextureRect(sprite, BUTTON_RESIZE_2_HIT);
		size = (sfVector2u) {size.x * 1.1, size.y * 1.1};
		if (size.y <= 1161)
			sfRenderWindow_setSize(window, size);
	}
}

void check_keybinding_button_clicked(int *selected_button,
		char key_binding[SPELL_NBR],
		sfRenderWindow *window)
{
	sfVector2f button_pos = {335, 195};
	int hitbox = 40;
	int offset = 75;
	sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window,
			sfMouse_getPositionRenderWindow(window),
			sfRenderWindow_getView(window));

	for (int i = 0; i < SPELL_NBR; i++) {
		if (mouse.x > button_pos.x &&
				mouse.x < button_pos.x + hitbox &&
				mouse.y > button_pos.y &&
				mouse.y < button_pos.y + hitbox) {
			*selected_button = i;
			key_binding[i] = '\0' - 'A';
		}
		button_pos.y += offset;
	}
}

void switch_state_button_resize(sfRenderWindow *window, sfSprite *sprite,
		int *selected_button)
{
	sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window,
			sfMouse_getPositionRenderWindow(window),
			sfRenderWindow_getView(window));

	*selected_button = -3;
	if (HIT_FIRST_RESIZE_BUTTON)
		sfSprite_setTextureRect(sprite, BUTTON_RESIZE_1_HOVER);
	else if (HIT_SECOND_RESIZE_BUTTON)
		sfSprite_setTextureRect(sprite, BUTTON_RESIZE_2_HOVER);
	else
		sfSprite_setTextureRect(sprite, BUTTON_RESIZE_STANDART);
}
