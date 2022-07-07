/*
** EPITECH PROJECT, 2022
** program in c manage your memory with malloc and free
** File description:
** sokoban
*/

#include "../include/mysokoban.h"

void its_free_real_estate(sokoban_t *skb)
{
    free(skb->board);
    free(skb->board_backup);
    free(skb);
}
