#include "inc.h"

int		ft_rotate_a(t_stack *stack)
{
	t_stack *cpy_stk;
	int	a_value;
	int	b_value;
	
	if (!stack)
		return (-1);
	cpy_stk = stack->next;
	a_value = stack->value;
	while (cpy_stk != stack)
	{
		b_value = cpy_stk->value;
		cpy_stk->value = a_value;
		a_value = b_value;
		cpy_stk = cpy_stk->next;
	}
	cpy_stk->value = a_value;
	return (0);
}

int		ft_reverse_rotate_a(t_stack *stack)
{
	t_stack *cpy_stk;
	int	a_value;
	int	b_value;
	
	if (!stack)
		return (-1);
	cpy_stk = stack->previous;
	a_value = stack->value;
	while (cpy_stk != stack)
	{
		b_value = cpy_stk->value;
		cpy_stk->value = a_value;
		a_value = b_value;
		cpy_stk = cpy_stk->previous;
	}
	cpy_stk->value = a_value;
	return (0);
}

void	ft_swap_address(t_stack **stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	tmp = *stack_a;
	*stack_a = stack_b;
	stack_b = tmp;
}

int		ft_swap_a(t_stack **stack)
{
	if (!stack || !((*stack)->next))
		return (-1);
	ft_swap_address(stack, (*stack)->next);
	return (0);	
}
