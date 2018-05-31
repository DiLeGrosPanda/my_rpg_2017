/*
** EPITECH PROJECT, 2018
** realloc_array
** File description:
** realloc_array
*/

#include "my.h"

void realloc_tab(void ***tab, void *new)
{
	int i = 0;
	void **res;

	if (*tab != NULL)
		for (i = 0; (*tab)[i] != NULL; i = i + 1);
	res = malloc(sizeof(void *) * (i + 2));
	for (int a = 0; a < i; a = a + 1)
		res[a] = (*tab)[a];
	res[i] = new;
	res[i + 1] = NULL;
	free(*tab);
	*tab = res;
}

void **realloc_array(void **array, int a)
{
	void **new;
	int i = 0;
	int y = 0;

	for (i = 0; array && array[i] != NULL; i = i + 1);
	new = malloc(sizeof(void *) * (i + a + 1));
	for (y = 0; array && y < i + a; y = y + 1)
		new[y] = array[y];
	for (; y < i + a; y = y + 1)
		new[y] = NULL;
	new[i + a] = NULL;
	free(array);
	return (new);
}
