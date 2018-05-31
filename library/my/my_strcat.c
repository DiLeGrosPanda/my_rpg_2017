/*
** EPITECH PROJECT, 2017
** my_str_concat
** File description:
** my_str_concat
*/

#include "my.h"

char *my_strcat(char *str1, char *str2)
{
	char *res;
	int i = 0;

	res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2)) + 2);
	if (res == NULL)
		return (NULL);
	if (str1 != NULL) {
		while (str1[i] != '\0') {
			res[i] = str1[i];
			i = i + 1;
		}
	}
	if (str2 != NULL) {
		for (int a = 0; str2[a] != '\0'; a = a + 1) {
			res[i] = str2[a];
			i = i + 1;
		}
	}
	res[i] = '\0';
	return (res);
}
