/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_each_type2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:30:59 by mnaude            #+#    #+#             */
/*   Updated: 2020/02/01 13:57:06 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_else_int(char **arg, char **width, t_struct *s_flags,
char **precision)
{
	if (*arg && *arg[0] == '-')
	{
		*arg = ft_minus_cut(*arg);
		*precision = ft_minus_point(s_flags->point - ft_strlen(*arg) + 1);
		*arg = ft_strjoin(*precision, *arg, s_flags);
		*width = ft_fill_str(s_flags->zero, s_flags->width -
		s_flags->point - 1);
	}
	else
	{
		*precision = ft_fill_str('0', s_flags->point - ft_strlen(*arg));
		*arg = ft_strjoin(*precision, *arg, s_flags);
		*width = ft_fill_str(s_flags->zero, s_flags->width - s_flags->point);
	}
}

void	ft_else_zero(char **arg, t_struct *s_flags,
char **precision)
{
	if (*arg && *arg[0] == '-')
	{
		*arg = ft_minus_cut(*arg);
		*precision = ft_minus_point(s_flags->width - ft_strlen(*arg));
	}
	else if (s_flags->width >= ft_strlen(*arg))
		*precision = ft_fill_str('0', s_flags->width - ft_strlen(*arg));
	*arg = ft_strjoin(*precision, *arg, s_flags);
}

void	ft_is_int(char **arg, char **width, t_struct *s_flags, char **precision)
{
	if (s_flags->width > 0 && s_flags->zero == ' ' && s_flags->width >=
	ft_strlen(*arg) && ((s_flags->width > s_flags->point && s_flags->point
	< ft_strlen(*arg)) || (s_flags->point == ft_strlen(*arg) &&
	*arg[0] != '-')))
		*width = ft_fill_str(' ', s_flags->width - ft_strlen(*arg));
	else if (s_flags->point > 0 && s_flags->point >= s_flags->width &&
	s_flags->point >= ft_strlen(*arg))
	{
		if (*arg && *arg[0] == '-')
		{
			*arg = ft_minus_cut(*arg);
			*precision = ft_minus_point(s_flags->point - ft_strlen(*arg) + 1);
		}
		else
			*precision = ft_fill_str('0', s_flags->point - ft_strlen(*arg));
		*arg = ft_strjoin(*precision, *arg, s_flags);
	}
	else if (s_flags->width > s_flags->point && (s_flags->point >
	ft_strlen(*arg) || (s_flags->point == ft_strlen(*arg) && *arg[0] == '-')))
		ft_else_int(arg, width, s_flags, precision);
	else if (s_flags->width > s_flags->point && s_flags->zero == '0' &&
	s_flags->width >= ft_strlen(*arg))
		ft_else_zero(arg, s_flags, precision);
}

int		ft_point_here(char *str, char *arg, char c)
{
	int i;

	i = 0;
	while (str && str[i] && (ft_check(str[i]) == 1 || ft_check(str[i]) == 2))
	{
		if (str[i] && str[i] == '.')
		{
			if (c == 's')
				return (1);
			if (ft_atoi(arg) == 0 && (c == 'u' || c == 'i' || c == 'd'))
				return (1);
			if (arg && arg[0] == '0' && (c == 'x' || c == 'X'))
				return (1);
		}
		i++;
	}
	return (0);
}
