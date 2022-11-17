NAME	= push_swap

CC		= cc

FILES 	=		command.c \
				ERROR_check.c \
				ft_split.c \
				linked_list.c \
				push_swap.c \
				quick_sort.c \
				reverse_rotate_command.c \
				rotate_command.c \
				sort.c \
				utils.c \
				separation.c \
				arr_init.c 

# FILES_BONUS = 	ft_lstadd_back.c \
# 				ft_lstadd_front.c \
# 				ft_lstclear.c \
# 				ft_lstdelone.c \
# 				ft_lstiter.c \
# 				ft_lstlast.c \
# 				ft_lstmap.c \
# 				ft_lstnew.c \
# 				ft_lstsize.c

OBJS		= $(FILES:.c=.o)
OBJS_BONUS 	= $(FILES_BONUS:.c=.o)

AR		= ar -crs
RM		= rm -f

ifdef WITH_BONUS
			OBJECTS	= $(OBJS) $(OBJS_BONUS)
else
			OBJECTS	= $(OBJS)
endif

all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
			$(CC) -o $(NAME) $(OBJECTS)

bonus	:	
			make WITH_BONUS=1 all

clean	:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean	:	clean
			$(RM) $(NAME)

re		: 
			make fclean
			make all
.PHONY	: bonus all clean fclean re
