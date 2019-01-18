/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** Functions to use the player struct
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "my_runner.h"

player_t *create_player(float move_time)
{
    player_t *player = malloc(sizeof(player_t));
    char *filepath = "./ressources/player.png";
    sfVector2f scale;

    scale.x = 0.3;
    scale.y = 0.3;
    if (player == NULL)
        return (NULL);
    player->clock = sfClock_create();
    player->texture = sfTexture_createFromFile(filepath, NULL);
    player->sprite = sfSprite_create();
    player->time_move = move_time;
    player->is_jumping = 1;
    player->gravity = 0.0;
    player->rect = create_rect(320, 320);
    player->is_dead = 0;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setScale(player->sprite, scale);
    scale.y = 300;
    sfSprite_setPosition(player->sprite, scale);
    return (player);
}

void destroy_player(player_t *player)
{
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    sfClock_destroy(player->clock);
    free(player);
}
