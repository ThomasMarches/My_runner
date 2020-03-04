/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** parallax.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void paralax_check_position(game_t *game, int count)
{
    sfVector2f starting_point = {0, 0};

    starting_point.x = generate_number(1920, 2500);
    starting_point.y = generate_number(0, 900);
    if (game->background[count].position.x < -400 && count <= 5) {
        game->background[count].position.x = generate_number(2000, 3000);
        game->background[count].position.y = generate_number(0, 900);
        generate_planet(game, count);
        sfSprite_setPosition(game->background[count].sprite,
        game->background[count].position);
    } else if (game->background[count].position.x < -400 && count > 5) {
        game->background[count].position.x = generate_number(2000, 3000);
        game->background[count].position.y = generate_number(0, 700);
        generate_ships(game, count);
        sfSprite_setPosition(game->background[count].sprite,
        game->background[count].position);
    }
}

void paralax_planet_destroy(game_t *game)
{
    for (int count = 0; count != 10; count++) {
        sfSprite_destroy(game->background[count].sprite);
        sfTexture_destroy(game->background[count].texture);
    }
}

void paralax_move_planet(game_t *game)
{
    for (int count = 0; count != 10; count++) {
        game->background[count].position =
        sfSprite_getPosition(game->background[count].sprite);
        sfSprite_move(game->background[count].sprite,
        game->background[count].speed);
        sfRenderWindow_drawSprite(game->window,
        game->background[count].sprite, NULL);
        paralax_check_position(game, count);
    }
}

void init_parallax_planet(game_t *game, char *filepath)
{
    sfVector2f starting_point;

    for (int count = 0; count != 10; count++) {
        game->background[count].speed.y = 0;
        starting_point.x = generate_number(0, 3000);
        starting_point.y = generate_number(0, 900);
        if (count <= 5) {
            game->background[count].speed.x = generate_number(1, 2) * -1;
            game->background[count].texture =
            sfTexture_createFromFile(generate_random_filepath(generate_number(0,
            10)), NULL);
        }else {
            game->background[count].speed.x = generate_number(12, 20) * -1;
            game->background[count].texture =
            sfTexture_createFromFile(generate_random_ships(generate_number(0,
            10)), NULL);
        }
        game->background[count].sprite = sfSprite_create();
        sfSprite_setTexture(game->background[count].sprite,
        game->background[count].texture, sfTrue);
        sfSprite_setPosition(game->background[count].sprite, starting_point);
    }
}