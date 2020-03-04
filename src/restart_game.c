/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** player.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

int restart_game(game_t *game)
{
    if (game->game_over_bool == 1)
        game->restarting = 1;
    return (1);
}