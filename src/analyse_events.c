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
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeySpace) {
            player->gravity = -5.0;
            player->is_jumping = 1;
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
