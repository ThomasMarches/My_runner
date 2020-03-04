/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** generate_random_number.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

int generate_number(int lower, int upper)
{
    int num = 0;

    num = (rand() % (upper - lower + 1)) + lower;
    return (num);
}