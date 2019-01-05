/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions to animate the player
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Event.h>
#include <unistd.h>
#include "my_runner.h"

void player_gravity_change(player_t *player)
{
    sfVector2f grav;
    sfVector2f player_pos = sfSprite_getPosition(player->sprite);

    grav.x = 0;
    grav.y = player->gravity;
    if (player_pos.y < 450) {
        player->gravity += 0.1;
        player->is_jumping = 1;
    }
    else if (player_pos.y >= 450) {
        player->gravity = 0;
        player_pos.y = 450;
        player->is_jumping = 0;
        sfSprite_setPosition(player->sprite, player_pos);
    }
    sfSprite_move(player->sprite, grav);
}

/*Too long function*/

void anim_player(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    float elapsed_time = sfTime_asMilliseconds(time);
    static int restart = 0;

    if (elapsed_time >= player->time_move) {
        sfClock_restart(player->clock);
        if (restart == 1) {
            player->rect.left = 1280;
            player->rect.top = 0;
        }
        if (player->rect.left < 3520) {
            sfSprite_setTextureRect(player->sprite, player->rect);
            player->rect.left += 320;
            restart = 0;
        } else {
            player->rect.top = 320;
            player->rect.left = 0;
            sfSprite_setTextureRect(player->sprite, player->rect);
            restart = 1;
        }
    }
    player_gravity_change(player);
}
