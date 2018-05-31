/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Menu management
*/

#include "my.h"

void menu_hoover(sfMouseMoveEvent event, button_t **buttons,
sfRenderWindow *window, int offset)
{
	sfVector2f pos = {event.x, event.y};
	sfIntRect rect;

	if (buttons == NULL)
		return;
	for (int i = 0; buttons[i] != NULL; i = i + 1) {
		rect = sfRectangleShape_getTextureRect(buttons[i]->rect);
		rect.left = offset;
		if (button_is_clicked(buttons[i], pos, window))
			sfRectangleShape_setTextureRect(buttons[i]->rect,
			rect);
		else
			sfRectangleShape_setTextureRect(buttons[i]->rect,
			(sfIntRect) {0, rect.top, rect.width, rect.height});
	}
}

int menu_click(sfMouseButtonEvent event, button_t **buttons,
sfRenderWindow *window)
{
	sfVector2f pos = {event.x, event.y};
	int status = -1;

	if (buttons == NULL)
		return (0);
	for (int i = 0; buttons[i] != NULL; i = i + 1) {
		if (button_is_clicked(buttons[i], pos, window))
			status = (buttons[i])->callback(buttons[i]->id);
	}
	return (status);
}

void menu_event(sfRenderWindow *window, int *state, button_t **buttons)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event))
		switch (event.type) {
		case sfEvtClosed:
			sfRenderWindow_close(window);
			break;
		case sfEvtMouseButtonPressed:
			*state = menu_click(event.mouseButton, buttons, window);
			break;
		case sfEvtMouseMoved:
			menu_hoover(event.mouseMove, buttons, window, 404);
			break;
		case sfEvtResized:
			sfRenderWindow_setSize(window,
			manage_resize(window, event));
			break;
		default:
			break;
		}
}

void destroy_menu(button_t **buttons, textures_t *textures)
{
	if (buttons != NULL) {
		for (int i = 0; buttons[i] != NULL; i = i + 1) {
			sfRectangleShape_destroy(buttons[i]->rect);
			free(buttons[i]);
		}
		free(buttons);
	}
	if (textures != NULL) {
		sfTexture_destroy(textures->buttons);
		sfTexture_destroy(textures->village);
		sfTexture_destroy(textures->village_burning);
		sfTexture_destroy(textures->fire);
		sfTexture_destroy(textures->orc);
		sfTexture_destroy(textures->villager);
		free(textures);
	}
}

int menu(sfRenderWindow *window, char key_binding[SPELL_NBR],
textures_t *textures, int state)
{
	button_t **buttons = get_menu_buttons(textures);
	sfView const *view = sfRenderWindow_getDefaultView(window);
	sfView const *keep = sfRenderWindow_getView(window);

	sfRenderWindow_setView(window, view);
	while (sfRenderWindow_isOpen(window) && state != 3 && state != 0) {
		menu_event(window, &state, buttons);
		sfRenderWindow_clear(window, sfBlack);
		display_res(window, (sfVector2f) {0, 150}, textures->village,
		sfWhite);
		for (int i = 0; buttons[i] != NULL; i = i + 1)
			sfRenderWindow_drawRectangleShape(window,
			buttons[i]->rect, NULL);
		sfRenderWindow_display(window);
		state = get_state(window, state, key_binding);
	}
	sfRenderWindow_setView(window, keep);
	destroy_menu(buttons, textures);
	return (state == 0 ? 0 : 1);
}
