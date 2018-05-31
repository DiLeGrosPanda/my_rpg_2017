/*
** EPITECH PROJECT, 2017
** nb_to_str
** File description:
** nb_to_str
*/

#include "my.h"

char *nb_to_str(int nb)
{
	int i = my_nblen(nb);
	char *str = malloc(sizeof(char) * i + 2);

	str[i + 1] = '\0';
	str[i] = '\0';
	i = i - 1;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0) {
		str[0] = '-';
		nb = nb * -1;
		i = i + 1;
	}
	while (nb != 0) {
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i = i - 1;
	}
	return (str);
}
