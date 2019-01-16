/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** Functions to display and use the main menu
*/
#include <SFML/Graphics/RenderWindow.h>
#include "my_runner.h"

int run_menu(sfRenderWindow *window)
{
    button_t *buttons = create_buttons();
    sfTexture *texture = sfTexture_createFromFile("./ressources/menu.jpg", NULL);
    sfSprite *background = sfSprite_create();
    sfEvent events;
    int choice = 0;

    if (buttons == NULL)
        return (84);
    sfSprite_setTexture(background, texture, sfTrue);
    while (choice == 0) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background, NULL);
        display_buttons(window, buttons);
        choice = analyse_menu_events(window, &events, buttons);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(background);
    sfTexture_destroy(texture);
    destroy_buttons(buttons);
    return (choice);
}