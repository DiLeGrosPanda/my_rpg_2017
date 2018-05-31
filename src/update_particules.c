/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file
*/

#include "my.h"

void update_part_buffer(partbuffer *this)
{
	for (uint id = 0; id < this->size; id += 1) {
		if (this->info[id].life <= 0)
			continue;
		this->info[id].life -= 1/100.;
		if (this->info[id].life <= 0) {
			memset(this->vertex + (id * 4), 0,
			sizeof(sfVertex) * 4);
			continue;
		}
		for (int cnt = 0; cnt != 4; cnt++) {
			this->vertex[(id * 4) + cnt].position.x +=
			this->info[id].speed.x;
			this->vertex[(id * 4) + cnt].position.y +=
			this->info[id].speed.y;
			this->vertex[(id * 4) + cnt].color.a =
			(int)(this->info[id].life * 255.);
		}
	}
}

void update_part_buffer_lightning(partbuffer *this)
{
	int idrect;

	for (uint id = 0; id < this->size; id += 1) {
		this->info[id].life -= 1/40.;
		if (this->info[id].life <= 0) {
			memset(this->vertex + (id * 4), 0,
			sizeof(sfVertex) * 4);
			continue;
		}
		idrect = (int)((1. - this->info[id].life) * 23.);
		this->vertex[(id * 4) + 0].texCoords = (sfVector2f)
		{200 * idrect, 0};
		this->vertex[(id * 4) + 1].texCoords = (sfVector2f)
		{200 * (idrect + 1), 0};
		this->vertex[(id * 4) + 2].texCoords = (sfVector2f)
		{200 * (idrect + 1), 500};
		this->vertex[(id * 4) + 3].texCoords = (sfVector2f)
		{200 * idrect, 500};
	}
}

void update(sfRenderWindow *window, fireball_t *fireball)
{
	sfVector2f pos = sfSprite_getPosition(fireball->sprite);
	uint id;

	pos.x += 30;
	pos.y += 45;
	update_part_buffer(fireball->buffer);
	for (int i = 0; i < 10; i += 1) {
		if ((id = new_part(fireball->buffer)) == (uint) (-1))
			break;
		set_part(fireball->buffer, id,
		pos, (sfColor) {255, 140, 0, 255});
	}
	draw_part_buffer(fireball->buffer, window);
}

void update_lightning(sfRenderWindow *window, player_t *player)
{
	if (!player->buffer)
		return;
	update_part_buffer_lightning(player->buffer);
	draw_part_buffer_lightning(player->buffer, window);
}
