/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to create the ath
*/

#include "my.h"

void event_how_to_play(sfRenderWindow *window, int *state)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else if (event.type == sfEvtKeyPressed)
			*state = *state + 1;
	}
}

int how_to_play(sfRenderWindow *window)
{
	sfTexture *t1 = sfTexture_createFromFile("sprites/tuto1.png", NULL);
	sfTexture *t2 = sfTexture_createFromFile("sprites/tuto2.png", NULL);
	sfSprite *sprite = sfSprite_create();
	int state = 0;

	while (sfRenderWindow_isOpen(window) && state != 2) {
		sfRenderWindow_clear(window, sfBlack);
		if (state == 0)
			sfSprite_setTexture(sprite, t1, sfTrue);
		else if (state == 1)
			sfSprite_setTexture(sprite, t2, sfTrue);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_display(window);
		event_how_to_play(window, &state);
	}
	sfSprite_destroy(sprite);
	sfTexture_destroy(t1);
	sfTexture_destroy(t2);
	return (-1);
}

void action_ath(sfRenderWindow *window, player_t *player, int i)
{
	switch (i) {
	case 0:
		player->ath->skill_tree.is_active = 1;
		break;
	case 1:
		display_inventory(window, player);
		break;
	case 2:
		display_player_infos(window, player);
		break;
	case 3:
		display_quest(window, player, sfSprite_create(), 1);
		break;
	default:
		break;
	}
}

int manage_ath_mouse(sfRenderWindow *window, sfEvent event, player_t *player)
{
	sfVector2f clic = {event.mouseButton.x, event.mouseButton.y};
	sfVector2u size = sfRenderWindow_getSize(window);
	sfVector2f hitbox = {72, 72};
	sfVector2f pos = {8, 300};

	for (int i = 0; pos.y <= 600; i = i + 1) {
		if (mouse_in_rect(clic, MAP_TRUE_COORDS(pos, size), hitbox)) {
			action_ath(window, player, i);
			return (1);
		}
		pos.y += 100;
	}
	return (0);
}

void init_ath(ath_t *ath, player_t *player)
{
	ath->ath_base = sfTexture_createFromFile(ATH_BASE, sfFalse);
	ath->states = (sfRenderStates) {
		.blendMode = sfBlendAlpha,
		.transform = sfTransform_Identity,
		.texture = ath->ath_base,
	};
	ath->shader = sfShader_createFromFile("shader/shader/simple.vert",
	"shader/shader/gradient.frag"),
	ath->array = sfVertexArray_create();
	ath->dialogue = (dialogue_t) {sfText_create(),
		sfFont_createFromFile("sprites/arial.ttf"),
		sfTexture_createFromFile("sprites/dialogues.png", sfFalse),
		sfSprite_create()};
	sfSprite_setTexture(ath->dialogue.sprite, ath->dialogue.texture,
	sfFalse);
	sfText_setFont(ath->dialogue.text, ath->dialogue.font);
	sfText_setColor(ath->dialogue.text, sfBlue);
	sfVertexArray_setPrimitiveType(ath->array, sfQuads);
	ath->skill_tree.unlocked[0] = 1;
	player->ath = ath;
}
