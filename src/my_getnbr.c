/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** display int enter without other character
*/

int my_getnbr(const char *str)
{
    int i = 0;
    int nbr = 0;
    int v = 0;

    while (str[i] != '\0' && v == 0) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i] - 48;
        }
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
            v = 1;
        i++;
    }
    return (nbr);
}