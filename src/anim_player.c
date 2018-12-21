/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions to animate the player
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Event.h>
#include "my_runner.h"

void player_gravity_change(player_t *player)
{
    sfVector2f grav;
    grav.x = 0;
    static float angle = 0.0;

    grav.y = player->gravity;
    if (sfSprite_getPosition(player->sprite).y < 500)
        player->gravity += 0.1;
    else if (sfSprite_getPosition(player->sprite).y >= 500)
        player->gravity = 0.0;
    if (player->gravity > 0.0) {
        if (angle < 50.0)
            angle += 1.0;
    }
    else if (player->gravity < 0.0) {
        if (angle > -50.0)
            angle -= 1.0;
    }
    else
       angle = 0;
    sfSprite_setRotation(player->sprite, angle);
    sfSprite_move(player->sprite, grav);
}

void anim_player(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    float elapsed_time = sfTime_asMilliseconds(time);

    if (elapsed_time >= player->time_move) {
        sfClock_restart(player->clock);
        if (player->rect.left < 152) {
            sfSprite_setTextureRect(player->sprite, player->rect);
            player->rect.left += 76;
        } else {
            sfSprite_setTextureRect(player->sprite, player->rect);
            player->rect.left = 0;
        }
    }
    player_gravity_change(player);
}
