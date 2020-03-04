/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** jump.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void recreate_sprite(game_t *game, int number)
{
    sfVector2f position = sfSprite_getPosition(game->player.sprite);

    if (number == 1) {
        sfSprite_destroy(game->player.sprite);
        sfTexture_destroy(game->player.texture);
        game->player.texture =
        sfTexture_createFromFile("assets/Image/jumping.png", NULL);
        game->player.sprite = sfSprite_create();
        sfSprite_setPosition(game->player.sprite, position);
    } else {
        sfSprite_destroy(game->player.sprite);
        sfTexture_destroy(game->player.texture);
        game->player.texture = sfTexture_createFromFile("assets/Image/22.png",
        NULL);
        game->player.sprite = sfSprite_create();
        sfSprite_setPosition(game->player.sprite, position);
    }

}

void falling_gestion(game_t *game)
{
    sfEvent event;

    game->jump.jump.y = 0;
    while (check_gravity(game) == 0) {
        game->player.position = sfSprite_getPosition(game->player.sprite);
        while (sfRenderWindow_pollEvent(game->window, &event))
            poll_event(event, game);
        sfSprite_move(game->player.sprite, game->jump.jump);
        update_games(game);
        if (game->player.position.y >= 1080) {
            game->game_over_bool = 1;
            game_over(game, "assets/Image/go.png", game->music.game_over);
        }
        game->jump.jump.y += 0.75;
    }
}

void manage_jump_speed(game_t *game)
{
    sfEvent event;
    sfVector2f starting_position = sfSprite_getPosition(game->player.sprite);
    game->player.position = sfSprite_getPosition(game->player.sprite);

    while (game->player.position.y > starting_position.y - 400 &&
    game->player.position.y > 50) {
        while (sfRenderWindow_pollEvent(game->window, &event))
            poll_event(event, game);
        game->player.position = sfSprite_getPosition(game->player.sprite);
        sfSprite_move(game->player.sprite, game->jump.jump);
        update_games(game);
        game->jump.jump.y -= 1;
    }
    falling_gestion(game);
}

void jump(game_t *game)
{
    if (game->jumping == 1)
        return;
    game->jumping = 1;
    game->jump.jump.y = 0;
    recreate_sprite(game, 1);
    manage_jump_speed(game);
    recreate_sprite(game, 0);
    game->jumping = 0;
    game->jump.jump.y = 0;
}