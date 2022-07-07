/*
** EPITECH PROJECT, 2022
** movements right left
** File description:
** sokoban
*/

#include "../include/mysokoban.h"

void turning_op(sokoban_t *skb)
{
    skb->board[skb->p_loci][skb->p_locj] = skb->board_backup[skb->p_loci]
    [skb->p_locj] == 'X' || skb->board_backup[skb->p_loci]
    [skb->p_locj] == 'P' ? ' ' : skb->board_backup[skb->p_loci][skb->p_locj];
}

void move_right(sokoban_t *skb)
{
    switch (skb->board[skb->p_loci][skb->p_locj + 1]) {
        case 'X':
            if (skb->board[skb->p_loci][skb->p_locj + 2] != '#' &&
                skb->board[skb->p_loci][skb->p_locj + 2] != 'X') {
                skb->board[skb->p_loci][skb->p_locj + 1] = 'P';
                skb->board[skb->p_loci][skb->p_locj + 2] = 'X';
                turning_op(skb);
                skb->p_locj++;
            }
            break;
        case 'O': case ' ':
            skb->board[skb->p_loci][skb->p_locj + 1] = 'P';
            turning_op(skb);
            skb->p_locj++;
            break;
        case '#': break;
    }
}

void move_left(sokoban_t *skb)
{
    switch (skb->board[skb->p_loci][skb->p_locj - 1]) {
        case 'X':
            if (skb->board[skb->p_loci][skb->p_locj - 2] != '#' &&
                skb->board[skb->p_loci][skb->p_locj - 2] != 'X') {
                skb->board[skb->p_loci][skb->p_locj - 1] = 'P';
                skb->board[skb->p_loci][skb->p_locj - 2] = 'X';
                turning_op(skb);
                skb->p_locj--;
            }
            break;
        case 'O': case ' ':
            skb->board[skb->p_loci][skb->p_locj - 1] = 'P';
            turning_op(skb);
            skb->p_locj--;
            break;
        case '#': break;
    }
}
