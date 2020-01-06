#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	printf("Real printf :\n");
	printf("|%d|", 42);
	printf("\n\nMy printf\n");
	ft_printf("|%d|\n", 42);
	return (0);
}
