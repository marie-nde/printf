#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	int *p;
	int a = 2000000;

	p = &a;
	printf("\n%d, ", printf("%05s yo %-24.30p et %-.6d\n", NULL, p, -34));
	printf("%d\n", ft_printf("%05s yo %-24.30p et %-.6d", NULL, p, -34));
	return (0);
}
