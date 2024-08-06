SRCS	= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp ICharacter.cpp IMateriaSource.cpp
OBJS	= $(SRCS:.cpp=.o)
NAME	= a.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g 
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re