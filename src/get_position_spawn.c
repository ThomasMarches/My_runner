/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_map.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

bool able_to_spawn(game_t *game, int count)
{
    if (game->t_ground[count].present == 0)
        return (0);
    game->t_ground[count].position =
    sfSprite_getPosition(game->t_ground[count].sprite);
    if (game->t_ground[count].position.x >= 1920
    && game->t_ground[count].stage == 0)
        return (1);
    return (0);
}

sfVector2f get_position_spawn(game_t *game, int number)
{
    sfVector2f position = {-200, 0};
    int check = 0;

    for (int count = 0; count != game->number_of_ground; count++) {
        check = able_to_spawn(game, count);
        if (check == 1) {
            game->t_ground[count].stage = 1;
            game->t_ground[count].position =
            sfSprite_getPosition(game->t_ground[count].sprite);
            position.x = game->t_ground[count].position.x;
            position.y = game->t_ground[count].position.y - number;
            return (position);
        }
    }
    return (position);
}
