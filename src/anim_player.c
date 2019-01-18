/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions to animate the player
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Event.h>
#include <unistd.h>
#include <stdio.h>
#include "lib.h"
#include "my_runner.h"

int player_gravity_change(player_t *player, object_t *objects)
{
    sfVector2f grav;
    sfVector2f player_pos = sfSprite_getPosition(player->sprite);
    int pos_y = is_player_on_ground(player, objects);

    grav.x = 0;
    grav.y = player->gravity;
    if (pos_y == -1) {
        player->gravity += 0.2;
        player->is_jumping = 1;
    }
    else if (pos_y != -1) {
        player_pos.y = pos_y - 100;
        player->is_jumping = 0;
        sfSprite_setPosition(player->sprite, player_pos);
    }
    if (pos_y == -2)
        return (1);
    sfSprite_move(player->sprite, grav);
    return (0);
}

void run_anim(player_t *player)
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
            player->rect.left += 320;
            restart = 0;
        } else {
            player->rect.top = 320;
            player->rect.left = 0;
           restart = 1;
        }
    }
}

void anim_player(player_t *player, object_t *objects, sfRenderWindow *window)
{
    if (player->gravity == 0.0 && player->is_jumping == 0) {
        if (player->rect.top > 0) {
            player->rect.top = 0;
            player->rect.left = 1280;
        }
        run_anim(player);
    }
    else if (player->gravity > 0.0) {
        player->rect.top = 640;
        player->rect.left = 320;
    } else {
        player->rect.top = 320;
        player->rect.left = 1600;
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
    player->is_dead = player_gravity_change(player, objects);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    check_collisions(objects, player);
}
