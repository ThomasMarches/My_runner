/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** player.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void destroy_object(object_t object)
{
    sfSprite_destroy(object.sprite);
    sfTexture_destroy(object.texture);
}