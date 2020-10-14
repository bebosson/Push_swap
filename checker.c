#include "inc.h"

t_stack	*ft_save_stack(int ac, char **av)
{
	int		i;
	t_stack	*new_element;
	t_stack	*stack;
	t_stack	*stack_cpy;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stack_cpy = stack;
	stack->value = ft_atoi(av[1]);
	i = 1;
	while (++i < ac)
	{
		if (!(new_element = (t_stack*)malloc(sizeof(t_stack))))
			return (NULL);
		new_element->value = ft_atoi(av[i]);
		new_element->previous = stack;
		stack->next = new_element;
		stack = stack->next;
	}
	stack_cpy->previous = stack;
	stack->next = stack_cpy;
	return (stack_cpy);
}

void	ft_save_list(t_stack **new, t_stack **ope, int i, t_stack **ope_cpy)
{
	if (i == 0)
	{
		*ope = *new;
		*ope_cpy = *ope;
	}
	else
	{
		(*ope)->next = *new;
		*ope = (*ope)->next;
	}
}

int		ft_check_instruction(t_env *env)
{
	int ret;
	char str[BUFFSIZE + 1];
	t_stack *ope_cpy;
	t_stack	*new;
	int				i;

	i = 0;
	while ((ret = read(0, str, BUFFSIZE)) > 0) // au moins 2 ? 
	{
		check_inst(ret); //free la liste
		if (ft_strchr(str, '\n'))
			str[ret - 1] = '\0';
		if ((new = array_inst(str)) == NULL)
			ft_error();	//free la list
		ft_save_list(&new, &env->ope, i, &ope_cpy);
		i++;
	}
	if (i == 0)
		ft_error();
	env->ope = ope_cpy;
	return (0);
}

void	ft_checker(int ac, char **av)
{
	t_env env;

	ft_memset(&env, 0, sizeof(t_env));
	env.astack = ft_save_stack(ac, av);
	ft_check_instruction(&env);
	print_list(env.ope);
	print_stack(env.astack);
//	print_stack_reverse(env.astack);
//	ft_reverse_rotate_a(env.astack);
//	ft_rotate_a(env.astack);
	ft_swap_a(&env.astack);
	print_stack(env.astack);
}
