/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_map.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void destroying_ennemy_colision(game_t *game, int count)
{
    if (sfFloatRect_intersects(&game->player.floatrect,
    &game->ennemy[count].floatrect, NULL)) {
        game->game_over_bool = 1;
        game_over(game, "assets/Image/go.png", game->music.game_over);
    }
}

void check_colision_ennemy(game_t *game)
{
    game->how_to_play = 0;
    game->player.floatrect =
    sfSprite_getGlobalBounds(game->player.sprite);
    for (int count = 0; count < 4; count++) {
        if (game->ennemy[count].present == 1) {
            game->ennemy[count].floatrect =
            sfSprite_getGlobalBounds(game->ennemy[count].sprite);
            destroying_ennemy_colision(game, count);
        }
    }
}

void create_ennemy(game_t *game, int number)
{
    sfVector2f position = get_position_spawn(game, 80);

    if (position.x == 0 && position.y == 0)
        return;
    game->ennemy[number].texture =
    sfTexture_createFromFile("assets/Image/ennemy.png", NULL);
    game->ennemy[number].sprite = sfSprite_create();
    game->ennemy[number].position.x = position.x;
    game->ennemy[number].position.y = position.y;
    sfSprite_setTexture(game->ennemy[number].sprite,
    game->ennemy[number].texture,
    sfTrue);
    sfSprite_setPosition(game->ennemy[number].sprite,
    game->ennemy[number].position);
    game->ennemy[number].present = 1;
    game->number_of_ennemy++;
}

void spawn_ennemy(game_t *game)
{
    int number = generate_number(0, 200);

    for (int count = 0; count < 4; count++)
        if (game->ennemy[count].present == 0 && number > 150) {
            number = generate_number(0, 200);
            create_ennemy(game, count);
        }
}