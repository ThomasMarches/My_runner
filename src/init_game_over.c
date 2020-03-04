/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** launch.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void init_game_over(game_t *game)
{
    game->game_over_bool = 1;
    game_over.clock = sfClock_create();
    game_over.time = sfClock_getElapsedTime(game_over.clock);
    game_over.txt = sfTexture_createFromFile(filepath, NULL);
    game_over.spr = sfSprite_create();
}