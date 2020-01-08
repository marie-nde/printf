/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:34:45 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/08 15:34:51 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_read(const char *str, va_list list)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				ft_print_char(str[i]);
			else if (str[i] == 'c')
				ft_print_char(ft_get_char(list));
			else if (str[i] == 's')
				ft_print_str(ft_get_str(list));
			else if (str[i] == 'd' || str[i] == 'i')
				ft_print_nbr(ft_get_int(list));
			else if (str[i] == 'x' || str[i] == 'X')
				ft_print_hexa(ft_get_int(list), str[i]);
			else if (str[i] == 'u')
				ft_print_unsigned(ft_get_unsigned(list));
			else if (str[i] == 'p')
				ft_print_address(ft_get_pointer(list));
			i++;
		}
		ft_print_char(str[i]);
		i++;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list		list;
	t_struct	s_struct;

	va_start(list, str);
	ft_read(str, list);
	va_end(list);
	return (0);
}
