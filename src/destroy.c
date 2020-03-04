/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** destroy.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void destroy_all_objects(game_t *game)
{
    for (int count = 0; count != game->number_of_wall; count++)
        if (game->wall[count].present == 1)
            destroy_object(game->wall[count]);
    for (int count = 0; count < 4; count++)
        if (game->ennemy[count].present == 1)
            destroy_object(game->ennemy[count]);
    for (int count = 0; count != game->number_of_ground; count++)
        if (game->t_ground[count].present == 1)
            destroy_object(game->t_ground[count]);
    if (game->bullet.present == 1)
        destroy_object(game->bullet);
    if (game->icon.present == 1)
        destroy_object(game->icon);
    destroy_object(game->button1);
    destroy_object(game->button2);
    destroy_object(game->button3);
}

void sprite_destroy(game_t *game)
{
    sfSprite_destroy(game->player.sprite);
    sfSprite_destroy(game->l_game.launch_spr);
    sfSprite_destroy(game->l_game.htpspr);
}

void texture_destroy(game_t *game)
{
    sfTexture_destroy(game->l_game.launch_txt);
    sfTexture_destroy(game->player.texture);
    sfTexture_destroy(game->l_game.htptxt);
}

void music_destroy(game_t *game)
{
    sfMusic_destroy(game->music.background);
    sfMusic_destroy(game->music.game_over);
    sfMusic_destroy(game->music.icon_music);
    sfMusic_destroy(game->music.game_music);
    sfMusic_destroy(game->music.shoot);
}

void destroy_game(game_t *game)
{
    destroy_all_objects(game);
    music_destroy(game);
    sfRenderWindow_close(game->window);
    sfRenderWindow_destroy(game->window);
    paralax_destroy(game);
    paralax_planet_destroy(game);
    texture_destroy(game);
    sprite_destroy(game);
    sfText_destroy(game->text.text);
    sfText_destroy(game->text.text_score);
    sfText_destroy(game->text.text_biggest_score);
}