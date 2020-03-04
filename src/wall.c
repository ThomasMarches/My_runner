/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** wall.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void ennemy_destroy_condition(game_t *game, int count)
{
    if (game->ennemy[count].position.x < -200) {
        sfTexture_destroy(game->ennemy[count].texture);
        sfSprite_destroy(game->ennemy[count].sprite);
        game->ennemy[count].present = 0;
        game->number_of_ennemy--;
    }
}

void ennemy_destroy(game_t *game)
{
    for (int count = 0; count < 4; count++) {
        if (game->ennemy[count].present == 1) {
            game->ennemy[count].position =
            sfSprite_getPosition(game->ennemy[count].sprite);
            ennemy_destroy_condition(game, count);
        }
    }
}

void destroying_wall(game_t *game, int count, sfVector2f position)
{
    if (game->wall[count].position.x < -80 &&
    game->infinite_mode == 0) {
        sfTexture_destroy(game->wall[count].texture);
        sfSprite_destroy(game->wall[count].sprite);
        game->wall[count].present = 0;
    } else if (game->wall[count].position.x < -80)
        sfSprite_setPosition(game->wall[count].sprite, position);
}

void wall_destroy(game_t *game)
{
    sfVector2f position = {0, 0};

    for (int count = 0; count != game->number_of_wall;
    count++) {
        position = get_position_spawn(game, 60);
        if (game->wall[count].present == 1) {
            game->wall[count].position =
            sfSprite_getPosition(game->wall[count].sprite);
            destroying_wall(game, count, position);
        }
    }
    ennemy_destroy(game);
}

void colision_with_wall_condition(game_t *game, int count)
{
    if (sfFloatRect_intersects(&game->player.floatrect,
    &game->wall[count].floatrect, NULL)) {
        game->game_over_bool = 1;
        game_over(game, "assets/Image/go.png", game->music.win);
    }
}