CXX = c++

CXXFLAGS 	= -std=c++98 -Wall -Werror -Wextra

NAME = btc

SRC = main.cpp \
		BitcoinExchange.cpp

DEPS = BitcoinExchange.hpp


SRCS = $(SRC) $(SRC_CMD)

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
