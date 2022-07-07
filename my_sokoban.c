/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** psu
*/

#include "include/mysokoban.h"

int game(sokoban_t *skb)
{
    WINDOW *window = initscr();
    keypad(window, true);
    curs_set(0);
    while (skb->boxes_set != skb->boxes_nb) {
        clear();
        for (int i = 0; skb->board[i]; i++)
            printw("%s\n", skb->board[i]);
        refresh();
        int input = getch_handler(skb);
        switch (input) {
            case SPECIAL: return SPECIAL;
            case ERROR: return ERROR;
        }
    check_boxes(skb);
    check_victory(skb);
    }
    win_display(skb);
    endwin();
    return is_win(skb);
}

int reload(sokoban_t *skb, int state)
{
    if (state == SPECIAL)
        state = game(skb);
    switch (state) {
        case SPECIAL:
            free(skb->board);
            skb->board = my_arraycpy(skb->board_backup);
            skb->boxes_set = 0;
            find_p(skb);
            state = reload(skb, SPECIAL);
        case WIN: return WIN;
        case LOSS: return LOSS;
        default: return ERROR;
    }
}

int init_struct(sokoban_t *skb, char **argv, int argc)
{
    char *output;
    int arg = check_args(argv, argc);

    if (arg != SUCCESS)
        return arg;
    if (do_board(&output, argv[1]) == ERROR
        || parse_board(output, skb) == ERROR)
        return ERROR;
    skb->board = my_str_to_word_array(output, '\n');
    skb->board_backup = my_arraycpy(skb->board);
    skb->boxes_set = 0;
    skb->win = 0;
    if (p_check(skb) == ERROR)
        return ERROR;
    free(output);
    return SUCCESS;
}

int main(int argc, char **argv)
{
    sokoban_t *skb = malloc(sizeof(sokoban_t));
    int end;

    if (init_struct(skb, argv, argc) == ERROR) {
        its_free_real_estate(skb);
        return ERROR;
    }
    end = reload(skb, SPECIAL);
    its_free_real_estate(skb);
    return end;
}
