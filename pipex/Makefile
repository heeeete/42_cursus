NAME	= pipex

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

SRC_DIR		= 	./src/
SRC_FILES 	=					\
								$(SRC_DIR)pipex.c \
								$(SRC_DIR)libft_utils.c \
								$(SRC_DIR)ft_split.c \
								$(SRC_DIR)pipex_utils.c

BONUS_DIR	=	./bonus_src/
BONUS_FILES	=					\
								$(BONUS_DIR)pipex_bonus.c \
								$(BONUS_DIR)ft_split_bonus.c \
								$(BONUS_DIR)pipex_utils_bonus.c \
								$(BONUS_DIR)get_next_line.c \
								$(BONUS_DIR)get_next_line_utils.c \
								$(BONUS_DIR)init_bonus.c

SRC_OBJS				=		$(SRC_FILES:.c=.o)
BONUS_OBJS				=		$(BONUS_FILES:.c=.o)

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
