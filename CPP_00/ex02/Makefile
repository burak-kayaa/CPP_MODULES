SRCS	= Account.cpp tests.cpp
OBJS	= $(SRCS:.cpp=.o)

CC	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= tests

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re