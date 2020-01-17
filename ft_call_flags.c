/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:32:04 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/17 15:49:39 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_only(t_struct *s_flags, char *arg, char *str)
{
	if (s_flags->zero == '0' && ft_atoi(arg) < 0)
	{
		arg = ft_strcut(arg);
		str = ft_strwidth_minus(s_flags->width - ft_strlen(arg));
	}
	else
		str = ft_strregular(arg, s_flags->zero, s_flags->width);
}

void	ft_point_regular(t_struct *s_flags, char *arg, char *str)
{
	if (ft_atoi(arg) < 0)
	{
		arg = ft_strcut(arg);
		str = ft_strpoint_minus(arg, s_flags);
	}
	else
		str = ft_strregular(arg, '0', s_flags->point);
}

void	ft_more_width(t_struct *s_flags, char *arg, char *str, char *str2)
{
	if (ft_atoi(arg) < 0)
	{
		str = ft_strpoint_minus(arg, s_flags);
		str2 = ft_strboth(s_flags->width - s_flags->point - 1, s_flags->zero);
		arg = ft_strcut(arg);
	}
	else
	{
		str = ft_strregular(arg, '0', s_flags->point);
		str2 = ft_strregular(arg, s_flags->zero, s_flags->point);
	}
	str = ft_strjoin(str, arg);
}
