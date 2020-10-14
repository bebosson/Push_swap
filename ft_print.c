#include "inc.h"

int		print_stack(t_stack *stack)
{
	t_stack *cpy_stk;

	if (!stack)
	{
		printf("NULL\n");
		return (-1);
	}
	cpy_stk = stack;
	printf("------\n");
	printf("%d\n", cpy_stk->value);
	cpy_stk = cpy_stk->next;
	while (cpy_stk != stack)
	{
		printf("%d\n", cpy_stk->value);
		cpy_stk = cpy_stk->next;
	}
	return (0);
}

int		print_stack_reverse(t_stack *stack)
{
	t_stack *cpy_stk;

	if (!stack || !(stack->previous))
	{
		printf("NULL\n");
		return (-1);
	}
	cpy_stk = stack;
	printf("------\n");
	cpy_stk = cpy_stk->previous;
	while (cpy_stk != stack)
	{
		printf("%d\n", cpy_stk->value);
		cpy_stk = cpy_stk->previous;
	}
	printf("%d\n", cpy_stk->value);
	return (0);
}

int		print_list(t_stack *stack)
{
	t_stack *cpy_stk;

	if (!stack)
	{
		printf("NULL\n");
		return (-1);
	}
	cpy_stk = stack;
	while (cpy_stk != NULL)
	{
		printf("%d\n", cpy_stk->value);
		cpy_stk = cpy_stk->next;
	}
	return (0);
}
