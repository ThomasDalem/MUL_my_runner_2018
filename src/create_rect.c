/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** Function to create a sfIntRect
*/
#include <SFML/Graphics/Sprite.h>

sfIntRect create_rect(int width, int height)
{
    sfIntRect rect;
    
    rect.width = width;
    rect.height = height;
    rect.left = 0;
    rect.top = 0;
    return (rect);
}