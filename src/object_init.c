/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** button_init.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void object_init(object_t *object, char *filepath, int x, int y)
{
    object->texture =
    sfTexture_createFromFile(filepath, NULL);
    object->sprite = sfSprite_create();
    object->position.x = x;
    object->position.y = y;
    sfSprite_setTexture(object->sprite, object->texture,
    sfTrue);
    sfSprite_setPosition(object->sprite, object->position);
}