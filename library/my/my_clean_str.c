/*
** EPITECH PROJECT, 2017
** clean_str
** File description:
** clean_str
*/

char *my_clean_str(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		str[i] = '\0';
		i = i + 1;
	}
	return (str);
}
