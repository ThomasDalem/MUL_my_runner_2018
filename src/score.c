/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** Create and displays the score on the screen
*/
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_runner.h"
#include "lib.h"

char *convert_to_string(int number)
{
    char *str = NULL;
    int num = number;
    int num2 = number;
    int nb_char = 0;
    int i = 0;

    while (num > 0) {
        num /= 10;
        nb_char++;
    }
    str = malloc(sizeof(char) * nb_char + 4);
    while (i < nb_char) {
        str[i] = num2 % 10 + '0';
        num2 /= 10;
        i++;
    }
    while (i < 4) {
        str[i] = '0';
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}

score_t *init_score(void)
{
    score_t *score = malloc(sizeof(score_t));
    sfVector2f pos;

    if (score == NULL)
        return (NULL);
    pos.x = 100;
    pos.y = 0;
    score->font = sfFont_createFromFile("./ressources/Comfortaa-Light.ttf");
    score->text = sfText_create();
    score->score_text = sfText_create();
    score->text_str = "Score: ";
    sfText_setFont(score->text, score->font);
    sfText_setFont(score->score_text, score->font);
    sfText_setColor(score->score_text, sfRed);
    sfText_setString(score->text, score->text_str);
    sfText_setPosition(score->score_text, pos);
    score->score = 0;
    score->clock = sfClock_create();
    return (score);
}

void update_score(score_t *score, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(score->clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds >= 0.2) {
        score->score_str = convert_to_string(score->score);
        sfText_setString(score->score_text, score->score_str);
        score->score += 1;
        sfClock_restart(score->clock);
        free(score->score_str);
    }
    sfRenderWindow_drawText(window, score->text, NULL);
    sfRenderWindow_drawText(window, score->score_text, NULL);
}

void destroy_score(score_t *score)
{
    sfClock_destroy(score->clock);
    sfFont_destroy(score->font);
    sfText_destroy(score->text);
    sfText_destroy(score->score_text);
    free(score);
}
