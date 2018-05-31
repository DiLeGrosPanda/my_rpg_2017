/*
** EPITECH PROJECT, 2017
** is_number
** File description:
** is_number
*/

#include "my.h"

int is_number(char const *str)
{
	int i = 0;
	int len = my_strlen(str);

	if (str == NULL)
		return (0);
	while (i < len) {
		if ((str[i] > '9' || str[i] < '0') && str[i] != '-')
			return (0);
		i = i + 1;
	}
	return (1);
}
