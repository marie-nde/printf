#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	int *p;
	int a = 10;

	p = &a;
	printf("Real printf :\n");
	printf("|%d|", 42);
	printf("\n\nMy printf\n");
/*	ft_printf("|%d|\n", 42);*/
	return (0);
}
