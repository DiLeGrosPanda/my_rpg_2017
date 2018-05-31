/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to manage the events
*/

#include "my.h"

void set_part_lightning(partbuffer *this, uint id, sfColor color)
{
	if (id >= this->size)
		return;
	this->vertex[(id * 4) + 0].position = (sfVector2f){150, 0};
	this->vertex[(id * 4) + 1].position = (sfVector2f){350, 0};
	this->vertex[(id * 4) + 2].position = (sfVector2f){350, 500};
	this->vertex[(id * 4) + 3].position = (sfVector2f){150, 500};
	this->vertex[(id * 4) + 0].texCoords = (sfVector2f){0, 0};
	this->vertex[(id * 4) + 1].texCoords = (sfVector2f){200, 0};
	this->vertex[(id * 4) + 2].texCoords = (sfVector2f){200, 500};
	this->vertex[(id * 4) + 3].texCoords = (sfVector2f){0, 500};
	for (int cnt = 0; cnt != 4; cnt++)
		this->vertex[(id * 4) + cnt].color = color;
	this->info[id].life = 1.;
}

void player_kill_monster(player_t *player, maps_t *maps, monster_t *monster)
{
	xp_player(player, 0.1);
	player->monster_killed += 1;
	spawn_object(maps, monster->pos);
	remove_monster(maps->llist_monsters, monster);
}

void check_lightning_hit(sfRenderWindow *window, maps_t *maps,
player_t *player)
{
	sfVector2f need = sfRenderWindow_mapPixelToCoords((window),
	sfMouse_getPositionRenderWindow(window),
	sfRenderWindow_getView(window));
	sfVector2f pos = sfSprite_getPosition(player->sprite);
	sfIntRect rect = {(int) need.x - 30, (int) need.y - 30, 60, 60};
	sfIntRect rect2 = {0, 0, 32, 32};
	monster_t *next;

	for (monster_t *tmp = maps->llist_monsters->first; tmp; tmp = next) {
		next = tmp->next;
		pos = tmp->pos;
		rect2.left = pos.x;
		rect2.top = pos.y;
		if (collision(rect, rect2) && (!(tmp->life -= 1) ||
		tmp->life == -1)) {
			player_kill_monster(player, maps, tmp);
		}
	}
}

void create_lightning_particules(sfRenderWindow *window,
player_t *player, int i)
{
	sfVector2f pos_lightning = sfRenderWindow_mapPixelToCoords((window),
	sfMouse_getPositionRenderWindow(window),
	sfRenderWindow_getView(window));
	float height = pos_lightning.y - (POS_PLAYER.y - WIN_HEIGHT / 2);

	pos_lightning.x -= 100;
	player->buffer->vertex[(i * 4) + 0].position =
	(sfVector2f) {pos_lightning.x, pos_lightning.y - height};
	player->buffer->vertex[(i * 4) + 1].position =
	(sfVector2f) {pos_lightning.x + 200, pos_lightning.y - height};
	player->buffer->vertex[(i * 4) + 2].position =
	(sfVector2f) {pos_lightning.x + 200, pos_lightning.y + 50};
	player->buffer->vertex[(i * 4) + 3].position =
	(sfVector2f) {pos_lightning.x, pos_lightning.y + 50};
	player->buffer->vertex[(i * 4) + 0].texCoords = (sfVector2f){0, 0};
	player->buffer->vertex[(i * 4) + 1].texCoords = (sfVector2f){200, 0};
	player->buffer->vertex[(i * 4) + 2].texCoords = (sfVector2f){200, 500};
	player->buffer->vertex[(i * 4) + 3].texCoords = (sfVector2f){0, 500};
	for (int cnt = 0; cnt != 4; cnt++)
		player->buffer->vertex[(i * 4) + cnt].color = sfWhite;
	player->buffer->info[i].life = 1.;
}
