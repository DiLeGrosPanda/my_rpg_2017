/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char const *str)
{
	int i = 0;
	int len = my_strlen(str) - 1;
	char buff;
	char *res = malloc(sizeof(char) * my_strlen(str) + 1);

	while (str[i] != '\0') {
		res[i] = str[i];
		i = i + 1;
	}
	i = 0;
	while (i < len) {
		buff = res[i];
		res[i] = res[len];
		res[len] = buff;
		i = i + 1;
		len = len - 1;
	}
	return (res);
}
