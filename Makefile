CC = gcc
SPC = *.c
OBJ = $(SRC:.c=.o)
NAME = hsh
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

all:
	$(CC) $(SPC) -o $(NAME)

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: oclean clean
