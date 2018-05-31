/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg
*/

#include "my.h"

void fill_sprite_array(maps_t *maps)
{
	sfSprite *sprite = sfSprite_create();

	sfSprite_setTexture(sprite, maps->texture_full, sfFalse);
	for (int y = 0; y < SPRITE_BG_HEIGHT; y++) {
		for (int x = 0; x < SPRITE_BG_WIDTH; x++) {
			sfSprite_setTextureRect(sprite,
			(sfIntRect) {x * 32, y * 32, 32, 32});
			maps->sprite_array[x + y * SPRITE_BG_WIDTH] =
			sfSprite_copy(sprite);
		}
	}
	sfSprite_destroy(sprite);
}

int *resolve_line(char *line)
{
	int len = count_char(line, ',') + 1;
	int *new = malloc(sizeof(int) * (len + 1));
	char **array = str_to_word_array(line, ',');
	int temp;

	for (int i = 0; i < len; i = i + 1) {
		temp = my_getnbr(array[i]);
		if (temp == -1)
			new[i] = temp;
		else
			new[i] = temp;
	}
	new[len] = -2;
	free_array((void **)array);
	return (new);
}
