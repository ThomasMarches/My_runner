/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_map.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void create_my_objects(game_t *game, int counter, int count, int line)
{
    if (game->map[counter] == '1')
        create_ground(count, line, game);
    else if (game->map[counter] == '2')
        create_obstacle(count, line, game, "assets/Image/obstacle.png");
    if (game->map[counter] == '3')
        create_obstacle(count, line, game, "assets/Image/obstacle2.png");
}

void check_number_on_map(game_t *game)
{
    int counter = 0;

    game->end_laser.position.x = 0;
    game->end_laser.position.y = 0;
    for (int count = 0, line = 0; game->map[counter] != '\0';
    counter++, count++) {
        if (game->map[counter] == '\n') {
            line++;
            count = 0;
        }
        create_my_objects(game, counter, count, line);
    }
    object_init(&game->end_laser, "assets/Image/laser.png",
    game->end_laser.position.x + 20, 0);
}