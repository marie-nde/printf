/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:44:05 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/17 14:27:44 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcut(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (ft_atoi(str) != 0)
	{
		if (str && str[i] == '-')
			i++;
		if (!(new = (char*)malloc(sizeof(char) * ft_strlen(str + i) + 1)))
			return (NULL);
		while (str && str[i])
			new[j++] = str[i++];
		new[j] = '\0';
		return (new);
	}
	return (str);
}

char	*ft_strregular(char *arg, char c, int compt)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * compt - ft_strlen(arg) + 1)))
		return (NULL);
	while (i < compt - ft_strlen(arg))
		new[i++] = c;
	new[i] = '\0';
	return (new);
}

char	*ft_strpoint_minus(char *arg, t_struct *s_flags)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * s_flags->point -
	ft_strlen(arg) + 2)))
		return (NULL);
	new[i] = '-';
	i++;
	while (i < (s_flags->point + 1) - ft_strlen(arg))
		new[i++] = '0';
	new[i] = '\0';
	return (new);
}

char	*ft_strboth(int len, char c)
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

char	*ft_strwidth_minus(int len)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	new[i] = '-';
	i++;
	while (i < len)
		new[i++] = '0';
	new[i] = '\0';
	return (new);
}
