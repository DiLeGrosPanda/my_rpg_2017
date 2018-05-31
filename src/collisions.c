/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Check collisions
*/

#include "my.h"

int check_collision_ennemy_ennemy(monster_t *un, monster_t *deux,
sfVector2f move)
{
	sfVector2f pos1 = un->pos;
	sfVector2f pos2 = deux->pos;
	sfIntRect box1 = {pos1.x + move.x, pos1.y + move.y, 15, 15};
	sfIntRect box2 = {pos2.x, pos2.y, 15, 15};

	if (un == deux)
		return (0);
	if (collision(box1, box2) || pos1.x + move.x < 0 ||
		pos1.y + move.y < 0 || (pos1.x + move.x) > 32 *
		COL_NBR || (pos1.y + move.y) > 32 * LINES_NBR)
		return (1);
	return (0);

}

int check_collision_ennemy_decor(const monster_t * const monster,
const objects_t * const iter, const sfVector2f move)
{
	sfVector2f pos1 = monster->pos;
	sfVector2f pos2 = iter->pos;

	if ((iter->value != COIN_VAL && iter->value != XP_POT_VAL &&
		iter->value != HEART_VAL && iter->value !=
		HP_POT_VAL && iter->value != BLOOD_VAL) &&
		(collision((sfIntRect) {pos1.x + move.x, pos1.y +
			move.y, 32, 32}, (sfIntRect) {pos2.x, pos2.y, 32, 32})))
		return (1);
	return (0);
}
