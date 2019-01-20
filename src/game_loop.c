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

void check_player_state(sfRenderWindow *window, player_t *plyr, score_t *score)
{
    if (plyr->is_dead == 1) {
        plyr->is_dead = end_lost_game(window, score);
    }
}

int run_game(sfRenderWindow *window, char const *filepath)
{
    sfEvent event;
    player_t *player = create_player(65);
    background_t **backgrounds = create_backgrounds();
    object_t *objects = create_objects(filepath);
    sfClock *objects_clock = sfClock_create();
    score_t *score = init_score();
    int restart = 0;

    while (player->is_dead == 0 && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        anim_backgrounds(backgrounds, window);
        display_objects(objects, window, objects_clock);
        anim_player(player, objects, window);
        analyse_events(window, &event, player);
        update_score(score, window);
        check_player_state(window, player, score);
        if (player->is_dead == 0)
            sfRenderWindow_display(window);
    }
    sfClock_destroy(objects_clock);
    restart = player->is_dead;
    destroy_player(player);
    destroy_backgrounds(backgrounds);
    destroy_objects(objects);
    destroy_score(score);
    return (restart);
}
