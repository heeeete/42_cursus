CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = ex01

SRCS = main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		Brain.cpp

DEPS = Animal.hpp \
		Cat.hpp \
		Dog.hpp \
		Brain.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

