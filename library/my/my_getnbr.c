/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
	int nb = 0;
	int i = 0;
	int neg = 1;

	if (str == NULL)
		return (0);
	if (str[0] == '-') {
		i = i + 1;
		neg = -1;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10 + str[i] - 48;
		i = i + 1;
	}
	return (nb * neg);
}
