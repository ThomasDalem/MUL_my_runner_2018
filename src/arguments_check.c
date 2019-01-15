/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Checks the arguments given by the user
*/
#include <unistd.h>
#include <sys/stat.h>
#include "lib.h"

int check_arguments(int ac, char **av)
{
    struct stat sb;

    if (ac != 2) {
        write(1, "./my_runner: bad arguments: ", 28);
        my_put_nbr(ac);
        write(1, " given but 1 is required\nretry with -h\n", 39);
        return (84);
    }
    else if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        write(1, "En cours... :(\n", 15);
        return (-1);
    }
    if (stat(av[1], &sb) == -1) {
        write(1, "Cannot find given map.\n", 23);
        return (84);
    }
    return (0);
}