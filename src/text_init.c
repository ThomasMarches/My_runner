/*
** EPITECH PROJECT, 2019
** Hunter2.0 (copy)
** File description:
** text_init.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void text_init_score(game_t *game)
{
    sfFont *font = sfFont_createFromFile("assets/Fonts/space.ttf");

    game->text.text_position_score.x = 500;
    game->text.text_position_score.y = 10;
    game->text.text_score = sfText_create();
    sfText_setFont(game->text.text_score, font);
    sfText_setStyle(game->text.text_score, sfTextBold);
    sfText_setCharacterSize(game->text.text_score, 50);
    sfText_setString(game->text.text_score, digit_to_char(game->score));
    sfText_setPosition(game->text.text_score, game->text.text_position_score);
}

void text_init(game_t *game)
{
    sfFont *font = sfFont_createFromFile("assets/Fonts/space.ttf");

    game->score = 0;
    game->text.text_position.x = 20;
    game->text.text_position.y = 10;
    game->text.text = sfText_create();
    sfText_setFont(game->text.text, font);
    sfText_setStyle(game->text.text, sfTextBold);
    sfText_setCharacterSize(game->text.text, 50);
    if (game->infinite_mode == 1)
        sfText_setString(game->text.text, "Your score\nBiggest score");
    else
        sfText_setString(game->text.text, "Your score");
    sfText_setPosition(game->text.text, game->text.text_position);
    text_init_score(game);
    text_init_biggest_score(game);
}

void text_init_biggest_score(game_t *game)
{
    sfFont *font = sfFont_createFromFile("assets/Fonts/space.ttf");

    get_biggest_score(game);
    game->text.text_position_biggest_score.x = 600;
    game->text.text_position_biggest_score.y = 60;
    game->text.text_biggest_score = sfText_create();
    sfText_setFont(game->text.text_biggest_score, font);
    sfText_setStyle(game->text.text_biggest_score, sfTextBold);
    sfText_setCharacterSize(game->text.text_biggest_score, 50);
    sfText_setString(game->text.text_biggest_score, game->biggest_score);
    sfText_setPosition(game->text.text_biggest_score,
    game->text.text_position_biggest_score);
}