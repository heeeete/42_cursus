NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

FILES 	=		ft_printf.c \
				ft_put_sc.c \
				ft_puthex_pXx.c \
				ft_putnbr_idu.c \

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
			$(AR) $(NAME) $(OBJECTS)

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
