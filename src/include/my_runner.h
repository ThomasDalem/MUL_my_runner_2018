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
    int choice;
    sfTexture *texture;
    sfSprite *sprite;
} button_t;

typedef struct player_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    float time_move;
    sfClock *clock;
    int is_jumping;
    float gravity;
} player_t;

typedef struct background_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    int move_delay;
} background_t;

int check_arguments(int ac, char **av);
sfRenderWindow *create_window(int width, int height);
int run_game(sfRenderWindow *window);
void anim_player(player_t *player);
player_t *create_player(float move_time);
void destroy_player(player_t *object);
void analyse_events(sfRenderWindow *window, sfEvent *event, player_t *player);
background_t *create_background(char const *filepath, int speed);
void destroy_background(background_t *background);
void anim_background(background_t *background);

#endif
