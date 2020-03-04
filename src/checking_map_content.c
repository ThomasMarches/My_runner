/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_map.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

int check_one_line(ssize_t read, char *line, char *filepath)
{
    for (int count = 0; count != read; count++)
        if (line[count] != '1' && line[count] != ' ') {
            write (1, "Le fichier de map: ", 19);
            write (1, filepath, my_strlen(filepath));
            write (1, " n'est pas valide.", 18);
            write (1, " Veuillez vérifier que la ligne 22", 35);
            write (1, " contienne bien uniquement des 1 ou des espaces.", 48);
            write (1, " Veuillez lire le fichier '.legend' pour vous", 45);
            write (1, " informer sur la création d'une map valide.", 43);
            return (-1);
        }
    return (0);
}

int check_line_22(game_t *game, char *filepath)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filepath, "r");
    for (int count = 0; count != 22; count++)
        read = getline(&line, &len, fp);
    if (check_one_line(read, line, filepath) == - 1)
        return (-1);
    if (line)
        free(line);
    return (0);
}

int checking_map_content(game_t *game, char *filepath)
{
    for (int counter = 0; game->map[counter] != '\0';
    counter++) {
        if (game->map[counter] != '1' && game->map[counter] != '2' &&
        game->map[counter] != '3' && game->map[counter] != ' ' &&
        game->map[counter] != '\n' && game->map[counter] != '\0') {
            write (1, "Le fichier de map: ", 19);
            write (1, filepath, my_strlen(filepath));
            write (1, " contient des charactères non valides.", 39);
            write (1, " Veuillez lire le fichier '.legend' pour vous", 45);
            write (1, " informer sur la création d'une map valide.", 43);
            return (-1);
        }
    }
    return (check_line_22(game, filepath));
}

int check_file_content(char *map)
{
    if (map[0] == '\0') {
        write(1, "Votre fichier de map est vide.", 30);
        return (-1);
    }
    return (0);
}