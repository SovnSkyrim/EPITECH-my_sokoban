/*
** EPITECH PROJECT, 2022
** is win
** File description:
** sokoban
*/

#include "../include/mysokoban.h"

int is_win(sokoban_t *skb)
{
    if (skb->win == 1)
        return WIN;
    else if (skb->win == 0)
        return LOSS;
    else {
        my_putstr("le bosquet a pris feu");
        return ERROR;
    }
}
