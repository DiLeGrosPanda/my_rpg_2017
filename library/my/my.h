/*
** EPITECH PROJECT, 2017
** my
** File description:
** header
*/

#ifndef UNUSED
#define UNUSED __attribute__((unused))
#endif

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char const c);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char const *str);
int my_putnbr(int nb);
char *my_strcat(char *str1, char *str2);
char *my_clean_str(char *str);
int test_nb(int nb);
int my_pow(int nb, int p);
char *nb_to_str(int nb);
int my_nblen(int nb);
int my_getnbr(char const *str);
void my_puterr(char const *str);
void infin_put(int len, ...);
int str_find(char *str, char to_find);
int is_number(char const *str);
int my_strcmp(char *str1, char *str2);
int count_words(char *str, char delim);
char *get_word(char *str, int nb, char delim);
char **str_to_word_array(char *str, char delim);
void free_array(void **array);
int count_char(char *str, char car);
int my_rand(int min, int max);
void my_srand(void);
void **realloc_array(void **array, int a);
void realloc_tab(void ***array, void *ptr);

#endif
