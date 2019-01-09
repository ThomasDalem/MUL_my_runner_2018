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

int run_game(sfRenderWindow *window, char const *filepath)
{
    sfEvent event;
    player_t *player = create_player(65);
    background_t **backgrounds = create_backgrounds();
    object_t *objects = create_objects(filepath);
    sfClock *object_clock = sfClock_create();

    while (sfRenderWindow_isOpen(window) && player->is_dead != 1) {
        sfRenderWindow_clear(window, sfBlack);
        anim_backgrounds(backgrounds, window);
        analyse_events(window, &event, player);
        display_objects(objects, window, object_clock);
        anim_player(player, objects);
        sfRenderWindow_drawSprite(window, player->sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(object_clock);
    sfRenderWindow_clear(window, sfWhite);
    destroy_player(player);
    destroy_backgrounds(backgrounds);
    destroy_objects(objects);
    return (0);
}
