/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char *str1, char *str2)
{
	int i = 0;

	if (str1 == NULL && str2 == NULL)
		return (1);
	else if (str1 == NULL || str2 == NULL)
		return (0);
	while (str1[0] != '\0' && str2[0] != '\0') {
		if (str1[i] != str2[i])
			return (0);
		i = i + 1;
	}
	if (str1[i] != str2[i])
		return (0);
	return (1);
}
