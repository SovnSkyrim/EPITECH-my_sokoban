/*
** EPITECH PROJECT, 2022
** check args
** File description:
** sokoban
*/

#include "../include/mysokoban.h"

void print_h(void)
{
    my_putstr_n("USAGE");
    my_putstr_n("\t./my_sokoban map");
    my_putstr_n("DESCRIPTION");
    my_putstr("\tmap\tfile representing the warehouse map,");
    my_putstr(" containing '#' for walls, 'P' for the player,");
    my_putstr_n(" 'X' for boxes and 'O' for storage locations.");
}

int check_args(char **argv, int argc)
{
    if (argc != 2)
        return ERROR;
    if (my_strcompare(argv[1], "-h") == SUCCESS) {
        print_h();
        exit(SUCCESS);
    }
    return SUCCESS;
}
