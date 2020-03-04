/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** poll_event.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void check_shoot(game_t *game)
{
    int x = 0;
    int y = 0;

    if (sfKeyboard_isKeyPressed(sfKeyR) && game->bullet.present == 0) {
        game->player.position = sfSprite_getPosition(game->player.sprite);
        sfMusic_stop(game->music.shoot);
        object_init(&game->bullet, "assets/Image/bullet.png",
        game->player.position.x + 25, game->player.position.y + 50);
        game->bullet.present = 1;
        sfMusic_play(game->music.shoot);
    }
}