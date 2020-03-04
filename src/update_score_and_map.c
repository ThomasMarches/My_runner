/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** show_player.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void update_map_and_score(game_t *game)
{
    static int score_check = 0;

    wall_destroy(game);
    ground_destroy(game);
    if (score_check == 3) {
        game->score += 1;
        score_check = 0;
    }
    score_check++;
}