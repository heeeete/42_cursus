CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = phoneBook

SRCS = Contact.cpp \
		PhoneBook.cpp \
		main.cpp

DEPS = Contact.hpp \
		PhoneBook.hpp

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

