/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** manage_game_advancing.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void manage_game_advancing(game_t *game)
{
    if (game->score > 5000 && game->stage == 1) {
        game->stage = 2;
        paralax_destroy(game);
        init_parallax(game, "assets/Image/Background2.jpg",
        "assets/Image/Reversebg2.jpg");
    } else if (game->score > 10000 && game->stage == 2) {
        game->stage = 3;
        paralax_destroy(game);
        init_parallax(game, "assets/Image/Background3.jpg",
        "assets/Image/Background3.jpg");
    }
}