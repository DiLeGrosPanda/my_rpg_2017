/*
** EPITECH PROJECT, 2018
** free_array
** File description:
** free_array
*/

#include "my.h"

void free_array(void **array)
{
	int i = 0;

	while (array[i] != NULL) {
		free(array[i]);
		i = i + 1;
	}
	free(array);
}
