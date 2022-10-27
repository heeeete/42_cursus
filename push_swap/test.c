#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

void	ft_putstr(char *s)
{
	while (*s)
	{
		write (1, s, 1);
		s++;
	}
	write (1, &"\n", 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}

long long ft_atoi(const char *str)
{
	long				sign;
	long long	i;

	sign = 1;
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i *= 10;
		i += (*str - '0');
		str++;
	}
	return ((i * sign));
}

t_list *newnode(t_list **head, char *argv)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	newnode->value = ft_atoi(argv);
	newnode->next = NULL;
	newnode->prev = *head;
	(*head)->next = newnode;
	return (newnode);
}

t_list *init_value(t_list **head, int argc, char *argv[])
{
	t_list *top;

	top = *head;
	while (argc != 1)
	{
		top = newnode(&top, argv[argc - 1]);
		argc--;
	}
	return (top);
}

int ERROR_ckeck(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc == 1)
		return (1);
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (1);
		while (argv[i][j])
		{	if (argv[i][0] == '-')
			{
				j++;
				continue;
			}
			else if ((argv[i][j] < '0' || argv[i][j] > '9'))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int ERROR_check2(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i <= (argc - 2))
	{
		j = i + 1;
		while (j <= (argc - 1))
		{
			if (!(ft_strcmp(argv[i], argv[j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_list	*stack_A;
	t_list	*stack_B;

	if (ERROR_ckeck(argc, argv) || ERROR_check2(argc, argv))
	{
		ft_putstr("Error");
		return (0);
	}
	stack_A = (t_list *)malloc(sizeof(t_list));
	stack_B = (t_list *)malloc(sizeof(t_list));
	if (!stack_A || !stack_B)
		return (0);
	stack_A = init_value(&stack_A, argc, argv);
	printf("%d\n", stack_A->value);
	stack_A = stack_A->prev;
	printf("%d\n", stack_A->value);
	stack_A = stack_A->prev;
	printf("%d\n", stack_A->value);
	stack_A = stack_A->prev;
	printf("%d\n", stack_A->value);
	stack_A = stack_A->prev;
	printf("%d\n", stack_A->value);
}