/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** File with libs functions
*/

#include "my.h"

int get_quest_nbr(player_t *player)
{
	int i = 0;

	for (; player->quests[i].resolved; i++);
	return (i);
}

int check_ressources_enable(void)
{
	sfTexture *tex = sfTexture_createFromFile(PATH_DIALOGUE_BG, sfFalse);
	sfTexture *t2 = sfTexture_createFromFile("sprites/pause.png", sfFalse);
	sfTexture *t3 = sfTexture_createFromFile("sprites/status_menu.png",
	sfFalse);
	sfTexture *t4 = sfTexture_createFromFile("sprites/village.jpg",
	sfFalse);
	int fd = open("maps/map_objects", O_RDONLY);
	int fd2 = open("maps/map_bg", O_RDONLY);

	if (!tex || !t2 || !t3 || !t4 || fd == -1 || fd2 == -1) {
		my_putstr("Some ressources are missings\n");
		return (0);
	}
	sfTexture_destroy(tex);
	sfTexture_destroy(t2);
	sfTexture_destroy(t3);
	sfTexture_destroy(t4);
	close(fd);
	close(fd2);
	return (1);
}

void save_key(char key_binding[SPELL_NBR])
{
	int fd = open("config.rpg", O_WRONLY | O_CREAT | O_TRUNC, 0666);

	if (fd == -1)
		return;
	write(fd, key_binding, sizeof(char) * SPELL_NBR);
}
