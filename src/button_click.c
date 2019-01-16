/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** Functions to check if the user pressed a button
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Event.h>
#include "my_runner.h"

int is_button_clicked(sfVector2f click_pos, button_t *button)
{
    sfVector2f button_pos = sfSprite_getPosition(button->sprite);

    if (click_pos.x >= button_pos.x && click_pos.y <= button_pos.x + 228) {
        if (click_pos.y >= button_pos.y && click_pos.y <= button_pos.y + 65)
            return (1);
    }
    return (0);
}

int check_button_pressed(button_t *buttons, sfEvent event)
{
    sfVector2f pos;

    pos.x = event.mouseButton.x;
    pos.y = event.mouseButton.y;
    while (buttons != NULL) {
        if (is_button_clicked(pos, buttons) == 1)
            return (buttons->choice);
        buttons = buttons->next;
    }
    return (0);
}
