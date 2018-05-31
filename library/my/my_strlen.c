/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		i = i + 1;
	}
	return (i);
}
