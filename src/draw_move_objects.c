/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** show_player.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void draw_and_move(game_t *game, object_t object)
{
    sfRenderWindow_drawSprite(game->window, object.sprite, NULL);
    sfSprite_move(object.sprite, game->speed_paralax);
}

void draw_and_move_objects(game_t *game)
{
    if (game->infinite_mode == 0)
        sfSprite_move(game->end_laser.sprite, game->speed_paralax);
    for (int count = 0; count != game->number_of_wall; count++)
        if (game->wall[count].present == 1)
            draw_and_move(game, game->wall[count]);
    for (int count = 0; count < 4; count++)
        if (game->ennemy[count].present == 1)
            draw_and_move(game, game->ennemy[count]);
    for (int count = 0; count != game->number_of_ground; count++)
        if (game->t_ground[count].present == 1)
            draw_and_move(game, game->t_ground[count]);
    if (game->game_over_bool != 1)
        sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
    if (game->bullet.present == 1)
        sfRenderWindow_drawSprite(game->window, game->bullet.sprite, NULL);
    if (game->infinite_mode == 0)
        sfRenderWindow_drawSprite(game->window, game->end_laser.sprite, NULL);
}