/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:44:05 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/30 11:48:39 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcut(char *str, t_struct *s_flags)
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * s_flags->point + 1)))
		return (NULL);
	while (i < s_flags->point)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_ptrcut(char *arg, int len)
{
	int		i;
	int		j;
	char	*new;

	i = 2;
	j = 0;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (j < len)
		new[j++] = arg[i++];
	new[j] = '\0';
	free(arg);
	return (new);
}

char	*ft_minus_cut(char *arg)
{
	char	*new;
	int		j;
	int		i;

	i = 0;
	j = 1;
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(arg))))
		return (NULL);
	while (i < ft_strlen(arg) - 1)
		new[i++] = arg[j++];
	new[i] = '\0';
	free(arg);
	return (new);
}
