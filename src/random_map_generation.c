/*
** EPITECH PROJECT, 2019
** CSFML_Initiation
** File description:
** csfml_initiation.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void deal_position(game_t *game, int spawned, int count, sfVector2f position)
{
    static int number_position = 0;

    if (spawned == 1)
        number_position = generate_number(1, 3);
    position.x = 1920 + (spawned + number_position) * 60;
    sfSprite_setPosition(game->t_ground[count].sprite, position);
    game->t_ground[count].present = 1;
}

void regenerate_platform(game_t *game, int number)
{
    int number_of_ground = generate_number(3, 15);
    int position_of_ground = generate_number(11, 18);
    sfVector2f position = {0, 0};
    int count = 65;
    int spawned = 0;

    position.y = position_of_ground * 40;
    game->t_ground[number].last = 0;
    for (; spawned != number_of_ground &&
    count != game->number_of_ground; count++) {
        if (game->t_ground[count].present == 0) {
            spawned++;
            deal_position(game, spawned, count, position);
        }
    }
    game->t_ground[count - 1].last = 1;
}

void generate_random_platform(game_t *game)
{
    int number_of_ground = generate_number(3, 15);
    int position_of_ground = generate_number(11, 18);
    int count = 0;

    for (count = 0; count != 125; count++) {
        if (game->t_ground[count].present == 0) {
            create_ground(-32 + game->number_of_ground,
            position_of_ground, game);
            game->t_ground[count].present = 0;
        }
    }
    for (count = 64; count != 64 + number_of_ground; count++)
        game->t_ground[count].present = 1;
    game->t_ground[count - 1].last = 1;
}

int random_map_generation(game_t *game)
{
    game->t_ground = malloc(sizeof(object_t) * 125);
    game->wall = malloc(sizeof(object_t) * 3);
    sfVector2f position = {0, 0};

    if (game->t_ground == NULL || game->wall == NULL)
        return (-1);
    for (int count = 0; count != 65; count++)
        create_ground(count, 22, game);
    for (int count = 0; count != 3; count++) {
        position = get_position_spawn(game, 60);
        if (generate_number(0, 200) < 100)
            create_obstacle_s(position.x, position.y + 20, game,
            "assets/Image/obstacle.png");
        else
            create_obstacle_s(position.x, position.y, game,
            "assets/Image/obstacle2.png");
    }
    generate_random_platform(game);
    game->infinite_mode = 1;
    return (0);
}