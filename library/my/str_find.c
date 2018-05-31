/*
** EPITECH PROJECT, 2017
** str_find
** File description:
** str_find
*/

#include "my.h"

int str_find(char *str, char to_find)
{
	int i = 0;
	int len = my_strlen(str);

	while (i < len) {
		if (str[i] == to_find)
			return (1);
		i = i + 1;
	}
	return (0);
}

int count_char(char *str, char car)
{
	int nb = 0;
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == car)
			nb = nb + 1;
		i = i + 1;
	}
	return (nb);
}
