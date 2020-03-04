/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** show_player.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void draw_text(game_t *game)
{
    sfText_setString(game->text.text_score, digit_to_char(game->score));
    if (game->score > my_getnbr(game->biggest_score))
    sfText_setString(game->text.text_biggest_score,
        digit_to_char(game->score));
    sfRenderWindow_drawText(game->window, game->text.text, NULL);
    if (game->infinite_mode == 1)
        sfRenderWindow_drawText(game->window, game->text.text_biggest_score,
        NULL);
    sfRenderWindow_drawText(game->window, game->text.text_score, NULL);
}

void draw_paralax(game_t *game)
{
    paralax_move(game);
    paralax_move_planet(game);
}

void player_texture(game_t *game)
{
    sfSprite_setTexture(game->player.sprite, game->player.texture, sfTrue);
    if (game->jumping == 0)
        sfSprite_setTextureRect(game->player.sprite, game->rect_player.rect);
    else
        sfSprite_setTextureRect(game->player.sprite, game->jump_rect);
}

void check_falling(game_t *game)
{
    if (check_gravity(game) == 0) {
        recreate_sprite(game, 1);
        falling_gestion(game);
        if (game->game_over_bool == 1)
            return;
        recreate_sprite(game, 0);
    }
}

void update_games(game_t *game)
{
    game_loop(game);
    victory_check(game);
    if (game->game_over_bool == 1)
        return;
    update_map_and_score(game);
    spawn_ennemy(game);
    draw_paralax(game);
    player_texture(game);
    if (game->icon.present == 1)
        move_icon(game);
    draw_text(game);
    update_shoot(game);
    draw_and_move_objects(game);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
}