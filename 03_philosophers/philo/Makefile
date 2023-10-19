NAME	= philo

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
HED		= ./include/philo.h

SRC_FILES 	=	main.c \
				init_utils.c \
				init.c \
				utils.c \
				simulate.c \
				routine.c \
				routine_utils.c



SRC_OBJS				=		$(SRC_FILES:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(BONUS_OBJS)
else
	OBJECTS = $(SRC_OBJS)
endif


all		:	$(NAME)

$(NAME)	:	$(OBJECTS) $(HED)
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
