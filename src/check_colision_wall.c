/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** wall.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void check_colision_wall(game_t *game)
{
    game->how_to_play = 0;
    game->player.floatrect =
    sfSprite_getGlobalBounds(game->player.sprite);
    for (int count = 0; count != game->number_of_wall;
    count++) {
        if (game->wall[count].present == 1) {
            game->wall[count].floatrect =
            sfSprite_getGlobalBounds(game->wall[count].sprite);
            colision_with_wall_condition(game, count);
        }
    }
}