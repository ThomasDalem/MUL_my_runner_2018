/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions to analyse the events
*/
#include <SFML/Window/Event.h>
#include <SFML/Graphics/RenderWindow.h>
#include <unistd.h>
#include "my_runner.h"

void check_input(sfEvent event, player_t *player)
{
    sfVector2f offset;

    offset.x = 0.0;
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeySpace && player->is_jumping == 0) {
            player->gravity = -10.0;
            player->is_jumping = 1;
            offset.y = player->gravity;
            sfSprite_move(player->sprite, offset);
        }
    }
}

void analyse_events(sfRenderWindow *window, sfEvent *event, player_t *player)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if ((*event).type == sfEvtClosed)
                sfRenderWindow_close(window);
        else
                check_input(*event, player);
    }
}
