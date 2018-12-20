/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions for the game loop
*/
#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include "my_runner.h"

int run_game(sfRenderWindow *window)
{
    sfEvent event;
    player_t *player = create_player(60);
    background_t *background = create_background("../ressources/sky.jpg", 25);
    background_t *background2 = create_background("../ressources/city.png", 5);

    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window, &event);
        sfRenderWindow_clear(window, sfWhite);
        anim_background(background);
        anim_background(background2);
        anim_player(player);
        sfRenderWindow_drawSprite(window, background->sprite, NULL);
        sfRenderWindow_drawSprite(window, background2->sprite, NULL);
        sfRenderWindow_drawSprite(window, player->sprite, NULL);
        sfRenderWindow_display(window);
    }
    destroy_player(player);
    destroy_background(background);
    destroy_background(background2);
    sfRenderWindow_destroy(window);
    return (0);
}