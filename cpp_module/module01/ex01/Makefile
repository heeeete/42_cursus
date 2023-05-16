CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror -g -fsanitize=address

NAME = Zombie

SRCS = Zombie.cpp \
		zombieHorde.cpp \
		main.cpp

DEPS = Zombie.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

