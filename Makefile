##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	    =	src/main.c		\
		src/arguments_check.c	\
		src/game_loop.c		\
		src/button_functions.c	\
		src/object_functions.c	\
		src/anim_player.c	\
		src/analyse_events.c	\
		src/anim_background.c	\
		src/create_window.c		\
		src/create_rect.c		\
		src/background_functions.c	\
		src/player_functions.c

FLAGS	    =	-L. -lmy -I./src/include -g3 -Wall -Werror -Wextra

CSFMLFLAGS  =	-lcsfml-graphics -lcsfml-system

LIBPATH	    =	./src/lib/

NAME	    =	my_runner

all: $(NAME)

$(NAME):
	make -C $(LIBPATH)
	gcc -o $(NAME) $(SRC) $(FLAGS) $(CSFMLFLAGS)

clean:
	make clean -C $(LIBPATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -f $(NAME)

re: fclean all
