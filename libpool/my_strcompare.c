/*
** EPITECH PROJECT, 2022
** my_strcompare
** File description:
** libpool
*/

#include "../include/mysokoban.h"

int my_strcompare(char *first, char *second)
{
    int len_f = my_strlen(first);
    int len_s = my_strlen(second);

    if (len_f != len_s)
        return ERROR;

    for (int i = 0; i < len_f; i++) {
        if (first[i] != second[i])
            return ERROR;
    }
    return SUCCESS;
}

int my_strcompare_begin(char *first, char *second)
{
    int len_s = my_strlen(second);

    for (int i = 0; i < len_s; i++) {
        if (first[i] != second[i])
            return ERROR;
    }
    return SUCCESS;
}
