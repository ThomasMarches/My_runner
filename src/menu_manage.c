/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** player.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

int check_click_on_button(game_t *game, object_t object, sfEvent event)
{
    if (event.type != sfEvtMouseButtonReleased)
        return (0);
    game->mouse = sfMouse_getPositionRenderWindow(game->window);
    object.floatrect =
    sfSprite_getGlobalBounds(object.sprite);
    if (sfFloatRect_contains(&object.floatrect,
    game->mouse.x, game->mouse.y) == 1)
        return (1);
    else
        return (0);
}

int menu_mouse_click(game_t *game, sfEvent event, int number)
{
    game->mouse = sfMouse_getPositionRenderWindow(game->window);
    if (event.type == sfEvtMouseButtonReleased) {
        game->player.present_rect =
        sfSprite_getGlobalBounds(game->button1.sprite);
        if (sfFloatRect_contains(&game->player.present_rect,
        game->mouse.x, game->mouse.y) == 1)
            return (restart_game(game));
        game->player.present_rect =
        sfSprite_getGlobalBounds(game->button2.sprite);
        if (sfFloatRect_contains(&game->player.present_rect,
        game->mouse.x, game->mouse.y) == 1) {
            game->game_over_bool = 1;
            game_over(game, "assets/Image/go.png", game->music.game_over);
            return (1);
        }
        if (number == 1)
            how_to_play(game);
    }
    return (0);
}

int menu_manage(game_t *game)
{
    sfEvent event;
    int clicked = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, true);
    while (1) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->l_game.launch_spr, NULL);
        sfRenderWindow_drawSprite(game->window, game->button1.sprite, NULL);
        sfRenderWindow_drawSprite(game->window, game->button2.sprite, NULL);
        sfRenderWindow_drawSprite(game->window, game->button3.sprite, NULL);
        sfRenderWindow_display(game->window);
        if (polling_event(game, event, 1) == 1) {
            sfRenderWindow_setMouseCursorVisible(game->window, false);
            return (1);
        }
    }
    return (1);
}