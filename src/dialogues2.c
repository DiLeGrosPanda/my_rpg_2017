/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg
*/

#include "my.h"

void display_text_on_screen(sfRenderWindow *window, player_t *player,
dialogue_display_t *dial, float height)
{
	sfText *text;
	sfFont *font;

	if (!dial->iter)
		return;
	text = sfText_create();
	font = sfFont_createFromFile("Blacksword.otf");
	sfText_setFont(text, font);
	sfText_setColor(text, sfBlue);
	sfText_setString(text, dial->iter->dialogue);
	sfText_setPosition(text, (sfVector2f)
	{sfSprite_getPosition(player->sprite).x - 400,
		sfSprite_getPosition(player->sprite).y + height});
	sfRenderWindow_drawText(window, text, NULL);
	sfFont_destroy(font);
	sfText_destroy(text);
}

int player_click_next(sfEvent event)
{
	if (event.type != sfEvtMouseButtonPressed)
		return (0);
	if (event.mouseButton.x < 1130 || event.mouseButton.x > 1230 ||
		event.mouseButton.y < 870 ||
		event.mouseButton.y > 910)
		return (0);
	return (1);
}

int event_dialogue(sfEvent event, sfRenderWindow *window,
dialogue_display_t *dial)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	else if (event.type == sfEvtKeyPressed || (player_click_next(event))) {
		if (!(dial->iter = dial->iter->next))
			return (0);
		sfTexture_destroy(dial->texture);
		dial->texture = sfTexture_createFromFile(
		dial->iter->path, sfFalse);
		sfSprite_setTexture(dial->sprite, dial->texture, sfFalse);
	}
	return (1);
}

void display_dialogue(sfRenderWindow *window, player_t *player,
dialogue_display_t *dial)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, dial->sprite_bg, NULL);
	sfRenderWindow_drawSprite(window, dial->sprite, NULL);
	display_text_on_screen(window, player, dial, 350);
	sfRenderWindow_display(window);
}
