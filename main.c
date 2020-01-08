#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	int *p;
	int a = 10;

	p = &a;
	printf("Real printf :\n");
	printf("|%4d|", 4);
	printf("\n\nMy printf\n");
	ft_printf("|%4d|\n", 45);

/*	printf("\n\nint max|%d|\n", 2147483647);
	printf("int min |%d|\n", -2147483648);
	printf("max u w/ d |%d|\n", 4294967295);
	printf("max u w/ u |%u|\n", 4294967295);
	printf("max u + 1 w/ u |%u|\n", 42949672956);
	printf("-1 |%u|\n", -1);
	printf("int max |%i|\n", 2147483647);
	printf("int max + 1 |%d|\n", 2147483648);
	printf("int min - 1 |%i|\n", -2147483649);
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
	printf("|%-.6d|\n", 3);*/
	return (0);
}
