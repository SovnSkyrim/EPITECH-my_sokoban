/*
** EPITECH PROJECT, 2022
** get_board
** File description:
** bsq modified
*/

#include "../include/mysokoban.h"

int do_board(char **output, char *path)
{
    struct stat stats;
    int statfd = stat(path, &stats);
    unsigned int size = stats.st_size;
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        close(fd);
        return ERROR;
    }
    char *temp = malloc(sizeof(char) * (size + 1));
    if (temp == NULL)
        return ERROR;
    read(fd, temp, size);
    temp[size] = '\0';
    close(fd);
    *(output) = temp;
    return SUCCESS;
}
