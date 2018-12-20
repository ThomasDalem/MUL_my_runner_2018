##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	    =	main.c		\
		arguments_check.c	\
		game_loop.c		\
		button_functions.c	\
		object_functions.c	\
		anim_player.c		\
		analyse_events.c	\
		anim_background.c	\
		create_window.c
FLAGS	    =	-L. -lmy -Iinclude -Wall -Werror -Wextra -g

CSFMLFLAGS  =	-lcsfml-graphics -lcsfml-system -lcsfml-audio

LIBPATH	    =	./lib/

NAME	    =	my_runner

all: $(NAME)

$(NAME):
	make -C $(LIBPATH)
	gcc -o $(NAME) $(SRC) $(FLAGS) $(CSFMLFLAGS)
	rm -f $(OBJ)

clean:
	make clean -C $(LIBPATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -f $(NAME)

re: fclean all
