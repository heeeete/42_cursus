CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror -g -fsanitize=address

NAME = run

SRCS = HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \
		main.cpp

DEPS = Weapon.hpp \
		HumanA.hpp \
		HumanB.hpp

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

