SRCS	= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= ex03

CC		= c++

FLAGS	= -Wall -Wextra -Werror -g -std=c++98 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re