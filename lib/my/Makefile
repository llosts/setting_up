##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compilation of the lib
##

SRC	=	my_str_to_word_array.c		\
		my_strncpy.c			\
		my_strdup.c			\
		my_getnbr.c			\
		my_strlen.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS=	-iquote .
INCLUDE =	../../include
CP	=	cp
RM	=	rm -f
HEADER	=	my.h

NAME 	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CP) $(NAME) ../
	$(CP) $(HEADER) $(INCLUDE)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)
	$(RM) $(INCLUDE)/$(HEADER)

re:	fclean all
