/*
** EPITECH PROJECT, 2021
** bsq.h
** File description:
** my_ls
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

#ifndef COMMON_H_
    #define COMMON_H_
    #define SUCCESS 0
    #define ERROR 84
    #define FALSE 0
    #define TRUE 1
    #define SPECIAL 2
    #define WIN 0
    #define LOSS 1

    typedef struct sokoban {
        char **board;
        char **board_backup;
        int boxes_nb;
        int boxes_set;
        int p_loci;
        int p_locj;
        int win;
    } sokoban_t;

    char *my_nbrtostr(int result);
    void my_putchar(char c);
    void my_putstr(char const *str);
    void my_putstr_n(char const *str);
    void my_putnbr(int nbr);
    char *my_revstr(char *str);
    char **my_str_to_word_array(char const *str, char c);
    char *concatenating3(char *begin, char *middle, char *end);
    char *concatenating2(char *begin, char *end);
    int my_strlen(char const *str);
    int my_strtonbr(char *str);
    int my_arrayheight(char **a);
    char *my_strxdups(char *input, int s);
    char *my_strxdupe(char *input, int e);
    char *my_strdupc(char *input, char c);
    int my_strcompare(char *first, char *second);
    int my_strcompare_begin(char *first, char *second);
    char *my_array_to_str(char **array);
    char **my_arraycpy(char **env);
    int do_board(char **output, char *path);
    int parse_board(char *board, sokoban_t *skb);
    int check_args(char **argv, int argc);
    int p_check(sokoban_t *skb);
    void find_p(sokoban_t *skb);
    int getch_handler(sokoban_t *skb);
    void its_free_real_estate(sokoban_t *skb);
    void move_right(sokoban_t *skb);
    void move_left(sokoban_t *skb);
    void move_up(sokoban_t *skb);
    void move_down(sokoban_t *skb);
    void turning_op(sokoban_t *skb);
    int is_win(sokoban_t *skb);
    void check_victory(sokoban_t *skb);
    void check_boxes(sokoban_t *skb);
    void win_display(sokoban_t *skb);

#endif/* !COMMON_H_ */
