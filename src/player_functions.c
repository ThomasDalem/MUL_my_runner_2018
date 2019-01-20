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

void create_player_sprite(player_t *player)
{
    char *filepath = "./ressources/player.png";
    sfVector2f scale;
    sfVector2f pos;

    scale.x = 0.3;
    scale.y = 0.3;
    pos.x = 0;
    pos.y = 300;
    player->texture = sfTexture_createFromFile(filepath, NULL);
    player->sprite = sfSprite_create();
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setScale(player->sprite, scale);
    sfSprite_setPosition(player->sprite, pos);
}

player_t *create_player(float move_time)
{
    player_t *player = malloc(sizeof(player_t));
    char *filepath = "./ressources/jump.ogg";

    if (player == NULL)
        return (NULL);
    create_player_sprite(player);
    player->clock = sfClock_create();
    player->time_move = move_time;
    player->is_jumping = 1;
    player->gravity = 0.0;
    player->rect = create_rect(320, 320);
    player->is_dead = 0;
    player->jump_buffer = sfSoundBuffer_createFromFile(filepath);
    player->jump_sound = sfSound_create();
    sfSound_setBuffer(player->jump_sound, player->jump_buffer);
    return (player);
}

void destroy_player(player_t *player)
{
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    sfClock_destroy(player->clock);
    sfSound_destroy(player->jump_sound);
    sfSoundBuffer_destroy(player->jump_buffer);
    free(player);
}
