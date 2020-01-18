/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:29:32 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/17 14:28:13 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * neg);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(s1) +
	ft_strlen(s2) + 1))))
		return (NULL);
	while (s1 && s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}

int		ft_type(const char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_check_conv(str[i]) == 0)
		i++;
	return (str[i]);
}
