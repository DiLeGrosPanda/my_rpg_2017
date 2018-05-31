/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Check collisions
*/

#include "my.h"

short collision(sfIntRect box1, sfIntRect box2)
{
	if ((box2.left >= box1.left + box1.width)
		|| (box2.left + box2.width <= box1.left)
		|| (box2.top >= box1.top + box1.height)
		|| (box2.top + box2.height <= box1.top))
		return (0);
	return (1);
}

short mouse_in_rect(sfVector2f mouse, sfVector2f target, sfVector2f hitbox)
{
	if (mouse.x > target.x && mouse.x < target.x + hitbox.x &&
		mouse.y > target.y && mouse.y < target.y + hitbox.y)
		return (1);
	return (0);
}
