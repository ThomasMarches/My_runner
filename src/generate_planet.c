/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** generate_planet.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

char *generate_random_ships(int number)
{
    if (number < 3)
        return ("assets/Image/spaceship01.png\0");
    else if (number < 5)
        return ("assets/Image/spacesgip02.png\0");
    if (number < 7)
        return ("assets/Image/spacesgip03.png\0");
    else
        return ("assets/Image/spacesgip04.png\0");
}

char *generate_random_filepath(int number)
{
    if (number == 1)
        return ("assets/Image/planet.png\0");
    else if (number == 2)
        return ("assets/Image/Sun.png\0");
    if (number == 3)
        return ("assets/Image/Planet0.png\0");
    else if (number == 4)
        return ("assets/Image/Planet1.png\0");
    if (number == 5)
        return ("assets/Image/Planet2.png\0");
    else if (number == 6)
        return ("assets/Image/Planet4.png\0");
    if (number == 7)
        return ("assets/Image/Planet5.png\0");
    else if (number == 8)
        return ("assets/Image/Planet7.png\0");
    else
        return ("assets/Image/Planet8.png\0");
}

void generate_planet(game_t *game, int count)
{
    int number = generate_number(0, 10);

    sfSprite_destroy(game->background[count].sprite);
    sfTexture_destroy(game->background[count].texture);
    game->background[count].texture =
    sfTexture_createFromFile(generate_random_ships(number),
    NULL);
    game->background[count].sprite = sfSprite_create();
    sfSprite_setTexture(game->background[count].sprite,
    game->background[count].texture, sfTrue);
}

void generate_ships(game_t *game, int count)
{
    int number = generate_number(0, 10);

    sfSprite_destroy(game->background[count].sprite);
    sfTexture_destroy(game->background[count].texture);
    game->background[count].texture =
    sfTexture_createFromFile(generate_random_ships(number),
    NULL);
    game->background[count].sprite = sfSprite_create();
    sfSprite_setTexture(game->background[count].sprite,
    game->background[count].texture, sfTrue);
}