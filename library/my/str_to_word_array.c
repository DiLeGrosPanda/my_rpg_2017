/*
** EPITECH PROJECT, 2018
** str_to_word_array
** File description:
** str_to_word_array
*/

#include "my.h"

int count_words(char *str, char delim)
{
	int i = 0;
	int count = 0;
	int is_char = 0;

	if (str == NULL)
		return (0);
	while (str[i + 1] != '\0') {
		if (str[i] != delim)
			is_char = 1;
		if (str[i] == delim && str[i + 1] != delim && str[i + 1] != '\0'
			&& is_char == 1)
			count = count + 1;
		i = i + 1;
	}
	return (count + 1);
}

char *get_word(char *str, int nb, char delim)
{
	int i = 0;
	int len = 0;
	int count = 0;
	int is_char = 0;
	char *res = NULL;

	for (i = 0; str[i + 1] != '\0' && count < nb; i = i + 1) {
		if (str[i] != delim)
			is_char = 1;
		if (str[i] == delim && str[i + 1] != delim && str[i + 1] != '\0'
			&& is_char == 1)
			count = count + 1;
	}
	while (str[i + len] != delim && str[i + len] != '\0')
		len = len + 1;
	res = malloc(sizeof(char) * (len + 1));
	for (int a = 0; str[i + a] != '\0' && str[i + a] != delim; a = a + 1)
		res[a] = str[i + a];
	res[len] = '\0';
	return (res);
}

char **str_to_word_array(char *str, char delim)
{
	int nb = count_words(str, delim);
	char **res = NULL;
	int i = 0;

	if (str == NULL)
		return (NULL);
	res = malloc(sizeof(char *) * (nb + 1));
	while (i < nb) {
		res[i] = get_word(str, i, delim);
		i = i + 1;
	}
	res[i] = NULL;
	return (res);
}
