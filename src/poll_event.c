/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** poll_event.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

int polling_event(game_t *game, sfEvent event, int number)
{
    while (sfRenderWindow_pollEvent(game->window, &event))
        if (menu_mouse_click(game, event, number) == 1)
            return (1);
    return (0);
}

void poll_event(sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (sfKeyboard_isKeyPressed(sfKeySpace) && game->jumping == 0)
        jump(game);
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->how_to_play = 0;
        object_init(&game->button1, "assets/Image/continuebtn.png", 650, 250);
        sfRenderWindow_setMouseCursorVisible(game->window, true);
        sfSprite_destroy(game->l_game.launch_spr);
        sfTexture_destroy(game->l_game.launch_txt);
        game->l_game.launch_txt =
        sfTexture_createFromFile("assets/Image/pausebackground.jpg", NULL);
        game->l_game.launch_spr = sfSprite_create();
        sfSprite_setTexture(game->l_game.launch_spr, game->l_game.launch_txt,
        sfTrue);
        menu_manage(game);
    }
    else
        check_shoot(game);
}