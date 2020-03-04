/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** icon.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void check_colision_icon(game_t *game)
{
    sfMusic_stop(game->music.icon_music);
    game->icon.position = sfSprite_getPosition(game->icon.sprite);
    game->player.position = sfSprite_getPosition(game->player.sprite);
    if (game->icon.position.x < -100) {
        destroy_object(game->icon);
        game->icon.present = 0;
    } else if (game->player.position.x > game->icon.position.x - 10 &&
    game->player.position.x < game->icon.position.x + 10) {
        destroy_object(game->icon);
        game->score += 1000;
        game->icon.present = 0;
        sfMusic_play(game->music.icon_music);
    }
}

void init_icon(game_t *game)
{
    game->icon.position.x = 1600;
    game->icon.position.y = 750;
    game->icon.texture =
    sfTexture_createFromFile("assets/Image/icon.png", NULL);
    game->icon.sprite = sfSprite_create();
    sfSprite_setTexture(game->icon.sprite,
                        game->icon.texture, sfTrue);
    sfSprite_setPosition(game->icon.sprite,
                        game->icon.position);
    game->icon.present = 1;
}

void move_icon(game_t *game)
{
    sfSprite_move(game->icon.sprite, game->speed_paralax);
    sfRenderWindow_drawSprite(game->window, game->icon.sprite, NULL);
    check_colision_icon(game);
}

void icon_check(game_t *game)
{
    int number = generate_number(0, 400);

    if (number == 42 && game->icon.present != 1 && game->infinite_mode == 1)
        init_icon(game);
}