/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** Functions related to the background_t structure
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "my_runner.h"

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

background_t **create_backgrounds(void)
{
    background_t **background = malloc(sizeof(background_t) * 2);

    if (background == NULL)
        return (NULL);
    background[0] = create_background("./ressources/sky.jpg", 25);
    background[1] = create_background("./ressources/city.png", 5);
    return (background);
}

void destroy_background(background_t *background)
{
     sfSprite_destroy(background->sprite);
     sfTexture_destroy(background->texture);
     sfClock_destroy(background->clock);
     free(background);
}

void destroy_backgrounds(background_t **backgrounds)
{
    destroy_background(backgrounds[0]);
    destroy_background(backgrounds[1]);
    free(backgrounds);
}
