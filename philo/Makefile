CC := cc
CFLAGS := -Wall -Werror -Wextra -O2 -foptimize-sibling-calls
NAME := philo

SRCS := atomic.c etc.c gc.c init.c lifecycle.c lifecycle2.c \
	main.c mini_ft.c
OBJS := $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -lpthread $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(patsubst %.o, %.c, $@)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PNONY: all clean fclean re
