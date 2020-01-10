/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:45:16 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/09 15:48:54 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count(long nb)
{
	int compt;

	compt = 0;
	if (nb > 0 && nb < 10)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		compt++;
	}
	return (compt);
}

char	*ft_tostring(char *str, long nb, int i)
{
	if (nb < 0)
	{
		nb = nb * -1;
		while (nb > 0)
		{
			str[i--] = (nb % 10) + '0';
			nb = nb / 10;
		}
	}
	if (nb > 0)
		while (nb > 0)
		{
			str[--i] = (nb % 10) + '0';
			nb = nb / 10;
		}
	return (str);
}

char	*ft_if(char *str, long nb, int i)
{
	if (nb == 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	else if (nb > 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * i + 1)))
			return (NULL);
		str[i] = '\0';
	}
	else if (nb < 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * i + 2)))
			return (NULL);
		str[0] = '-';
		str[i + 1] = '\0';
	}
	str = ft_tostring(str, nb, i);
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	int		i;

	nb = n;
	str = NULL;
	i = 0;
	if (nb > 0)
		i = ft_count(nb);
	if (nb < 0)
		i = ft_count(-nb);
	str = ft_if(str, nb, i);
	return (str);
}
