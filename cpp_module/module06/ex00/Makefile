
CXX = c++

CXXFLAGS = -std=c++98 -g -fsanitize=address

NAME = convert

SRCS = main.cpp \
		ScalarConverter.cpp

DEPS = ScalarConverter.hpp \


OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

