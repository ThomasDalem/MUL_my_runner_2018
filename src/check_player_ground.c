/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** Functions to check if the player is on the ground
*/

#include <unistd.h>
#include "my_runner.h"

int compare_pos(sfVector2f player_pos, sfVector2f ground_pos, float grav)
{
    player_pos.y += 100.0;
    
    if (player_pos.x + 100.0 >= ground_pos.x && player_pos.x <= ground_pos.x + 100.0) {
        if (player_pos.y + grav >= ground_pos.y && player_pos.y <= ground_pos.y)
            return (1);
    }
    return (-1);
}

int is_player_on_ground(player_t *player, object_t *object)
{
    sfVector2f player_pos = sfSprite_getPosition(player->sprite);
    sfVector2f ground_pos;
    object_t *curs = object;
    int compared_pos = 0;

    while (curs != NULL) {
        ground_pos = sfSprite_getPosition(curs->sprite);
        compared_pos = compare_pos(player_pos, ground_pos, player->gravity);
        if (curs->type == 0 && compared_pos != -1) {
            player->gravity = 0;
            return (ground_pos.y);
        }
        else if (curs->type == 0 && compared_pos == 2)
            return (-2);
        curs = curs->next;
    }
    return (-1);
}
