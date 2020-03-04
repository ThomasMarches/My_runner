/*
** EPITECH PROJECT, 2019
** CSFML_Initiation
** File description:
** csfml_initiation.c
*/

#include "game.h"
#include <time.h>
#include "prototypes.h"
#include "include.h"

int sfml_game_start(char **argv)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return (-1);
    init_game(game);
    if (my_strcmp(argv[1], "-i") == 0)
        random_map_generation(game);
    else if (init_map(argv[1], game) == 84)
        return (-1);
    text_init(game);
    start_game(game);
    destroy_game(game);
    if (game->restarting == 1) {
        game->closing = 0;
        sfml_game_start(argv);
    }
    free(game);
    return (0);
}

int show_read_me(char **argv)
{
    FILE *fd;
    char *map = malloc(sizeof(char) * 270);
    int nb = 0;

    fd = fopen("usage.txt", "r");
    nb = fread(map, 268, 1, fd);
    write(1, map, 268);
    fclose(fd);
    free(map);
    return (0);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    if (ac != 2)
        return (84);
    else if (my_strcmp(av[1], "-h") == 0)
        return (show_read_me(av));
    if (sfml_game_start(av) == -1)
        return (84);
    return (0);
}