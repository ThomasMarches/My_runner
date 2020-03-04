/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** player.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void move_player_rect(game_t *game)
{
    int offset = 0;
    int max_value = 0;

    if (game->jumping == 1) {
        offset = 100;
        max_value = 600;
    } else {
        offset = 110;
        max_value = 880;
    }
    if (game->rect_player.rect.left + offset <= max_value)
        game->rect_player.rect.left += offset;
    else
        game->rect_player.rect.left = 0;
}