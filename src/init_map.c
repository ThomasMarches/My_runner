/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_map.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "game.h"
#include "prototypes.h"
#include "include.h"

int init_map(char *map, game_t *game)
{
    int fd, size = 0;

    fd = open(map, O_RDONLY);
    if (fd < 0) {
        write(1, "La map que vous essayez d'ouvrir n'existe pas.", 46);
        return (84);
    }
    size = read(fd, game->map, 1000);
    game->map[size] = '\0';
    close(fd);
    if (malloc_struct_table(game) == -1
    || check_file_content(game->map) == -1
    || checking_map_content(game, map) == -1)
        return (84);
    check_number_on_map(game);
    return (0);
}