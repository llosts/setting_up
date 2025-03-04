##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for the 101 pong program
##

SRC			=	src/error_gestion.c				\
				src/file_gestion.c				\
				src/generate_or_read_map.c		\
				src/display_functions.c			\
				src/memory_gestion.c			\
				src/special_case.c				\
				src/setting_up.c				\

MAIN_SRC 	=	src/main.c

TEST_SRC 	=	tests/tests_my_file_gestion.c			\
				tests/tests_my_display_functions.c		\
				tests/tests_my_special_case.c			\
				tests/tests_my_error_gestion.c			\
				tests/tests_my_memory_gestion.c			\
				tests/tests_my_generate_or_read_map.c	\
				tests/tests_my_setting_up.c

OBJ			=	$(SRC:.c=.o)
MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

CMAKE		=	make -C ./lib/my
CTESTS		=	-lcriterion --coverage
CGCOVR		=	gcovr --exclude tests ; gcovr --branch --exclude tests
CFLAGS		=   -Wall -Wextra -Werror
CPPFLAGS 	=	-iquote include
LIBFLAGS	=	-L lib/ -lmy
RM			=	rm -f
CC			=	gcc

TEST_NAME	=	unit_tests
NAME        =   setting_up

all:			clib $(NAME)

clib:
		$(CMAKE)

$(NAME):		$(OBJ) $(MAIN_OBJ)
		$(CC) -o $(NAME) $(OBJ) $(MAIN_OBJ) $(LIBFLAGS)

$(TEST_NAME):	clean all
		$(CC) -o $(TEST_NAME) $(TEST_SRC) $(SRC) $(CTESTS)	\
		$(LIBFLAGS) $(CPPFLAGS)

tests_run:      $(TEST_NAME)
		./$(TEST_NAME) ; $(CGCOVR)

clean:
		$(RM) $(OBJ)
		$(RM) $(MAIN_OBJ)
		$(RM) $(TEST_OBJ)
		$(RM) *.gcno
		$(RM) *.gcda

fclean:			clean
		$(CMAKE) fclean
		$(RM) $(NAME)
		$(RM) $(TEST_NAME)

re:				fclean all

.PHONY:			all clean fclean all tests_run
