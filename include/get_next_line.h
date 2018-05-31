/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** get_next_line.h
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#ifndef READ_SIZE
#define READ_SIZE (16)
#endif

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

#endif
