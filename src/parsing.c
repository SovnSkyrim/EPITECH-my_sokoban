/*
** EPITECH PROJECT, 2022
** parsing
** File description:
** sokoban
*/

#include "../include/mysokoban.h"

void pos_p(sokoban_t *skb, int i, int j, int *found)
{
    if (skb->board[i][j] == 'P') {
        skb->p_loci = i;
        skb->p_locj = j;
        (*found)++;
    }
}

void find_p(sokoban_t *skb)
{
    int found = 0;

    for (int i = 0; skb->board[i] && found == 0; i++) {
        for (int j = 0; skb->board[i][j] && found == 0; j++)
            pos_p(skb, i, j, &found);
    }
}

int p_check(sokoban_t *skb)
{
    find_p(skb);
    if (skb->board[skb->p_loci + 1][skb->p_locj] == '#' &&
        skb->board[skb->p_loci - 1][skb->p_locj] == '#' &&
        skb->board[skb->p_loci][skb->p_locj - 1] == '#' &&
        skb->board[skb->p_loci][skb->p_locj + 1] == '#')
        return ERROR;
    return SUCCESS;
}

int parse_board(char *board, sokoban_t *skb)
{
    int p_count = 0;
    int x_count = 0;
    int o_count = 0;

    for (int i = 0; board[i]; i++) {
        switch (board[i]) {
            case 'P': p_count++;
                break;
            case 'O': o_count++;
                break;
            case 'X': x_count++;
                break;
            case '\n': case ' ': case '#': case '\0': break;
            default: return ERROR;
        }
    }
    if (x_count < o_count || p_count > 1)
        return ERROR;
    skb->boxes_nb = o_count;
    return SUCCESS;
}
