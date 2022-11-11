NAME        =   push_swap

CC          =   cc
CFLAGS      =	-Wall -Wextra -Werror
SRCS        =	command.c \
				ERROR_check.c \
				ft_split.c \
				linked_list.c \
				push_swap.c \
				quick_sort.c \
				reverse_rotate_command.c \
				rotate_command.c \
				sort.c \
				utils.c


AR          =   ar
ARFLAGS     =   crs

all : mandatory
mandatory: $(NAME)($(SRCS:.c=.o))
bonus : $(NAME)($(SRCS:.c=.o) $(SRCS_BONUS:.c=.o))
clean : ; rm -f *.o
fclean : clean ; rm -f $(NAME)
re : fclean ; make all
.PHONY : bonus all clean fclean re