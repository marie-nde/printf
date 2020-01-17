#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	int *p;
	int a = 2000000;

	p = &a;
	printf("\n%d, ", printf("%05s yo %-7.10s et %-.6s\n", NULL, "true", "potote"));
	printf("%d\n", ft_printf("%05s yo %-7.10s et %-.6ss", NULL, "true", "potote"));
	return (0);
}
