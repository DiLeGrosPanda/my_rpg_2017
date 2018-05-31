/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Functions to manage buttons
*/

#include "my.h"

int button_is_clicked(button_t *button, sfVector2f event,
sfRenderWindow *window)
{
	return (event.x < (sfRectangleShape_getPosition(button->rect).x +
	sfRectangleShape_getSize(button->rect).x) * ratio_x(window) &&
	event.x > sfRectangleShape_getPosition(button->rect).x *
	ratio_x(window) && event.y <
	(sfRectangleShape_getPosition(button->rect).y +
	sfRectangleShape_getSize(button->rect).y) * ratio_y(window) &&
	event.y > sfRectangleShape_getPosition(button->rect).y
	* ratio_y(window));
}

button_t *new_button(sfVector2f pos, sfVector2f size, sfTexture *texture,
int (*callback)())
{
	button_t *new_button = malloc(sizeof(button_t));
	static int id;

	if (texture == NULL) {
		id = 0;
		return (NULL);
	}
	new_button->texture = texture;
	new_button->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(new_button->rect, pos);
	sfRectangleShape_setSize(new_button->rect, size);
	sfRectangleShape_setTexture(new_button->rect, texture, 0);
	new_button->callback = callback;
	new_button->id = id;
	id = id + 1;
	return (new_button);
}

button_t **new_buttons(sfVector2f *pos, sfVector2f *size, sfTexture **textures,
int(**callbacks)())
{
	int i = 0;
	int nb = 0;
	button_t **buttons;

	for (nb = 0; textures[nb] != NULL; nb = nb + 1);
	buttons = malloc(sizeof(button_t *) * (nb + 1));
	while (textures[i] != NULL) {
		buttons[i] = new_button(pos[i], size[i], textures[i],
		callbacks[i]);
		i = i + 1;
	}
	buttons[i] = NULL;
	new_button((sfVector2f) {0, 0}, (sfVector2f) {0, 0}, NULL, NULL);
	return (buttons);
}

button_t **get_menu_buttons(textures_t *textures)
{
	sfVector2f pos[] = {{450, 300}, {450, 400}, {450, 500}, {450, 600}};
	sfVector2f size[] = {{150, 80}, {280, 70}, {400, 80}, {170, 80}};
	sfTexture *texture[] = {textures->buttons, textures->buttons,
		textures->buttons, textures->buttons, NULL};
	sfIntRect rect[] = {{0, 0, 150, 80}, {0, 90, 280, 65},
		{0, 170, 400, 80}, {0, 255, 170, 80}};
	int(*callbacks[])() = {&get_id, &get_id, &get_id, &get_id, NULL};
	button_t **buttons = new_buttons(pos, size, texture, callbacks);

	for (int i = 0; buttons[i] != NULL; i = i + 1)
		sfRectangleShape_setTextureRect(buttons[i]->rect, rect[i]);
	return (buttons);
}

button_t **get_pause_buttons(void)
{
	sfTexture *texture = sfTexture_createFromFile("sprites/pause.png", 0);
	sfVector2f pos[] = {{450, 300}, {450, 400}, {450, 500}};
	sfVector2f size[] = {{265, 70}, {472, 84}, {170, 84}};
	sfTexture *textures[] = {texture, texture, texture, NULL};
	sfIntRect rect[] = {{0, 0, 265, 70}, {0, 75, 472, 84},
		{0, 167, 170, 84}};
	int(*callbacks[])() = {&get_id, &get_id, &get_id, NULL};
	button_t **buttons = new_buttons(pos, size, textures, callbacks);

	for (int i = 0; buttons[i] != NULL; i = i + 1)
		sfRectangleShape_setTextureRect(buttons[i]->rect, rect[i]);
	return (buttons);
}
