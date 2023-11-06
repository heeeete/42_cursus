CXX = c++

CXXFLAGS 	= -std=c++98
OPT			= -Wall -Werror -Wextra

NAME = ex01

SRC = main.cpp

DEPS = iter.hpp


SRCS = $(SRC)

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(OPT)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
