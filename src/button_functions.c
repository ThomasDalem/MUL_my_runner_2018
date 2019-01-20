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

button_t *create_button(int x, int y, char const *filepath, int choice)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return (NULL);
    button->pos.x = x;
    button->pos.y = y;
    button->choice = choice;
    button->texture = sfTexture_createFromFile(filepath, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->pos);
    return (button);
}

button_t **create_menu_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t) * 2);

    if (buttons == NULL)
        return (NULL);
    buttons[0] = create_button(845, 500, "./ressources/play.png", 2);
    buttons[1] = create_button(845, 700, "./ressources/quit.png", 1);
    return (buttons);
}

button_t **create_end_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t) * 2);

    if (buttons == NULL)
        return (NULL);
    buttons[0] = create_button(500, 500, "./ressources/retry.png", 2);
    buttons[1] = create_button(500, 700, "./ressources/quit.png", 1);
    return (buttons);
}

void destroy_button(button_t *button)
{
    sfSprite_destroy(button->sprite);
    sfTexture_destroy(button->texture);
    free(button);
}

void destroy_buttons(button_t **buttons, int button_nb)
{
    for (int i = 0; i < button_nb; i++)
        destroy_button(buttons[i]);
    free(buttons);
}
