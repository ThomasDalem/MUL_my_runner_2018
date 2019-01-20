/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** Checks the collision between objects
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "my_runner.h"

void my_put_nbr(int nb);

int is_colliding(sfSprite *object1, sfSprite *object2)
{
    sfFloatRect obj1_rect = sfSprite_getGlobalBounds(object1);
    sfFloatRect obj2_rect = sfSprite_getGlobalBounds(object2);
    sfVector2f pos_obj1 = sfSprite_getPosition(object1);
    sfVector2f pos_obj2 = sfSprite_getPosition(object2);

    if (sfFloatRect_intersects(&obj1_rect, &obj2_rect, NULL) == sfTrue) {
        if (pos_obj1.x + 100 >= pos_obj2.x + 40 && pos_obj1.x <= pos_obj2.x)
            return (1);
    }
    return (0);
}

int check_collisions(/*sfRenderWindow *window,*/ object_t *object, player_t *plyr)
{
    int collision = 0;

    while (object != NULL) {
        collision = is_colliding(plyr->sprite, object->sprite);
        if (collision == 1 && object->type == 3)
            plyr->is_dead = -1;
        else if (collision == 1)
            plyr->is_dead = 1;
        object = object->next;
    }
    if (sfSprite_getPosition(plyr->sprite).y > 2000)
        plyr->is_dead = 1;
    return (0);
}
