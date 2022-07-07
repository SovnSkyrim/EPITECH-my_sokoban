/*
** EPITECH PROJECT, 2022
** movement up down
** File description:
** sokoban
*/

#include "../include/mysokoban.h"

void move_up(sokoban_t *skb)
{
    switch (skb->board[skb->p_loci - 1][skb->p_locj]) {
        case 'X':
            if (skb->board[skb->p_loci - 2][skb->p_locj] != '#' &&
                skb->board[skb->p_loci - 2][skb->p_locj] != 'X') {
                skb->board[skb->p_loci - 1][skb->p_locj] = 'P';
                skb->board[skb->p_loci - 2][skb->p_locj] = 'X';
                turning_op(skb);
                skb->p_loci--;
            }
            break;
        case 'O': case ' ':
            skb->board[skb->p_loci - 1][skb->p_locj] = 'P';
            turning_op(skb);
            skb->p_loci--;
            break;
        case '#': break;
    }
}

void move_down(sokoban_t *skb)
{
    switch (skb->board[skb->p_loci + 1][skb->p_locj]) {
        case 'X':
            if (skb->board[skb->p_loci + 2][skb->p_locj] != '#' &&
                skb->board[skb->p_loci + 2][skb->p_locj] != 'X') {
                skb->board[skb->p_loci + 1][skb->p_locj] = 'P';
                skb->board[skb->p_loci + 2][skb->p_locj] = 'X';
                turning_op(skb);
                skb->p_loci++;
            }
            break;
        case 'O': case ' ':
            skb->board[skb->p_loci + 1][skb->p_locj] = 'P';
            turning_op(skb);
            skb->p_loci++;
            break;
        case '#': break;
    }
}
