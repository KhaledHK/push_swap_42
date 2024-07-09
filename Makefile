
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	error.c handle_input.c push.c revrotate.c rotate.c sort_small.c sort_utility1.c sort_utility2.c sort_utility3.c sort.c \
		 split.c stack_fnct.c stack_fnct1.c stack_fnct2.c swap.c get_next_line.c get_next_line_utils.c\


OBJS = $(SRCS:.c=.o)

NAME = push_swap

MANDATORY_SRCS = push_swap.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

CHECKERNAME = checker

BONUS_SRCS = checker.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MANDATORY_OBJS) -o $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) -o $(CHECKERNAME)

clean:
	rm -f $(OBJS) $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKERNAME)

re: fclean all

.PHONY: all clean fclean re bonus