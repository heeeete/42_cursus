NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
MFLAGS 	= -lmlx -framework OpenGl -framework AppKit -Imlx
MLX_DIR = mlx_opengl

SRC_DIR		= 	./src/
SRC_FILES 	=					\
								$(SRC_DIR)so_long.c \
								$(SRC_DIR)init.c \
								$(SRC_DIR)utils.c \
								$(SRC_DIR)ft_split.c \
								$(SRC_DIR)get_next_line.c \
								$(SRC_DIR)get_next_line_utils.c \
								$(SRC_DIR)move.c \
								$(SRC_DIR)dfs.c


SRC_OBJS				=		$(SRC_FILES:.c=.o)

AR		= ar -crs
RM		= rm -f

OBJECTS			= $(SRC_OBJS)

all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
			$(MAKE) -C mlx_opengl
			$(CC) $(CFLAGS) -L./$(MLX_DIR) $(MFLAGS) $(OBJECTS) -o $(NAME)

bonus	:	$(BNAME)

$(BNAME) :	$(OBJECTS_BONUS)
			$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(BNAME)

clean	:
			$(RM) $(OBJECTS)

fclean	: 	clean
			$(RM) $(NAME)
re		:
			make fclean
			make all

.PHONY	: bonus all clean fclean re