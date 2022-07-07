/*
** EPITECH PROJECT, 2022
** check win loss
** File description:
** sokoban
*/

#include "../include/mysokoban.h"

void victory_check(sokoban_t *skb, int i, int j)
{
    if (skb->board[i][j] == 'X' && skb->board_backup[i][j] == 'O') {
        skb->boxes_set++;
    }
}

void check_victory(sokoban_t *skb)
{
    if (skb->boxes_nb == skb->boxes_set)
        return;

    skb->boxes_set = 0;

    for (int i = 0; skb->board[i]; i++) {
        for (int j = 0; skb->board[i][j]; j++)
            victory_check(skb, i, j);
    }
    if (skb->boxes_set == skb->boxes_nb) {
        skb->win = 1;
    }
}

void boxes_check(sokoban_t *skb, int i, int j, int *count)
{
    if ((skb->board[i][j] == 'X'
        && skb->board[i][j + 1] == '#' && skb->board[i + 1][j] == '#' ) ||
        (skb->board[i][j] == 'X'
        && skb->board[i][j - 1] == '#' && skb->board[i + 1][j] == '#' ) ||
        (skb->board[i][j] == 'X'
        && skb->board[i][j + 1] == '#' && skb->board[i - 1][j] == '#' ) ||
        (skb->board[i][j] == 'X'
        && skb->board[i][j - 1] == '#' && skb->board[i - 1][j] == '#'))
        (*count)++;
}

void check_boxes(sokoban_t *skb)
{
    int count = 0;
    for (int i = 0; skb->board[i]; i++) {
        for (int j = 0; skb->board[i][j]; j++)
            boxes_check(skb, i, j, &count);
    }
    if (count == skb->boxes_nb) {
        skb->boxes_set = skb->boxes_nb;
    }
}
