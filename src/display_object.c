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
    object_t *curs = object;
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asMilliseconds(time);
    int restart = 0;

    if (seconds >= 10.0) {
        sfClock_restart(clock);
        restart = 1;
    }
    while (curs != NULL) {
        offset.x = -5;
        offset.y = 0;
        if (restart == 1)
            sfSprite_move(curs->sprite, offset);
        sfRenderWindow_drawSprite(window, curs->sprite, NULL);
        curs = curs->next;
    }
}
