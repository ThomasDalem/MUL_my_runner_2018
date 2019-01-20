/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** Displays the buttons on the screen
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_runner.h"

void display_buttons(sfRenderWindow *window, button_t **buttons, int button_nb)
{
    for (int i = 0; i < button_nb; i++)
        sfRenderWindow_drawSprite(window, buttons[i]->sprite, NULL);
}