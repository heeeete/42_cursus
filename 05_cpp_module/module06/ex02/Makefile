
CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Wall

NAME = ex02

SRCS = main.cpp \
		utils.cpp \
		Base.cpp \
		A.cpp \
		B.cpp \
		C.cpp

DEPS = A.hpp \
		B.hpp \
		C.hpp \
		Base.hpp \
		utils.hpp


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

