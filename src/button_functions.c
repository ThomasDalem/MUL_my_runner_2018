/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions related to the buttons structure
*/
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "my_runner.h"

button_t *create_button(int choice, char const *text_path)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return (NULL);
    button->pos.x = 20;
    button->pos.y = 20;
    button->choice = choice;
    button->texture = sfTexture_createFromFile(text_path, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    return (button);
}

void destroy_button(button_t *button)
{
    sfSprite_destroy(button->sprite);
    sfTexture_destroy(button->texture);
    free(button);
}