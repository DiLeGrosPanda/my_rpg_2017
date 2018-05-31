/*
** EPITECH PROJECT, 2018
** my_random
** File description:
** my_random
*/

#include "my.h"
#include <fcntl.h>

int my_rand(int min, int max)
{
	int nb = rand();

	return (nb % (max - min + 1) + min);
}

void my_srand(void)
{
	int fd = open("/dev/urandom", O_RDONLY);
	char buff[4];
	unsigned int toto = 42;

	if (fd == -1)
		return;
	read(fd, buff, 4);
	for (int i = 0; i < 4; i = i + 1)
		toto = toto + buff[i];
	srand(toto);
	close(fd);
}
