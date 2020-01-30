/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:32:04 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/30 11:40:02 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill_str(char c, int len)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
		new[i++] = c;
	new[i] = '\0';
	return (new);
}

char	*ft_ptrzero(int len)
{
	char	*new;
	int		i;

	i = 2;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	new[0] = '0';
	new[1] = 'x';
	while (i < len)
		new[i++] = '0';
	new[i] = '\0';
	return (new);
}

char	*ft_minus_point(int len)
{
	char	*new;
	int		i;

	i = 0;
	while (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	new[i] = '-';
	i++;
	while (i < len)
		new[i++] = '0';
	new[i] = '\0';
	return (new);
}
