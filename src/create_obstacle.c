/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_map.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void create_obstacle(int count, int line, game_t *game, char *filepath)
{
    game->wall[game->number_of_wall].texture =
    sfTexture_createFromFile(filepath, NULL);
    game->wall[game->number_of_wall].sprite = sfSprite_create();
    game->wall[game->number_of_wall].position.x = count * 60;
    game->wall[game->number_of_wall].position.y = line * 40 - 15;
    sfSprite_setTexture(game->wall[game->number_of_wall].sprite,
    game->wall[game->number_of_wall].texture, sfTrue);
    sfSprite_setPosition(game->wall[game->number_of_wall].sprite,
    game->wall[game->number_of_wall].position);
    game->wall[game->number_of_wall].present = 1;
    game->number_of_wall++;
}

int create_obstacle_s(int count, int line, game_t *game, char *filepath)
{
    if (count == 0)
        return (0);
    game->wall[game->number_of_wall].texture =
    sfTexture_createFromFile(filepath, NULL);
    game->wall[game->number_of_wall].sprite = sfSprite_create();
    game->wall[game->number_of_wall].position.x = count;
    game->wall[game->number_of_wall].position.y = line - 15;
    sfSprite_setTexture(game->wall[game->number_of_wall].sprite,
    game->wall[game->number_of_wall].texture, sfTrue);
    sfSprite_setPosition(game->wall[game->number_of_wall].sprite,
    game->wall[game->number_of_wall].position);
    game->wall[game->number_of_wall].present = 1;
    game->number_of_wall++;
    return (1);
}
