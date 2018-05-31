/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line main file
*/

#include "get_next_line.h"
#include "my.h"

int str_find2(char *str, char to_find)
{
	int i = 0;
	int len = 0;

	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len = len + 1;
	if (to_find == '\0')
		return (len);
	while (i < len) {
		if (str[i] == to_find)
			return (i);
		i = i + 1;
	}
	return (-1);
}

char *my_str_concat(char *str, char *str2)
{
	char *res = malloc(1 * (str_find2(str, 0) + str_find2(str2, 0)) + 1);
	int i = 0;
	int a = 0;

	if (str != NULL && res != NULL) {
		while (str[i] != '\0') {
			res[i] = str[i];
			i = i + 1;
		}
	}
	if (str2 != NULL && res != NULL) {
		while (str2[a] != '\0') {
			res[i] = str2[a];
			i = i + 1;
			a = a + 1;
		}
	}
	if (res != NULL)
		res[i] = '\0';
	return (res);
}

char *split_str(char *str, char *buff)
{
	int len = str_find2(str, '\n');
	int len_tot = str_find2(str, '\0');
	char *res;
	int i = 0;

	if (len < 0)
		len = len_tot;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL || str == NULL || str[0] == '\0')
		return (NULL);
	for (i = 0; str[i] != '\n' && str[i] != '\0'; i = i + 1)
		res[i] = str[i];
	res[i] = '\0';
	if (str[i] == '\n')
		len = len + 1;
	for (i = 0; str[i + len] != '\0'; i = i + 1)
		buff[i] = str[i + len];
	buff[i] = '\0';
	return (res);
}

char *buffer_without_carriage_return(int fd, char *buff, int *len)
{
	char *res = malloc(sizeof(char) * READ_SIZE + 1);
	char *temp = NULL;
	char *free_var = NULL;

	*len = read(fd, res, READ_SIZE);
	if ((*len == 0 && buff[0] == '\0') || *len == -1 || res == NULL) {
		free(res);
		return (NULL);
	}
	res[*len] = '\0';
	temp = my_str_concat(buff, res);
	while (str_find2(temp, '\n') == -1 && *len > 0 && temp != NULL) {
		*len = read(fd, res, READ_SIZE);
		res[*len] = '\0';
		free_var = temp;
		temp = my_str_concat(temp, res);
		free(free_var);
	}
	free(res);
	return (temp);
}

char *get_next_line(int fd)
{
	char *temp = NULL;
	static char buff[READ_SIZE + 1] = {'\0'};
	static int len = READ_SIZE;
	char *res = NULL;

	if (fd < 0)
		return (NULL);
	if (str_find2(buff, '\n') > 0) {
		temp = split_str(buff, buff);
		return (temp);
	} else {
		temp = buffer_without_carriage_return(fd, buff, &len);
		if (temp == NULL)
			return (NULL);
	}
	res = split_str(temp, buff);
	free(temp);
	return (res);
}
