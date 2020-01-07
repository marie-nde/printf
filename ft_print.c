#include "ft_printf.h"

void	ft_print_str(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
}

void	ft_print_nbr(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
	}
	if (n > 9)
		ft_print_nbr(n / 10);
	ft_print_char((n % 10) + '0');
}

void	ft_print_hexa(int nb, char c)
{
	long n;
	char *low;
	char *caps;

	n = nb;
	low = "0123456789abcdef";
	caps = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
	}
	if (c == 'x')
	{
		if (n > 9)
			ft_print_hexa(n / 16, c);
		ft_print_char(low[n % 16] + '0');
	}
	else if (c == 'X')
	{
		if (n > 9)
			ft_print_hexa(n / 16, c);
		ft_print_char(caps[n % 16] + '0');
	}
}
