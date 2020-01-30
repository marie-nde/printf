/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_each_type2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:30:59 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/30 15:59:00 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_else_int(char **arg, char **width, t_struct *s_flags,
char **precision)
{
	if (ft_atoi(*arg) < 0)
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
		*width = ft_fill_str(s_flags->zero, s_flags->width -
		s_flags->point);
	}
}

void	ft_is_int(char **arg, char **width, t_struct *s_flags, char **precision)
{
	if (s_flags->width > 0 && ((s_flags->width > s_flags->point &&
	s_flags->point < ft_strlen(*arg)) || (s_flags->point == ft_strlen(*arg)
	&& *arg[0] != '-')))
		*width = ft_fill_str(s_flags->zero, s_flags->width - ft_strlen(*arg));
	else if (s_flags->point > 0 && s_flags->point >= s_flags->width)
	{
		if (ft_atoi(*arg) < 0)
		{
			*arg = ft_minus_cut(*arg);
			*precision = ft_minus_point(s_flags->point - ft_strlen(*arg) + 1);
			*arg = ft_strjoin(*precision, *arg, s_flags);
		}
		else
		{
			*precision = ft_fill_str('0', s_flags->point -
			ft_strlen(*arg));
			*arg = ft_strjoin(*precision, *arg, s_flags);
		}
	}
	else if (s_flags->width > s_flags->point
	&& (s_flags->point > ft_strlen(*arg)
	|| (s_flags->point == ft_strlen(*arg) && *arg[0] == '-')))
		ft_else_int(arg, width, s_flags, precision);
}

int		ft_special_char(t_struct *s_flags)
{
	if (s_flags->type == 'c' && s_flags->conversion[0] == '\0')
		return (1);
	return (0);
}
