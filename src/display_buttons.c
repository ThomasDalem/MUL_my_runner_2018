/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** Displays the buttons on the screen
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_runner.h"

void display_buttons(sfRenderWindow *window, button_t *buttons)
{
    while (buttons != NULL) {
        sfRenderWindow_drawSprite(window, buttons->sprite, NULL);
        buttons = buttons->next;
    }
}