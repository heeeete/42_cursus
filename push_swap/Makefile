NAME        =   libft.a
CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror
SRCS        =   asd.c

AR          =   ar
ARFLAGS     =   crs
.PHONY : bonus all clean fclean re
all : mandatory
mandatory: $(NAME)($(SRCS:.c=.o))
bonus : $(NAME)($(SRCS:.c=.o) $(SRCS_BONUS:.c=.o))
clean : ; rm -f *.o
fclean : clean ; rm -f $(NAME)
re : fclean ; make all
