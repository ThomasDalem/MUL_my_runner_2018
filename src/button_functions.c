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

int create_play_button(button_t **node_head)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return (84);
    button->pos.x = 960 - 114;
    button->pos.y = 450;
    button->choice = 2;
    button->texture = sfTexture_createFromFile("./ressources/play.png", NULL);
    //button->pressed_texture = sfTexture_createFromFile("./ressources/play_prs.png", NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->pos);
    button->next = *node_head;
    *node_head = button;
    return (0);
}
int create_quit_button(button_t **node_head)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return (84);
    button->pos.x = 960 - 114;
    button->pos.y = 600;
    button->choice = 1;
    button->texture = sfTexture_createFromFile("./ressources/quit.png", NULL);
    //button->pressed_texture = sfTexture_createFromFile("./ressources/quit_prs.png", NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->pos);
    button->next = *node_head;
    *node_head = button;
    return (0);
}

button_t *create_buttons(void)
{
    button_t *buttons = NULL;

    if (create_play_button(&buttons) == 84)
        return (NULL);
    if (create_quit_button(&buttons) == 84) {
        return (NULL);
    }
    return (buttons);
}

void destroy_button(button_t *button)
{
    sfSprite_destroy(button->sprite);
    sfTexture_destroy(button->texture);
    //sfTexture_destroy(button->pressed_texture);
    free(button);
}

void destroy_buttons(button_t *node_head)
{
    button_t *next_button = NULL;

    while (node_head != NULL) {
        next_button = node_head->next;
        destroy_button(node_head);
        node_head = next_button;
    }
}
