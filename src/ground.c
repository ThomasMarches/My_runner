/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** ground.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void destroy_not_infinite(game_t *game, int count)
{
    game->t_ground[count].position =
    sfSprite_getPosition(game->t_ground[count].sprite);
    if (game->t_ground[count].position.x < -200) {
        destroy_object(game->t_ground[count]);
        game->t_ground[count].present = 0;
        game->t_ground[count].stage = 0;
        game->t_ground[count].last = 0;
    }
}

void destroying_condition(game_t *game, int count)
{
    sfVector2f position = {3700, 880};

    game->t_ground[count].position =
    sfSprite_getPosition(game->t_ground[count].sprite);
    if (game->t_ground[count].position.x < -100 &&
    game->t_ground[count].position.y == 880) {
        game->t_ground[count].stage = 0;
        game->t_ground[count].last = 0;
        sfSprite_setPosition(game->t_ground[count].sprite, position);
    } else if (game->t_ground[count].position.x < -100 &&
    game->t_ground[count].position.y != 880) {
        game->t_ground[count].present = 0;
        game->t_ground[count].stage = 0;
        game->t_ground[count].last = 0;
    }
}

void ground_generation(game_t *game, int count)
{
    game->t_ground[count].position =
    sfSprite_getPosition(game->t_ground[count].sprite);
    if (game->t_ground[count].position.x < 1920)
        regenerate_platform(game, count);

}

void ground_destroy(game_t *game)
{
    for (int count = 0; count != game->number_of_ground; count++) {
        if (game->t_ground[count].present == 1 && game->infinite_mode == 0)
            destroy_not_infinite(game, count);
        else if (game->t_ground[count].present == 1 && game->infinite_mode == 1)
            destroying_condition(game, count);
        if (game->t_ground[count].present == 1 &&
        game->t_ground[count].last == 1 && game->infinite_mode == 1) {
            ground_generation(game, count);
        }
    }
}

int check_gravity(game_t *game)
{
    game->player.floatrect =
    sfSprite_getGlobalBounds(game->player.sprite);
    for (int count = 0; count != game->number_of_ground;
    count++) {
        if (game->t_ground[count].present == 1) {
            game->t_ground[count].floatrect =
            sfSprite_getGlobalBounds(game->t_ground[count].sprite);
            if (sfFloatRect_intersects(&game->player.floatrect,
            &game->t_ground[count].floatrect, NULL))
                return (1);
        }
    }
    return (0);
}