/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** game.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void init_struct(game_t *game)
{
    game->score = 0;
    game->restarting = 0;
    game->closing = 0;
    game->jumping = 0;
    game->menu = 1;
    game->how_to_play = 1;
    game->bullet.present = 0;
    game->game_over_bool = 0;
    game->stage = 1;
    game->number_of_ennemy = 0;
    game->number_of_ground = 0;
    game->number_of_wall = 0;
    game->speed_paralax.x = -15;
    game->speed_paralax.y = 0;
}

void init_game(game_t *game)
{
    if (game->restarting == 1) {
        free(game);
        game_t *game = malloc(sizeof(game_t));
    }
    init_struct(game);
    game->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "My Runner", sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(game->window, false);
    sfRenderWindow_setFramerateLimit(game->window, 30);
    init_parallax(game, "assets/Image/Background1.jpg",
    "assets/Image/Background1.jpg");
    object_init(&game->bullet, "assets/Image/bullet.png", 230, 850);
    init_parallax_planet(game, "assets/Image/planet.png");
    music_init(game);
    create_player(game);
    init_launch(game);
}

void game_loop(game_t *game)
{
    if (game->infinite_mode == 1)
        icon_check(game);
    if (game->number_of_wall != 0)
        check_colision_wall(game);
    if (game->number_of_ennemy != 0)
        check_colision_ennemy(game);
    if (game->bullet.present == 1)
        check_bullet_colision(game);
}

void start_game(game_t *game)
{
    sfEvent event;
    sfClock *clock = sfClock_create();

    launching_game(game);
    sfMusic_play(game->music.game_music);
    if (game->game_over_bool == 1)
        return;
    sfRenderWindow_setMouseCursorVisible(game->window, false);
    while (sfRenderWindow_isOpen(game->window) && game->game_over_bool == 0) {
        check_falling(game);
        update_games(game);
        while (sfRenderWindow_pollEvent(game->window, &event))
            poll_event(event, game);
        if (sfClock_getElapsedTime(clock).microseconds / 100000.0 >= 1.0) {
            move_player_rect(game);
            sfClock_restart(clock);
        }
        manage_game_advancing(game);
    }
}