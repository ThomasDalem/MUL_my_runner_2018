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
   // sfTexture *pressed_texture;
    sfSprite *sprite;
    int choice;
    struct button_s *next;
} button_t;

typedef struct player_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    int is_jumping;
    int is_dead;
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

typedef struct menu_image_s
{
    sfTexture *texture;
    sfSprite *sprite;
} menu_image_t;

typedef struct object_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int type;
    struct object_s *next;
} object_t;

/* Structures creating functions */
player_t *create_player(float move_time);
sfIntRect create_rect(int width, int height);
object_t *create_objects(char const *filepath);
background_t **create_backgrounds(void);
button_t *create_buttons(void);

/* Structures destroying functions */
void destroy_player(player_t *object);
void destroy_backgrounds(background_t **backgrounds);
void destroy_objects(object_t *objects);
void destroy_buttons(button_t *node_head);

/* Animation functions */
void anim_player(player_t *player, object_t *objects, sfRenderWindow *window);
void anim_backgrounds(background_t **background, sfRenderWindow *window);

int check_arguments(int ac, char **av);
sfRenderWindow *create_window(int width, int height);
int run_game(sfRenderWindow *window, char const *filepath);
void analyse_events(sfRenderWindow *window, sfEvent *event, player_t *player);
void display_objects(object_t *object, sfRenderWindow *window, sfClock *clock);
int is_player_on_ground(player_t *player, object_t *object);
int is_colliding(sfSprite *object1, sfSprite *object2);
int check_collisions(object_t *object, player_t *player);
int analyse_menu_events(sfRenderWindow *window, sfEvent *events, button_t *btn);
int check_button_pressed(button_t *buttons, sfEvent event);
void display_buttons(sfRenderWindow *window, button_t *buttons);
int run_menu(sfRenderWindow *window);

#endif
