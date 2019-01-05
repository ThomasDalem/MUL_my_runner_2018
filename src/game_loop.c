/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions for the game loop
*/
#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_runner.h"

int run_game(sfRenderWindow *window)
{
    sfEvent event;
    player_t *player = create_player(65);
    background_t **backgrounds = create_backgrounds(); 

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        anim_backgrounds(backgrounds, window);
        analyse_events(window, &event, player);
        anim_player(player);
        sfRenderWindow_drawSprite(window, player->sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_clear(window, sfWhite);
    destroy_player(player);
    destroy_backgrounds(backgrounds);
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
    return (0);
}