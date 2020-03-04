/*
** EPITECH PROJECT, 2019
** My swap
** File description:
** My swap is used to swap two integers with their adress taken as parameter
*/

#include "prototypes.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i2 = 0;
    int i3 = 0;

    i2 = my_strlen(s1);
    i3 = my_strlen(s2);
    if (i2 != i3)
        return (1);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (1);
    }
    return (0);
}