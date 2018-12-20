/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Checks the arguments given by the user
*/
#include <unistd.h>
#include "lib.h"

int check_arguments(int ac, char **av)
{
    if (ac != 2) {
        write(1, "./my_runner: bad arguments: ", 28);
        my_put_nbr(ac);
        write(1, "given but 1 is required\nretry with -h\n", 38);
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        write(1, "En cours... :(\n", 15);
        return (-1);
    }
    return (0);
}