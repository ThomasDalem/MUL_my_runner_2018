/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** Functions to display and use the main menu
*/
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include "my_runner.h"

menu_image_t *init_image(void)
{
    menu_image_t *image = malloc(sizeof(menu_image_t));

    if (image == NULL)
        return (NULL);
    image->texture = sfTexture_createFromFile("./ressources/menu.png", NULL);
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfFalse);
    return (image);
}

void destroy_image(menu_image_t *background)
{
    sfSprite_destroy(background->sprite);
    sfTexture_destroy(background->texture);
    free(background);
}

int run_menu(sfRenderWindow *window)
{
    button_t **buttons = create_menu_buttons();
    int choice = 0;
    menu_image_t *background = init_image();

    if (buttons == NULL || background == NULL)
        return (84);
    while (choice == 0) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background->sprite, NULL);
        display_buttons(window, buttons, 2);
        choice = analyse_menu_events(window, buttons);
        sfRenderWindow_display(window);
    }
    destroy_buttons(buttons, 2);
    destroy_image(background);
    return (choice);
}