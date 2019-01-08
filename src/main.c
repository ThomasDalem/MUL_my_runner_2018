/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Main function of the my_runner project
*/
#include <SFML/Graphics/RenderWindow.h>
#include <unistd.h>
#include "lib.h"
#include "my_runner.h"

int main(int ac, char **av)
{
    sfRenderWindow *window = create_window(1920, 1080);
    int arg = check_arguments(ac, av);

    if (arg == 84)
        return (84);
    else if (arg == -1)
        return (0);
    run_game(window, av[1]);
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
    return (0);
}
