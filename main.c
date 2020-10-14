#include "inc.h"
// il faut deux stacks => listes chainees

int main(int ac, char **av) //read the instruction by the av
{
	
	// il faut checker si 
	if (ac < 2 || check_arg(ac, av)) // et suffisamment d instruction ?  
		ft_error();
	else
		ft_checker(ac, av);
}
