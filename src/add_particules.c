/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** particules file
*/

#include "my.h"

partbuffer *new_part_buffer(int size)
{
	partbuffer *this;
	const size_t size_m = (sizeof(partbuffer) + sizeof(sfVertex) * size * 4
	+ sizeof(t_info) * size);
	void *ptn = malloc(size_m);

	if (ptn == NULL)
		return (NULL);
	memset(ptn, 0, size_m);
	this = (partbuffer *)(ptn);
	this->size = size;
	this->vertex = (sfVertex *) (ptn + sizeof(partbuffer));
	this->info = (t_info *) (this->vertex + (size * 4));
	return (this);
}

partbuffer *init(void)
{
	partbuffer *buffer = new_part_buffer(10000);

	if (buffer == NULL)
		return (0);
	return (buffer);
}

uint new_part(partbuffer *this)
{
	for (uint id = this->size - 1; id != 0; id -= 1)
		if (this->info[id].life <= 0)
			return (id);
	return ((uint) (-1));
}

void set_part(partbuffer *this, uint id, sfVector2f pos, sfColor color)
{
	if (id >= this->size)
		return;
	this->vertex[(id * 4) + 0].position =
	(sfVector2f) {pos.x + 0, pos.y + 0};
	this->vertex[(id * 4) + 1].position =
	(sfVector2f) {pos.x + 5, pos.y + 0};
	this->vertex[(id * 4) + 2].position =
	(sfVector2f) {pos.x + 5, pos.y + 5};
	this->vertex[(id * 4) + 3].position =
	(sfVector2f) {pos.x + 0, pos.y + 5};
	for (int cnt = 0; cnt != 4; cnt++)
		this->vertex[(id * 4) + cnt].color = color;
	this->info[id].speed.x = ((float) (rand() % 255) / 300);
	this->info[id].speed.y = -((float)(rand()
	% (int)(this->info[id].speed.x * 255 + 1)) / 700) + 2
	* ((float)(rand() % (int)(this->info[id].speed.x * 255 + 1)) / 700);
	this->info[id].life = 1.;
}
