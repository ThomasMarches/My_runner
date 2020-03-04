/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** player.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

int how_to_play(game_t *game)
{
    sfEvent event;

    game->player.present_rect =
    sfSprite_getGlobalBounds(game->button3.sprite);
    if (sfFloatRect_contains(&game->player.present_rect,
        game->mouse.x, game->mouse.y) == 0)
        return (0);
    while (1) {
        game->how_to_play = 1;
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->l_game.launch_spr, NULL);
        sfRenderWindow_drawSprite(game->window, game->button2.sprite, NULL);
        sfRenderWindow_drawSprite(game->window, game->l_game.htpspr, NULL);
        sfRenderWindow_display(game->window);
        if (polling_event(game, event, 0) == 1) {
            game->how_to_play = 0;
            return (1);
        }
    }
    return (0);
}