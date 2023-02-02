NAME	= philo

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

SRC_DIR		= 	./src/
SRC_FILES 	=					\


SRC_OBJS				=		$(SRC_FILES:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(BONUS_OBJS)
else
	OBJECTS = $(SRC_OBJS)
endif


all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
			$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

bonus	:	$(BONUS_OBJS)
			make WITH_BONUS=1 all

clean	:
			$(RM) $(SRC_OBJS) $(BONUS_OBJS)

fclean	: 	clean
			$(RM) $(NAME)
re		:
			make fclean
			make all

.PHONY	: bonus all clean fclean re
