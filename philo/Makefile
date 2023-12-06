NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./

SRC = utils.c \
		errors.c \
		colors.c \
		data.c \
		actions.c \
		program.c \
		stop.c \
		main.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
