NAME	= checker

CC		= cc


SRC_DIR_BONUS		= 	./checker_src/src/
SRC_FILES_BONUS 	=				\
							$(SRC_DIR)checker.c \
							$(SRC_DIR)ERROR_check.c \
							$(SRC_DIR)ft_split.c \
							$(SRC_DIR)linked_list.c \
							$(SRC_DIR)utils.c \
							$(SRC_DIR)utils2.c \

COMMAND_SRC_DIR_BONUS = ./checker_src/command_src/
COMMAND_SRC_FILES_BONUS =			\
							$(COMMAND_SRC_DIR)command.c \
							$(COMMAND_SRC_DIR)reverse_rotate_command.c \
							$(COMMAND_SRC_DIR)rotate_command.c

GNL_SRC_DIR_BONUS		=	./checker_src/gnl/
GNL_SRC_FILES_BONUS	=			\
							$(GNL_SRC_DIR)get_next_line.c \
							$(GNL_SRC_DIR)get_next_line_utils.c

SRC_OBJS_BONUS				=	$(SRC_FILES:.c=.o)
COMMAND_SRC_OBJS_BONUS		=	$(COMMAND_SRC_FILES:.c=.o)
GNL_SRC_OBJS_BONUS			=	$(GNL_SRC_FILES:.c=.o)

AR		= ar -crs
RM		= rm -f


OBJECTS_BONUS	= $(SRC_OBJS_BONUS) $(COMMAND_SRC_OBJS_BONUS) $(GNL_SRC_OBJS_BONUS)
OBJECTS	= $(SRC_OBJS) $(COMMAND_SRC_OBJS) $(GNL_SRC_OBJS)


all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
			$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

bonus	:	$(OBJS_BONUS])
			$(CC) $(OBJECTS_BONUS) -o $(BNAME)

clean	:
			$(RM) $(OBJECTS)

fclean	: 	clean
			$(RM) ../$(NAME)

re		: 
			make fclean
			make all

.PHONY	: bonus all clean fclean re
