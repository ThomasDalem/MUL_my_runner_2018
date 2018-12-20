/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Moves the background
*/
#include "my_runner.h"

void anim_background(background_t *background)
{
    sfTime time = sfClock_getElapsedTime(background->clock);
    float elapsed_time = sfTime_asMilliseconds(time);

    if (elapsed_time >= background->move_delay) {
        sfClock_restart(background->clock);
        if (background->rect.left < 960) {
            sfSprite_setTextureRect(background->sprite, background->rect);
            background->rect.left += 1;
        } else {
            sfSprite_setTextureRect(background->sprite, background->rect);
            background->rect.left = 0;
        }
    }
}
