CC := cc
CFLAGS := -Wall -Werror -Wextra -O2 -foptimize-sibling-calls
NAME := philo

SRCS := mini_ft.c gc.c main.c init.c
OBJS := $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(patsubst %.o, %.c, $@)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PNONY: all clean fclean re
