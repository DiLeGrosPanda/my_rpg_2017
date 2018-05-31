/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** quests.c
*/

#include "my.h"

void clear_dialogue_quest(sfTexture *texture, sfTexture *texture_bg,
sfSprite *sprite, sfSprite *sprite_bg)
{
	sfTexture_destroy(texture);
	sfTexture_destroy(texture_bg);
	sfSprite_destroy(sprite);
	sfSprite_destroy(sprite_bg);
}

void dialogue_quest_loop(sfRenderWindow *window, player_t *player,
dialogue_display_t dial)
{
	sfEvent event;
	sfIntRect rect = {0, 0, 500, 500};
	float keep = 0.1;
	int ret = 1;

	while (sfRenderWindow_isOpen(window) && dial.iter) {
		ret = 1;
		while (sfRenderWindow_pollEvent(window, &event) && ret)
			ret = event_dialogue(event, window, &dial);
		display_dialogue(window, player, &dial);
		if ((dial.seconds = sfClock_getElapsedTime(dial.clock)\
.microseconds / 1000000.0) >= keep) {
			rect.left = rect.left > 11000 ? 0 : rect.left + 500;
			keep = dial.seconds + 0.04;
			sfSprite_setTextureRect(dial.sprite_bg, rect);
		}
	}
	clear_dialogue_quest(dial.texture, dial.texture_bg, dial.sprite,
	dial.sprite_bg);
	sfClock_destroy(dial.clock);
}

void display_dialogue_quest(sfRenderWindow *window, player_t *player)
{
	dialogue_display_t dial = {
		.iter = player->quests[get_quest_nbr(player)].dialogue,
		.texture = sfTexture_createFromFile(dial.iter->path, sfFalse),
		.texture_bg = sfTexture_createFromFile(PATH_DIALOGUE_BG, NULL),
		.sprite = sfSprite_create(),
		.sprite_bg = sfSprite_create(),
		.clock = sfClock_create(),
	};
	sfVector2f pos = sfSprite_getPosition(player->sprite);

	sfSprite_setTexture(dial.sprite_bg, dial.texture_bg, sfFalse);
	sfSprite_setPosition(dial.sprite_bg, (sfVector2f) {pos.x -
		WIN_WIDTH / 2, pos.y - WIN_HEIGHT / 2});
	sfSprite_setScale(dial.sprite_bg, (sfVector2f) {WIN_WIDTH / 500 * 1.3,
		WIN_HEIGHT / 500 * 1.9});
	sfSprite_setTexture(dial.sprite, dial.texture, sfFalse);
	sfSprite_setPosition(dial.sprite,
	(sfVector2f) {pos.x - 600, pos.y - 300});
	dialogue_quest_loop(window, player, dial);
}
