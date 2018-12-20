/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions to animate the player
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Event.h>
#include "my_runner.h"

void anim_player(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    float elapsed_time = sfTime_asMilliseconds(time);

    if (elapsed_time >= player->time_move) {
        sfClock_restart(player->clock);
        if (player->rect.left < 550) {
            sfSprite_setTextureRect(player->sprite, player->rect);
            player->rect.left += 110;
        } else {
            sfSprite_setTextureRect(player->sprite, player->rect);
            player->rect.left = 0;
        }
    }
}
