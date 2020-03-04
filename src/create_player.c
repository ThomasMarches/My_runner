/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** player.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void player_spawn(game_t *game)
{
    game->player.texture =
    sfTexture_createFromFile("assets/Image/22.png", NULL);
    game->player.sprite = sfSprite_create();
    game->player.position.x = 200;
    game->player.position.y = 0;
    sfSprite_setPosition(game->player.sprite, game->player.position);
}

void create_player(game_t *game)
{
    player_spawn(game);
    game->rect_player.rect.top = 0;
    game->rect_player.rect.left = 0;
    game->rect_player.rect.width = 110;
    game->rect_player.rect.height = 125;
    game->jump_rect.top = 0;
    game->jump_rect.left = 0;
    game->jump_rect.width = 100;
    game->jump_rect.height = 125;
    game->jump.jump.x = 0;
    game->jump.jump.y = 0;
}