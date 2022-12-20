NAME	= pipex

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3

SRC_DIR		= 	./src/
SRC_FILES 	=					\
								$(SRC_DIR)pipex.c \
								$(SRC_DIR)libft_utils.c \
								$(SRC_DIR)ft_split.c \
								$(SRC_DIR)pipex_utils.c


SRC_OBJS				=		$(SRC_FILES:.c=.o)

AR		= ar -crs
RM		= rm -f

OBJECTS			= $(SRC_OBJS)

all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
			$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

bonus	:	$(BNAME)

$(BNAME) :	$(OBJECTS_BONUS)
			$(CC) $(OBJECTS_BONUS) -o $(BNAME)

clean	:
			$(RM) $(OBJECTS)

fclean	: 	clean
			$(RM) $(NAME)
re		:
			make fclean
			make all

.PHONY	: bonus all clean fclean re%