/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** task04
*/

int my_pow(int nb, int p)
{
	if (p > 1) {
		nb = nb * my_pow(nb, p - 1);
	}
	if (p == 0) {
		nb = 1;
	}
	if (p < 0 || nb < 0) {
		nb = 0;
	}
	return (nb);
}
