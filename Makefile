##
## EPITECH PROJECT, 2021
## makefile evalexpr
## File description:
## makefile for evalxpr
##

SRC = 	my_sokoban.c \
		libpool/my_nbrtostr.c \
		libpool/my_put_in_terminal.c \
		libpool/my_revstr.c \
		libpool/my_str_to_word_array.c \
		libpool/my_strcat.c \
		libpool/my_strlen.c \
		libpool/my_strtonbr.c \
		libpool/my_arrayheight.c \
		libpool/my_strxdup.c \
		libpool/my_strcompare.c \
		libpool/my_remove_from_array.c \
		libpool/my_array_to_str.c \
		libpool/my_add_to_str.c \
		libpool/my_arraycpy.c \
		src/get_board.c \
		src/parsing.c \
		src/mvlr.c \
		src/mvud.c \
		src/check_args.c \
		src/checkers.c \
		src/is_win.c \
		src/its_free_real_estate.c \
		src/win_display.c \
		src/getch_handler.c

OBJ =	$(SRC:.c=.o)

NAME = 	my_sokoban

all:	$(NAME)

$(NAME):	${OBJ}
	gcc -lncurses -o ${NAME} ${OBJ}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ${NAME}

re: fclean all

debug:     ${OBJ}
	gcc -lncurses -g -W -Wall -Wextra -Werror -o $(NAME) $(SRC)