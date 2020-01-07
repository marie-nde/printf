#include "ft_printf.h"

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

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
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
	}
	if (nb > 9)
		ft_print_nbr(nb / 10);
	ft_print_char((nb % 10) + '0');
}
