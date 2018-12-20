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

player_t *create_player(float move_time)
{
    player_t *player = malloc(sizeof(player_t));
    char *filepath = "../ressources/player_run.png";
    sfVector2f pos;

    pos.x = 0;
    pos.y = 400;
    if (player == NULL)
        return (NULL);
    player->pos.x = 0;
    player->pos.y = 0;
    player->clock = sfClock_create();
    player->texture = sfTexture_createFromFile(filepath, NULL);
    player->sprite = sfSprite_create();
    player->rect.height = 110;
    player->rect.width = 110;
    player->rect.left = 0;
    player->rect.top = 0;
    player->time_move = move_time;
    sfSprite_setPosition(player->sprite, pos);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
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
