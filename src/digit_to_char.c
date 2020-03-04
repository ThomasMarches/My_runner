/*
** EPITECH PROJECT, 2019
** Hunter2.0 (copy)
** File description:
** digit_to_char.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

char *digit_to_char(int digit)
{
    char *str = malloc(sizeof(char) * 2000);
    long int div = 1;
    int i = 0;

    while ((digit / div) != 0)
        div = div * 10;
    while (div != 1) {
        str[i] = ((digit % div) / (div / 10)) + 48;
        div = div / 10;
        i++;
    }
    str[i] = '\0';
    if (str[0] == '\0')
        return ("0");
    return (str);
}