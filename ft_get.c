/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:40:33 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/31 14:11:12 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			ft_get_char(va_list list)
{
	return (va_arg(list, int));
}

char			*ft_get_str(va_list list)
{
	return (va_arg(list, char*));
}

int				ft_get_int(va_list list)
{
	return (va_arg(list, int));
}

unsigned int	ft_get_unsigned(va_list list)
{
	return (va_arg(list, unsigned int));
}

unsigned long	ft_get_pointer(va_list list)
{
	return (va_arg(list, unsigned long));
}
