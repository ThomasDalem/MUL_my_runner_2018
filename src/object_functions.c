/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions related to the object_t struct
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_runner.h"

int create_object(object_t **object_head, int y, int x)
{
    object_t *new_object = malloc(sizeof(object_t));
    sfVector2f scale;

    if (new_object == NULL)
        return (84);
    scale.x = 0.5;
    scale.y = 0.5;
    new_object->pos.x = x * 100;
    new_object->pos.y = y * 100;
    new_object->texture = sfTexture_createFromFile("./ressources/ground_sprite.png", NULL);
    new_object->sprite = sfSprite_create();
    sfSprite_setTexture(new_object->sprite, new_object->texture, sfFalse);
    sfSprite_setScale(new_object->sprite, scale);
    sfSprite_setPosition(new_object->sprite, new_object->pos);
    new_object->next = *object_head;
    *object_head = new_object;
    return (0);
}

int add_objects_of_line(object_t **object_head, int y, FILE *fd)
{
    int x = 0;
    char *buffer = NULL;
    size_t size = 0;

    if (fd == NULL)
        return (84);
    getline(&buffer, &size, fd);
    while (buffer[x] != '\0') {
        if (buffer[x] == '0' || buffer[x] == '1')
            create_object(object_head, y, x);
        x++;
    }
    free(buffer);
    return (0);
}

object_t *create_objects(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    object_t *objects = NULL;

    for (int y = 0; y < 10; y++)
        add_objects_of_line(&objects, y, fd);
    fclose(fd);
    return (objects);
}

void destroy_objects(object_t *objects)
{
    object_t *prev_object = NULL;

    while (objects != NULL) {
        prev_object = objects;
        objects = objects->next;
        sfSprite_destroy(prev_object->sprite);
        sfTexture_destroy(prev_object->texture);
        free(prev_object);
    }
}
