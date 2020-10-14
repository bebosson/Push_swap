#include "inc.h"

void	ft_error()
{
	ft_putendl("Error"); //free_and_exit
	exit(EXIT_FAILURE);
}

int	check_inst(int ret)
{
	if (ret < 3 || ret > 5)
		ft_error();
	
	return (0);	
}

t_stack	*array_inst(char inst[])
{
	int i;
	t_stack *new_element;
	static char str[10][4] = {"pa","pb", "ra", "rb", "rr", "rra", "rrb",
		"rrr","sa", "sb"};

	i = -1;
	while (++i < 10)
	{
		if (ft_strequ(str[i], inst) == 1)
		{
			if (!(new_element = (t_stack*)malloc(sizeof(t_stack))))
				return (0);
			new_element->value = i;
			new_element->next = NULL;
			return (new_element);
		}
	}
	return (0);
}

int	check_double(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (++j < ac && i != j)
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (-1);
	}
	return (0);
}

int	check_arg(int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac)
		if (!ft_str_is_numeric(av[i]))
			return (-1);
	if (check_double(ac, av))
		return (-1);
	return (0);
}
