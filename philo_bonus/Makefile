NAME = philo_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./

SRC = utils_bonus.c \
		errors_bonus.c \
		colors_bonus.c \
		data_bonus.c \
		actions_bonus.c \
		program_bonus.c \
		stop_bonus.c \
		main_bonus.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
