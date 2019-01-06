/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Functions related to the object_t struct
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_runner.h"

char **load_map(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    //char *buffer = NULL;
    char **map = NULL;

    if (fd < 0) {
        write(1, "Can't open the map file.\n", 25);
        close(fd);
        return (NULL);
    }
    close(fd);
    return (map);
}

int check_if_object(char c)
{
    if (c == '1' || c == '2' || c == '3')
        return (1);
    return (0);
}

int get_number_of_objects(char **map, int *map_x, int *map_y)
{
    int y = 0;
    int x = 0;
    int number_of_objects = 0;

    while (map[y][x] != '\0') {
        if (map[y][x] == '\n') {
            y++;
            x = 0;
        }
        else if (map[y][x] == '\0') {
            *map_x = x;
            *map_y = y;
            return (number_of_objects);
        }
        number_of_objects += check_if_object(map[y][x]);
        x++;
    }
    return (number_of_objects);
}

object_t **create_objects()
{
    object_t **objects = NULL;
    char **map = malloc(sizeof(char *) * 2);
    int map_x = 0;
    int map_y = 0;
    int nb_objects = 0;
    char c = 0;
    char c2 = 0;
    char c3 = 0;
    
    map[0] = malloc(sizeof(char) * 4);
    map[1] = malloc(sizeof(char) * 4);
    map[0][0] = ' ';
    map[0][1] = ' ';
    map[0][2] = '1';
    map[0][3] = '\0';
    map[1][0] = '2';
    map[1][1] = ' ';
    map[1][2] = '3';
    map[1][3] = '\0';
    nb_objects = get_number_of_objects(map, &map_x, &map_y);
    c = nb_objects + '0';
    c2 = map_x + '0';
    c3 = map_y + '0';
    write(1, &c, 1);
    write(1, &c2, 1);
    write(1, &c3, 1);
    return (objects);
}

void destroy_objects(object_t **objects, int number_of_objects)
{
    int i = 0;

    while (i < number_of_objects) {
        sfSprite_destroy(objects[i]->sprite);
        sfTexture_destroy(objects[i]->texture);
        free(objects[i]);
        i++;
    }
    free(objects);
}
