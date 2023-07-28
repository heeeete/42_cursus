
CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = ex00

SRCS = main.cpp \
		Bureaucrat.cpp

DEPS = Bureaucrat.hpp \


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

