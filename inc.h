#ifndef INC_H
# define INC_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
# include "libft/libft.h"
#define BUFFSIZE 50

typedef struct s_stack
{	
	struct s_stack *next; // c              b
	struct s_stack *previous; //a			 c
//	struct s_stack *first;
//	struct s_stack *last;
	int value;
}			t_stack;

typedef struct s_env
{
	t_stack *astack; //  9 ->8 ->7 ->1 ->-7 
	t_stack *bstack; // 5->80 
	t_stack *ope; 
}			t_env;

int		ft_swap_a(t_stack **stack);
int		print_stack(t_stack *stack);
int		ft_reverse_rotate_a(t_stack *stack);
int		ft_set_previous(t_stack *stack);
int	ft_rotate_a(t_stack *stack);
int		print_list(t_stack *stack);
int	check_inst(int ret);
t_stack	*array_inst(char inst[]);
t_stack	*ft_save_stack(int ac, char **av);
void	ft_checker(int ac, char **av);
/* ft_check_errors */
int	check_double(int ac, char **av);
int	check_arg(int ac, char **av);
void	ft_error();
#endif
