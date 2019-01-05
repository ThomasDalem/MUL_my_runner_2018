/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>

typedef struct button_s
{
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    int choice;
} button_t;

typedef struct player_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    int is_jumping;
    float gravity;
    float time_move;
} player_t;

typedef struct background_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    int move_delay;
} background_t;

typedef struct object_s
{
    sfTexture *texture;
    sfSprite *sprite;
} object_t;

int check_arguments(int ac, char **av);
sfRenderWindow *create_window(int width, int height);
int run_game(sfRenderWindow *window);
void anim_player(player_t *player);
player_t *create_player(float move_time);
void destroy_player(player_t *object);
void analyse_events(sfRenderWindow *window, sfEvent *event, player_t *player);
background_t **create_backgrounds(void);
void destroy_backgrounds(background_t **backgrounds);
void anim_backgrounds(background_t **background, sfRenderWindow *window);
sfIntRect create_rect(int width, int height);

#endif
