
CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = ex03

SRCS = main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		PresidentialPardonForm.cpp

DEPS = Bureaucrat.hpp \
		AForm.hpp \
		RobotomyRequestForm.hpp \
		ShrubberyCreationForm.hpp \
		PresidentialPardonForm.hpp


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

