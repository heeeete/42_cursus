NAME	= push_swap

CC		= cc

CFLAGS 	=-Wall -Wextra -Werror
##AA = -fsanitize=address

SRC_DIR		= 	./src/
SRC_FILES 	=				\
							$(SRC_DIR)set_arr.c \
							$(SRC_DIR)ERROR_check.c \
							$(SRC_DIR)ft_split.c \
							$(SRC_DIR)linked_list.c \
							$(SRC_DIR)push_swap.c \
							$(SRC_DIR)quick_sort.c \
							$(SRC_DIR)sort.c \
							$(SRC_DIR)utils.c \
							$(SRC_DIR)utils2.c \
							$(SRC_DIR)separation.c \
							$(SRC_DIR)add_action.c


COMMAND_SRC_DIR = ./command_src/
COMMAND_SRC_FILES =			\
							$(COMMAND_SRC_DIR)command.c \
							$(COMMAND_SRC_DIR)reverse_rotate_command.c \
							$(COMMAND_SRC_DIR)rotate_command.c

SRC_OBJS				=	$(SRC_FILES:.c=.o)
COMMAND_SRC_OBJS		=	$(COMMAND_SRC_FILES:.c=.o)
OBJS_BONUS 	=				$(FILES_BONUS:.c=.o)

AR		= ar -crs
RM		= rm -f

ifdef WITH_BONUS
			OBJECTS	= $(SRC_OBJS) $(COMMAND_SRC_OBJS) $(OBJS_BONUS)
else
			OBJECTS	= $(SRC_OBJS) $(COMMAND_SRC_OBJS)
endif

all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

bonus	:	
			make WITH_BONUS=1 all

clean	:
			$(RM) $(OBJECTS)

fclean	: 	clean
			$(RM) $(NAME)

re		: 
			make fclean
			make all

.PHONY	: bonus all clean fclean re
