/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my.h"

int my_putnbr(int nb)
{
	int n = 0;
	int temp = 0;

	nb = test_nb(nb);
	temp = nb;
	while (temp > 0) {
		temp = temp / 10;
		n = n + 1;
	}
	while (n != 0) {
		my_putchar((nb / my_pow(10, n - 1)) + 48);
		temp = my_pow(10, n - 1);
		nb = nb % temp;
		n = n - 1;
	}
	return (0);
}

int test_nb(int nb)
{
	if (nb == 0) {
		my_putchar('0');
	}
	if (nb == -2147483648) {
		nb = -214748364;
		my_putnbr(nb);
		my_putchar('8');
		nb = 0;
	}
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	return (nb);
}
