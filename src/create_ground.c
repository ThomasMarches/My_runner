/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_map.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void create_ground(int count, int line, game_t *game)
{
    game->t_ground[game->number_of_ground].texture =
    sfTexture_createFromFile("assets/Image/ground.jpg", NULL);
    game->t_ground[game->number_of_ground].sprite = sfSprite_create();
    game->t_ground[game->number_of_ground].position.x = count * 60;
    game->t_ground[game->number_of_ground].position.y = line * 40;
    sfSprite_setTexture(game->t_ground[game->number_of_ground].sprite,
    game->t_ground[game->number_of_ground].texture,
    sfTrue);
    sfSprite_setPosition(game->t_ground[game->number_of_ground].sprite,
    game->t_ground[game->number_of_ground].position);
    game->t_ground[game->number_of_ground].present = 1;
    game->t_ground[game->number_of_ground].stage = 0;
    game->t_ground[game->number_of_ground].last = 0;
    game->number_of_ground++;
    if (count * 60 > game->end_laser.position.x)
        game->end_laser.position.x = count * 60;
}