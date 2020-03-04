/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** game
*/

#include "include.h"

#ifndef GAME_H_
#define GAME_H_

typedef struct
{
    sfIntRect buttonrect;
    sfVector2f position;
    sfSprite *sprite;
    sfTexture *texture;
    bool present;
    bool last;
    int stage;
    sfIntRect present_rect;
    sfFloatRect floatrect;
    sfVector2f speed;
} object_t;

typedef struct
{
    sfMusic *background;
    sfMusic *game_music;
    sfMusic *game_over;
    sfMusic *icon_music;
    sfMusic *shoot;
    sfMusic *win;
} music_t;

typedef struct
{
    sfIntRect rect;
} player_rect_t;

typedef struct player
{
    sfVector2f position;
    int direction_x;
    int direction_y;
    sfTexture *texture;
    sfSprite *sprite;
    int speed;
    sfFloatRect present_rect;
    sfFloatRect floatrect;
} player_t;

typedef struct
{
    sfText *text;
    sfText *text_score;
    sfText *text_biggest_score;
    sfVector2f text_position;
    sfVector2f text_position_score;
    sfVector2f text_position_biggest_score;
} text_t;

typedef struct {
    sfSprite *paralaxspr;
    sfSprite *paralax2spr;
    sfTexture *paralaxtxt;
    sfTexture *paralax2txt;
    sfVector2f speed_paralax;
    sfVector2f paralax_position;
    sfVector2f paralax2_position;
    sfVector2f starting_point;
    sfVector2f starting_point2;
} paralax_t;

typedef struct
{
    sfClock *launch_clock;
    sfTime launchtime;
    sfTexture *launch_txt;
    sfSprite *launch_spr;
    sfImage *image;
    sfTexture *htptxt;
    sfSprite *htpspr;
} launch_t;

typedef struct
{
    sfVector2f jump;
    sfVector2f in_the_air;
    sfVector2f jump_fall;
} jump_t;

typedef struct
{
    sfVector2i mouse;
    int score;
    char *biggest_score;
    sfRenderWindow *window;
    sfVector2f speed_paralax;
    text_t text;
    music_t music;
    player_t player;
    paralax_t paralax;
    player_rect_t rect_player;
    jump_t jump;
    sfIntRect jump_rect;
    bool restarting;
    bool jumping;
    bool shooting;
    bool recharging;
    bool game_over_bool;
    bool closing;
    bool infinite_mode;
    bool menu;
    bool how_to_play;
    int number_of_wall;
    int number_of_ground;
    int number_of_ennemy;
    int stage;
    int number_of_planet;
    launch_t l_game;
    object_t button1;
    object_t button2;
    object_t button3;
    object_t bullet;
    object_t end_laser;
    object_t icon;
    object_t background[10];
    object_t ennemy[3];
    object_t *t_ground;
    object_t *wall;
    char map[2000];
} game_t;

typedef struct
{
    sfClock *clock;
    sfTime time;
    sfTexture *txt;
    sfSprite *spr;
} game_over_t;

#endif /* !GAME_H_ */