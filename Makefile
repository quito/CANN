
NAME	=	neuronne

SRC	=	main.c \
		ANN.c \
		list.c

CC	=	clang

OBJ	=	$(SRC:.c=.o)

CFLAGS =	-w -Wall -Wextra -ggdb

LDFLAGS =	-lSDL -lm

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@