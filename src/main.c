/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Main function of the my_runner project
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include "lib.h"
#include "my_runner.h"

sfMusic *create_music(void)
{
    sfMusic *music = sfMusic_createFromFile("./ressources/music.ogg");

    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return (music);
}

void game_loop(char const *filepath)
{
    sfRenderWindow *window = NULL;
    int quit = 0;
    sfMusic *music = create_music();

    window = create_window(1920, 1080);
    while (sfRenderWindow_isOpen(window) && quit != 1) {
        sfMusic_play(music);
        if (quit != 2)
            quit = run_menu(window);
        if (quit != 1)
            quit = run_game(window, filepath);
        sfMusic_stop(music);
    }
    sfMusic_destroy(music);
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
}

int main(int ac, char **av)
{
    int arg = check_arguments(ac, av);

    if (arg == 84)
        return (84);
    else if (arg == -1)
        return (0);
    game_loop(av[1]);
    return (0);
}
