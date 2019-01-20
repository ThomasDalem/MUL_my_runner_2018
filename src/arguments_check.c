/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Checks the arguments given by the user
*/
#include <unistd.h>
#include <sys/stat.h>
#include "lib.h"

void display_rules(void)
{
    write(1, "\nMy_runner project 2018\n\nYou are the character on the ", 54);
    write(1, "left of the screen and you must run to the escape pod ", 54);
    write(1, "\non the right of the map.\nYou must not touch the spikes", 55);
    write(1, " or the hit a box from the left, or you will die !\n\n", 52);
    write(1, "You can only use the spacebar to jump,\nholding it will ", 55);
    write(1, "make the character jump right after hitting the ground, ", 56);
    write(1, "use it at your advantage.\n\n", 27);
    write(1, "Have fun :)\n\n", 13);
}

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
        display_rules();
        return (-1);
    }
    if (stat(av[1], &sb) == -1) {
        write(1, "Cannot find given map.\n", 23);
        return (84);
    }
    return (0);
}