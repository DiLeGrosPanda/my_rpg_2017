/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to manage the events
*/

#include "my.h"

static void manage_pause_event(sfRenderWindow *window, int *state,
button_t **buttons)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else if (event.type == sfEvtKeyPressed && SF_KEY == sfKeyEscape)
			*state = 0;
		if (event.type == sfEvtMouseMoved)
			menu_hoover(event.mouseMove, buttons, window, 473);
		else if (event.type == sfEvtMouseButtonPressed)
			*state = menu_click(event.mouseButton, buttons, window);
	}
}

int my_pause(sfRenderWindow *window, sfView const *view2, int state)
{
	sfImage *image = sfRenderWindow_capture(window);
	sfTexture *texture = sfTexture_createFromImage(image, NULL);
	button_t **buttons = get_pause_buttons();
	sfView const *view = sfRenderWindow_getDefaultView(window);

	sfRenderWindow_setView(window, view);
	while (sfRenderWindow_isOpen(window) && state == -1) {
		manage_pause_event(window, &state, buttons);
		sfRenderWindow_clear(window, sfBlack);
		display_res(window, (sfVector2f) {0, 0}, texture, sfWhite);
		for (int i = 0; buttons[i] != NULL; i = i + 1)
			sfRenderWindow_drawRectangleShape(window,
			buttons[i]->rect, NULL);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_setView(window, view2);
	sfImage_destroy(image);
	sfTexture_destroy(texture);
	destroy_menu(buttons, NULL);
	return (state);
}

void display_skills_point(sfRenderWindow *window, player_t *player,
sfText *text)
{
	char *pts = nb_to_str(player->ath->skill_tree.skills_point);

	sfText_setColor(text, sfBlack);
	sfText_setString(text, pts);
	sfText_setPosition(text, (sfVector2f) {875, 680});
	sfRenderWindow_drawText(window, text, NULL);
	free(pts);
	sfRenderWindow_setView(window, player->view);
}
