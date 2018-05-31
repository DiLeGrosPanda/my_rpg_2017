/*
** EPITECH PROJECT, 2017
** my_nblen
** File description:
** my_nblen
*/

int my_nblen(int nb)
{
	int i = 0;

	while (nb != 0) {
		nb = nb / 10;
		i = i + 1;
	}
	return (i);
}
