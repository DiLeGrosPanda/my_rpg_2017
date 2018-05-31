/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** quests.c
*/

#include "my.h"

const dialogue_quest_t *dial1 = cons("sprites/dial_2.png", "Wizard ! the "
		"world needs you !",
	cons("sprites/dial_1.png", "Huh what ?",
	cons("sprites/dial_2.png", "Since they spawn, some gobelins try"
		"to steal our ressources && kill us. Oh please help us",
	cons("sprites/dial_1.png", "...",
	cons("sprites/dial_2.png", "First, you should talk to our prest !",
	NULL)))));

const dialogue_quest_t *dial2 = cons("sprites/dial_2.png", "Oh, you finnaly "
		"came !",
	cons("sprites/dial_1.png", "...\nWhat am i supposed to do ?",
	cons("sprites/dial_2.png", "First, try to hunt 5 monsters."
	"I 'll come back to you then.", NULL)));

const dialogue_quest_t *dial3 = cons("sprites/dial_1.png", "AHHHHH",
	cons("sprites/dial_2.png", "Wow, you did it !",
	cons("sprites/dial_1.png", "Yeah, that wasn't easy..",
	cons("sprites/dial_2.png", "Hum, i'm sorry but we need you to hunt"
		"all of them. <3", NULL))));

const dialogue_quest_t *dial4 = cons("sprites/dial_2.png", "Amazing !",
	cons("sprites/dial_2.png", "You did it ! You kill'd them all !",
	cons("sprites/dial_2.png", "So i guess you just won the game !! ",
	cons("sprites/dial_2.png", "A few monsters 'll still appears over "
		"and over\nbut we should be able to take care of them",
	cons("sprites/dial_2.png", "Feel free to bring back your previous"
		" life.",
	cons("sprites/dial_2.png", "Thanks for playing.", NULL))))));
