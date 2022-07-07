/*
** EPITECH PROJECT, 2022
** getch_handler
** File description:
** sokoban
*/

#include "../include/mysokoban.h"

int getch_handler(sokoban_t *skb)
{
    int input = getch();
    switch (input) {
        case KEY_UP: move_up(skb);
            break;
        case KEY_DOWN: move_down(skb);
            break;
        case KEY_RIGHT: move_right(skb);
            break;
        case KEY_LEFT: move_left(skb);
            break;
        case 32: return SPECIAL;
        default: return ERROR;
    }
    return SUCCESS;
}
