/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Main function of the my_runner project
*/
#include <SFML/Graphics/RenderWindow.h>
#include "lib.h"
#include "my_runner.h"

int main(int ac, char **av)
{
    sfRenderWindow *window = create_window(800, 600);
    int arg = check_arguments(ac, av);

    if (arg == 84)
        return (84);
    else if (arg == -1)
        return (0);
    my_putstr(av[1]);
    run_game(window);
    return (0);
}
