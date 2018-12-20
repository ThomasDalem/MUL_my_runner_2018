/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions to analyse the events
*/
#include <SFML/Window/Event.h>
#include <SFML/Graphics/RenderWindow.h>

void analyse_events(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if ((*event).type == sfEvtMouseButtonPressed)
                sfRenderWindow_close(window);
    }
}
