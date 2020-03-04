/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** launch.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void change_menu_background(game_t *game, char *filepath)
{
    sfSprite_destroy(game->l_game.launch_spr);
    sfTexture_destroy(game->l_game.launch_txt);
    game->l_game.launch_txt =
    sfTexture_createFromFile(filepath, NULL);
    game->l_game.launchtime =
    sfClock_getElapsedTime(game->l_game.launch_clock);
    game->l_game.launch_spr = sfSprite_create();
    sfSprite_setTexture(game->l_game.launch_spr, game->l_game.launch_txt,
    sfTrue);
}

int clock_launching_game(game_t *game)
{
    float seconds;
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    sfRenderWindow_drawSprite(game->window, game->l_game.launch_spr, NULL);
    sfRenderWindow_display(game->window);
    game->l_game.launchtime =
    sfClock_getElapsedTime(game->l_game.launch_clock);
    seconds = game->l_game.launchtime.microseconds / 1000000.0;
    if (seconds > 4.0) {
        change_menu_background(game, "assets/Image/launching_screen2.jpg");
        sfClock_destroy(game->l_game.launch_clock);
        object_init(&game->button1, "assets/Image/button1.png", 650, 250);
        object_init(&game->button3, "assets/Image/howtoplay.png", 650, 450);
        object_init(&game->button2, "assets/Image/button2.png", 650, 650);
        return (menu_manage(game));
    }
    return (0);
}

void init_launch(game_t *game)
{
    sfVector2f position = {300, 250};

    game->l_game.htptxt =
    sfTexture_createFromFile("assets/Image/htp.png", NULL);
    game->l_game.htpspr = sfSprite_create();
    sfSprite_setTexture(game->l_game.htpspr, game->l_game.htptxt,
    sfTrue);
    sfSprite_setPosition(game->l_game.htpspr, position);
    game->l_game.launch_clock = sfClock_create();
    game->l_game.launch_txt =
    sfTexture_createFromFile("assets/Image/launchingscreen.jpg", NULL);
    game->l_game.launchtime = sfClock_getElapsedTime(game->l_game.launch_clock);
    game->l_game.launch_spr = sfSprite_create();
    sfSprite_setTexture(game->l_game.launch_spr, game->l_game.launch_txt,
    sfTrue);
}

void launching_game(game_t *game)
{
    int opened = 0;
    static int launch = 0;

    object_init(&game->button1, "assets/Image/continuebtn.png", 650, 250);
    object_init(&game->button3, "assets/Image/howtoplay.png", 650, 450);
    object_init(&game->button2, "assets/Image/button2.png", 650, 650);
    if (launch == 1)
        return;
    sfMusic_play(game->music.background);
    while (opened == 0)
        opened = clock_launching_game(game);
    if (game->game_over_bool == 1)
        return;
    sfRenderWindow_clear(game->window, sfBlack);
    launch++;
}