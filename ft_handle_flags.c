/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:44:05 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/16 15:01:47 by mnaude           ###   ########.fr       */
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
	if (str[i] == '-')
		i++;
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(str + i) + 1)))
		return (NULL);
	while (str && str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free(str);
	return (new);
}

char	*ft_strwidth(char *arg, t_struct *s_flags)
{
	char *new;
	int i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * s_flags->width + 1)))
		return (NULL);
	while (i < s_flags->width - ft_strlen(arg))
	{
		new[i] = s_flags->zero;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strpoint(char *arg, t_struct *s_flags)
{
	char *new;
	int i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * s_flags->point + 1)))
		return (NULL);
	while (i < s_flags->point - ft_strlen(arg))
	{
		new[i] = '0';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strpoint_minus(char *arg, t_struct *s_flags)
{
	char *new;
	int i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * s_flags->point + 2)))
		return (NULL);
	new[i] = '-';
	s_flags->point = s_flags->point + 1;
	arg = ft_strcut(arg);
	i++;
	while (i < s_flags->point - ft_strlen(arg))
		new[i++] = '0';
	new[i] = '\0';
	return (new);
}
