/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** music.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void set_volume(game_t *game, float volume)
{
    sfMusic_setVolume(game->music.background, volume);
    sfMusic_setVolume(game->music.game_music, volume);
    sfMusic_setVolume(game->music.icon_music, volume);
    sfMusic_setVolume(game->music.shoot, volume);
    sfMusic_setVolume(game->music.win, volume);
    sfMusic_setVolume(game->music.game_over, volume);
}

void music_init(game_t *game)
{
    game->music.background = sfMusic_createFromFile("assets/Music/launch.ogg");
    game->music.game_music = sfMusic_createFromFile("assets/Music/music.ogg");
    game->music.game_over = sfMusic_createFromFile("assets/Music/gameover.ogg");
    game->music.icon_music = sfMusic_createFromFile("assets/Music/icon.ogg");
    game->music.shoot = sfMusic_createFromFile("assets/Music/shoot.wav");
    game->music.win = sfMusic_createFromFile("assets/Music/win.ogg");
    set_volume(game, 0);
}