/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** end_game
*/
#include <stdlib.h>
#include "my_runner.h"

void display_end_score(sfRenderWindow *window, score_t *score)
{
    sfVector2f pos;
    sfVector2f scale;

    pos.x = 1400;
    pos.y = 730;
    scale.x = 1.5;
    scale.y = 1.5;
    score->score_str = convert_to_string(score->score);
    sfText_setPosition(score->score_text, pos);
    sfText_setScale(score->score_text, scale);
    sfText_setString(score->score_text, score->score_str);
    free(score->score_str);
    sfRenderWindow_drawText(window, score->score_text, NULL);
}

void destroy_menu_background(sfTexture *texture, sfSprite *sprite)
{
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

int end_win_game(sfRenderWindow *window, score_t *score)
{
    int choice = 0;
    button_t **buttons = create_end_buttons();
    char *filepath = "./ressources/win_screen.png";
    sfTexture *background = sfTexture_createFromFile(filepath, NULL);
    sfSprite *background_sprite = sfSprite_create();

    sfSprite_setTexture(background_sprite, background, sfFalse);
    while (sfRenderWindow_isOpen(window) && choice == 0) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background_sprite, NULL);
        display_buttons(window, buttons, 2);
        choice = analyse_menu_events(window, buttons);
        display_end_score(window, score);
        sfRenderWindow_display(window);
        if (choice == 1)
            sfRenderWindow_close(window);
    }
    destroy_buttons(buttons, 2);
    destroy_menu_background(background, background_sprite);
    return (2);
}

int end_lost_game(sfRenderWindow *window, score_t *score)
{
    int choice = 0;
    button_t **buttons = create_end_buttons();
    char *filepath = "./ressources/lost_screen.png";
    sfTexture *background = sfTexture_createFromFile(filepath, NULL);
    sfSprite *background_sprite = sfSprite_create();

    sfSprite_setTexture(background_sprite, background, sfFalse);
    while (sfRenderWindow_isOpen(window) && choice == 0) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background_sprite, NULL);
        display_buttons(window, buttons, 2);
        choice = analyse_menu_events(window, buttons);
        display_end_score(window, score);
        sfRenderWindow_display(window);
        if (choice == 1)
            sfRenderWindow_close(window);
    }
    destroy_buttons(buttons, 2);
    destroy_menu_background(background, background_sprite);
    return (2);
}