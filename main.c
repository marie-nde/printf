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
	ft_print_hexa(-42, 'x');

	printf("\n\n|%d|\n", 2147483647);
	printf("|%d|\n", -2147483648);
	printf("|%d|\n", 4294967295);
	printf("|%u|\n", 4294967295);
	printf("|%u|\n", 42949672956);
	printf("|%u|\n", -1);
	printf("|%i|\n", 2147483647);
	printf("|%d|\n", 2147483648);
	printf("|%i|\n", -2147483649);
	printf("|%%|\n");
	printf("|%%d|\n");
	printf("|%0d|\n", 42);
	printf("|%10d|\n", 42);
	printf("|%3d|\n", 15352);
	printf("|%-9d|\n", 42);
	printf("|%0.d|\n", 42);
	printf("|%*d|\n", 3, 32);
	printf("|%04d|\n", -42);
	printf("|%.4d|\n", -42);
	printf("|%0-3d|\n", 42);
	printf("|%0.6d|\n", 3);
	printf("|%-.6d|\n", 3);
	return (0);
}
