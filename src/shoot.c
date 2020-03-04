/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** poll_event.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void destroying_ennemy_and_bullet(game_t *game, int count)
{
    if (sfFloatRect_intersects(&game->bullet.floatrect,
    &game->ennemy[count].floatrect, NULL)) {
        destroy_object(game->ennemy[count]);
        destroy_object(game->bullet);
        game->score += 100;
        game->number_of_ennemy--;
        game->ennemy[count].present = 0;
        game->bullet.present = 0;
    }
}

void check_ennemy_and_bullet_colision(game_t *game)
{
    if (game->bullet.present == 0)
        return;
    game->bullet.floatrect =
        sfSprite_getGlobalBounds(game->bullet.sprite);
    for (int count = 0; count != 4;
    count++) {
        if (game->ennemy[count].present == 1) {
            game->ennemy[count].floatrect =
            sfSprite_getGlobalBounds(game->ennemy[count].sprite);
            destroying_ennemy_and_bullet(game, count);
        }
    }
}

void destroying_bullet(game_t *game, int count)
{
    if (sfFloatRect_intersects(&game->wall[count].floatrect,
    &game->bullet.floatrect, NULL)) {
        destroy_object(game->bullet);
        game->bullet.present = 0;
    }
}

void check_bullet_colision(game_t *game)
{
    game->bullet.position = sfSprite_getPosition(game->bullet.sprite);
    if (game->bullet.position.x > 1920) {
        destroy_object(game->bullet);
        game->bullet.present = 0;
        return;
    }
    for (int count = 0; count != game->number_of_wall;
    count++)
        if (game->wall[count].present == 1) {
            game->wall[count].floatrect =
            sfSprite_getGlobalBounds(game->wall[count].sprite);
            game->bullet.floatrect =
            sfSprite_getGlobalBounds(game->bullet.sprite);
            destroying_bullet(game, count);
        }
    check_ennemy_and_bullet_colision(game);
}

void update_shoot(game_t *game)
{
    sfVector2f speed = {20, 0};

    if (game->bullet.present == 0)
        return;
    sfSprite_move(game->bullet.sprite, speed);
}