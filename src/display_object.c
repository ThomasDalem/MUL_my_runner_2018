/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions to display the object on the screen
*/
#include <SFML/Graphics/RenderWindow.h>
#include <unistd.h>
#include "my_runner.h"

void display_objects(object_t *object, sfRenderWindow *window, sfClock *clock)
{
    sfVector2f offset;
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asMilliseconds(time);
    sfVector2f obj_pos;
    int restart = 0;

    if (seconds >= 7.0) {
        sfClock_restart(clock);
        restart = 1;
    }
    while (object != NULL) {
        offset.x = -5;
        offset.y = 0;
        obj_pos = sfSprite_getPosition(object->sprite);
        if (restart == 1)
            sfSprite_move(object->sprite, offset);
        if (obj_pos.x < 2000 && obj_pos.x > -100)
            sfRenderWindow_drawSprite(window, object->sprite, NULL);
        object = object->next;
    }
}
