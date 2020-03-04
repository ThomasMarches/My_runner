/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** parallax.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void paralax_check(game_t *game)
{
    if (game->paralax.paralax_position.x == -1910) {
        sfSprite_setPosition(game->paralax.paralaxspr,
        game->paralax.starting_point);
    }
    if (game->paralax.paralax2_position.x == -1910) {
        sfSprite_setPosition(game->paralax.paralax2spr,
        game->paralax.starting_point);
    }
}

void paralax_destroy(game_t *game)
{
    sfSprite_destroy(game->paralax.paralax2spr);
    sfSprite_destroy(game->paralax.paralaxspr);
    sfTexture_destroy(game->paralax.paralax2txt);
    sfTexture_destroy(game->paralax.paralaxtxt);
}

void paralax_move(game_t *game)
{
    game->paralax.speed_paralax.x = -1;
    game->paralax.speed_paralax.y = 0;
    game->paralax.paralax_position =
    sfSprite_getPosition(game->paralax.paralaxspr);
    game->paralax.paralax2_position =
    sfSprite_getPosition(game->paralax.paralax2spr);
    sfSprite_move(game->paralax.paralaxspr, game->paralax.speed_paralax);
    sfSprite_move(game->paralax.paralax2spr, game->paralax.speed_paralax);
    sfRenderWindow_drawSprite(game->window, game->paralax.paralaxspr, NULL);
    sfRenderWindow_drawSprite(game->window, game->paralax.paralax2spr, NULL);
    paralax_check(game);
}

void init_parallax(game_t *game, char *filepath, char *second)
{
    game->paralax.starting_point2.x = 0;
    game->paralax.starting_point2.y = 0;
    game->paralax.starting_point.x = 1920;
    game->paralax.starting_point.y = 0;
    game->paralax.paralaxtxt =
    sfTexture_createFromFile(filepath, NULL);
    game->paralax.paralaxspr = sfSprite_create();
    game->paralax.paralax2txt =
        sfTexture_createFromFile(second, NULL);
    game->paralax.paralax2spr = sfSprite_create();
    sfSprite_setTexture(game->paralax.paralaxspr,
    game->paralax.paralaxtxt, sfTrue);
    sfSprite_setTexture(game->paralax.paralax2spr,
    game->paralax.paralax2txt, sfTrue);
    sfSprite_setPosition(game->paralax.paralax2spr,
    game->paralax.starting_point);
}