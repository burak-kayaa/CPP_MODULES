SRCS	= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= zombie

CC		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re