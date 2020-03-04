/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_map.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "game.h"
#include "prototypes.h"
#include "include.h"

int malloc_struct_table(game_t *game)
{
    int obstacle = 0;
    int ground = 0;

    for (int count = 0; game->map[count] != '\0'; count++) {
        if (game->map[count] == '1')
            ground++;
        else if (game->map[count] == '2' || game->map[count] == '3')
            obstacle++;
    }
    game->t_ground = malloc(sizeof(object_t) * ground + 1);
    game->wall = malloc(sizeof(object_t) * obstacle + 1);
    if (game->t_ground == NULL || game->wall == NULL)
        return (-1);
    return (0);
}