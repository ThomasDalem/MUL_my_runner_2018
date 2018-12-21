/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions related to the object_t struct
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "my_runner.h"

sfIntRect create_rect(int width, int height)
{
    sfIntRect rect;
    
    rect.width = width;
    rect.height = height;
    rect.left = 0;
    rect.top = 0;
    return (rect);
}

player_t *create_player(float move_time)
{
    player_t *player = malloc(sizeof(player_t));
    char *filepath = "../ressources/Spaceship.png";
    sfVector2f pos;
    sfVector2f scale;

    pos.x = 0;
    pos.y = 0;
    scale.x = 2;
    scale.y = 2;
    if (player == NULL)
        return (NULL);
    player->clock = sfClock_create();
    player->texture = sfTexture_createFromFile(filepath, NULL);
    player->sprite = sfSprite_create();
    player->time_move = move_time;
    player->is_jumping = 0;
    player->gravity = 5.0;
    player->rect = create_rect(76, 34);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, pos);
    sfSprite_setScale(player->sprite, scale);
    return (player);
}

background_t *create_background(char const *filepath, int speed)
{
    background_t *background = malloc(sizeof(background_t));

    if (background == NULL)
        return (NULL);
    background->texture = sfTexture_createFromFile(filepath, NULL);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    background->rect.width = 960;
    background->rect.height = 720;
    background->rect.left = 0;
    background->rect.top = 0;
    background->clock = sfClock_create();
    background->move_delay = speed;
    return (background);
}

void destroy_player(player_t *player)
{
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    sfClock_destroy(player->clock);
    free(player);
}

void destroy_background(background_t *background)
{
     sfSprite_destroy(background->sprite);
     sfTexture_destroy(background->texture);
     sfClock_destroy(background->clock);
     free(background);
}
