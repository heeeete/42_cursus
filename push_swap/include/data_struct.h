#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
	int				size;
}	t_list;

typedef struct s_head_tail
{
	struct s_list	*head;
	struct s_list	*tail;
}	t_point;

# endif
