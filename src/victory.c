/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** poll_event.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void victory_check(game_t *game)
{
    int count = 0;

    if (game->infinite_mode == 1)
        return;
    game->player.floatrect =
        sfSprite_getGlobalBounds(game->player.sprite);
    game->end_laser.floatrect =
        sfSprite_getGlobalBounds(game->end_laser.sprite);
    if (sfFloatRect_intersects(&game->player.floatrect,
    &game->end_laser.floatrect, NULL)) {
        game->game_over_bool = 1;
        game_over(game, "assets/Image/win.jpg", game->music.win);
    }
}