/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File to init the whole map
*/

#include "my.h"

static const int **map_bg;
static const int **map_objects;

static void add_bg_to_vertex_array(maps_t *maps, int x, int y)
{
	if (map_bg[y][x] == -1)
		return;
	sfVertexArray_append(maps->array_bg, (sfVertex) {{x * 32, y * 32},
		sfWhite, {(map_bg[y][x]) % SPRITE_BG_WIDTH * 32,
			(map_bg[y][x]) / SPRITE_BG_WIDTH * 32}});
	sfVertexArray_append(maps->array_bg, (sfVertex) {{x * 32, y * 32 + 32},
		sfWhite, {(map_bg[y][x]) % SPRITE_BG_WIDTH * 32,
			(map_bg[y][x]) / SPRITE_BG_WIDTH * 32 + 32}});
	sfVertexArray_append(maps->array_bg,
	(sfVertex) {{x * 32 + 32, y * 32 + 32}, sfWhite,
		{(map_bg[y][x]) % SPRITE_BG_WIDTH * 32 + 32,
			(map_bg[y][x]) / SPRITE_BG_WIDTH * 32 + 32}});
	sfVertexArray_append(maps->array_bg, (sfVertex) {{x * 32 + 32, y * 32},
		sfWhite, {(map_bg[y][x]) % SPRITE_BG_WIDTH * 32 + 32,
			(map_bg[y][x]) / SPRITE_BG_WIDTH * 32}});
}

static void fill_array_bg(maps_t *maps)
{
	maps->array_bg = sfVertexArray_create();

	sfVertexArray_setPrimitiveType(maps->array_bg, sfQuads);
	for (int y = 0; map_bg[y]; y++)
		for (int x = 0; map_bg[y][x] != -2; x++)
			add_bg_to_vertex_array(maps, x, y);
}

static void fill_llist_objects(maps_t *maps, int y)
{
	for (int x = 0; map_objects[y][x] != -2; x++) {
		if (map_objects[y][x] <= -1 || (map_objects[y][x] + 1)
			>= SPRITE_BG_NBR)
			continue;
		if ((IS_GOBELIN(map_objects[y][x])) ||
		IS_MAGE(map_objects[y][x]) || IS_SOLDIER(map_objects[y][x]))
			add_monster(maps, (sfVector2f) {x * 32, y * 32},
			map_objects[y][x]);
		else
			add_object(maps, map_objects[y][x],
			(sfVector2f) {x * 32, y * 32});
	}
}

int init_maps(maps_t *maps)
{
	get_maps();
	fill_maps_values(maps);
	if (!maps->texture_full || !maps->llist_fireball->texture)
		return (1);
	sfSprite_setTexture(maps->llist_fireball->sprite,
	maps->llist_fireball->texture, sfFalse);
	fill_sprite_array(maps);
	maps->fire_sound = sfSoundBuffer_createFromFile("fire.wav");
	fill_array_bg(maps);
	for (int y = 0; map_objects[y]; y++)
		fill_llist_objects(maps, y);
	fill_render_states(maps);
	fill_npc(maps);
	return (0);
}

void get_maps(void)
{
	int fd = open("maps/map_bg", O_RDONLY);
	int fd1 = open("maps/map_objects", O_RDONLY);
	char *line = get_next_line(fd);

	if (fd == -1 || fd1 == -1)
		return;
	for (int i = 0; line != NULL; i = i + 1) {
		map_bg = (const int **)realloc_array((void **)map_bg, 1);
		map_bg[i] = resolve_line(line);
		free(line);
		line = get_next_line(fd);
	}
	line = get_next_line(fd1);
	for (int i = 0; line != NULL; i = i + 1) {
		map_objects = (const int **)realloc_array((void **)map_objects,
		1);
		map_objects[i] = resolve_line(line);
		free(line);
		line = get_next_line(fd1);
	}
}
