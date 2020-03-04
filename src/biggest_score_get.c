/*
** EPITECH PROJECT, 2019
** Hunter2.0 (copy)
** File description:
** biggest_score_get.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "game.h"
#include "prototypes.h"
#include "include.h"

char *fill_map(char *map)
{
    FILE *fd;

    fd = fopen("assets/Score/biggest_score.txt", "r");
    fread(map, 8, 1, fd);
    fwrite(map, 8, 1, fd);
    fclose(fd);
    return (map);
}

void get_biggest_score(game_t *game)
{
    int score = 0;
    char *line = malloc(sizeof(char) * 8);
    int i = 0;

    line = fill_map(line);
    score = my_getnbr(line);
    free(line);
    game->biggest_score = digit_to_char(score);
}

void set_biggest_score(game_t *game)
{
    FILE *fd;

    fd = fopen("assets/Score/biggest_score.txt", "w");
    fwrite(digit_to_char(game->score), 8, 1, fd);
    fclose(fd);
}