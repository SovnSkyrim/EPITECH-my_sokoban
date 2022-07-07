/*
** EPITECH PROJECT, 2022
** win_display
** File description:
** sokoban
*/

#include "../include/mysokoban.h"

void win_display(sokoban_t *skb)
{
    clear();
    for (int i = 0; skb->board[i]; i++)
        printw("%s\n", skb->board[i]);
    refresh();
}
