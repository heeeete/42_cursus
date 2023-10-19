NAME	= push_swap
BNAME	= checker

CC		= cc
CFLAGS	= -Wall -Werror -Wextra 

SRC_DIR		= 	./src/
SRC_FILES 	=					\
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

SRC_OBJS				=		$(SRC_FILES:.c=.o)
COMMAND_SRC_OBJS		=		$(COMMAND_SRC_FILES:.c=.o)



SRC_DIR_BONUS		= 			./checker_src/src/
SRC_FILES_BONUS 	=			\
								$(SRC_DIR_BONUS)checker.c \
								$(SRC_DIR_BONUS)ERROR_check_bonus.c \
								$(SRC_DIR_BONUS)ft_split_bonus.c \
								$(SRC_DIR_BONUS)linked_list_bonus.c \
								$(SRC_DIR_BONUS)utils_bonus.c \
								$(SRC_DIR_BONUS)utils2_bonus.c \

COMMAND_SRC_DIR_BONUS = 		./checker_src/command_src/
COMMAND_SRC_FILES_BONUS =		\
								$(COMMAND_SRC_DIR_BONUS)command_bonus.c \
								$(COMMAND_SRC_DIR_BONUS)reverse_rotate_command_bonus.c \
								$(COMMAND_SRC_DIR_BONUS)rotate_command_bonus.c

GNL_SRC_DIR_BONUS		=	./checker_src/gnl/
GNL_SRC_FILES_BONUS		=	\
								$(GNL_SRC_DIR_BONUS)get_next_line.c \
								$(GNL_SRC_DIR_BONUS)get_next_line_utils.c

SRC_OBJS_BONUS				=	$(SRC_FILES_BONUS:.c=.o)
COMMAND_SRC_OBJS_BONUS		=	$(COMMAND_SRC_FILES_BONUS:.c=.o)
GNL_SRC_OBJS_BONUS			=	$(GNL_SRC_FILES_BONUS:.c=.o)

AR		= ar -crs
RM		= rm -f

OBJECTS_BONUS	= $(SRC_OBJS_BONUS) $(COMMAND_SRC_OBJS_BONUS) $(GNL_SRC_OBJS_BONUS)
OBJECTS			= $(SRC_OBJS) $(COMMAND_SRC_OBJS)

all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
			$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

bonus	:	$(BNAME)

$(BNAME) :	$(OBJECTS_BONUS)
			$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(BNAME)

clean	:
			$(RM) $(OBJECTS_BONUS)
			$(RM) $(OBJECTS)

fclean	: 	clean
			$(RM) $(NAME)
			$(RM) $(BNAME)
re		: 
			make fclean
			make all

.PHONY	: bonus all clean fclean re
