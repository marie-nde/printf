/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_each_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:10:24 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/30 16:05:03 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_str(char **arg, char **width, t_struct *s_flags)
{
	if ((s_flags->width >= s_flags->point && s_flags->point < ft_strlen(*arg)
	&& s_flags->point != 0) || (s_flags->point < ft_strlen(*arg) &&
	s_flags->point > s_flags->width))
		*arg = ft_strcut(*arg, s_flags);
	*width = ft_fill_str(s_flags->zero, s_flags->width - ft_strlen(*arg));
}

void	ft_is_char(char **arg, char **width, t_struct *s_flags)
{
	if (s_flags->width > 0 && s_flags->special_char == 1)
		*width = ft_fill_str(s_flags->zero, s_flags->width - 1);
	else if (s_flags->width > 0)
		*width = ft_fill_str(s_flags->zero, s_flags->width -
		ft_strlen(*arg));
}

void	ft_is_un(char **arg, char **width, t_struct *s_flags, char **precision)
{
	if (s_flags->point >= s_flags->width)
	{
		*precision = ft_fill_str('0', s_flags->point - ft_strlen(*arg));
		*arg = ft_strjoin(*precision, *arg, s_flags);
	}
	else if (s_flags->width > 0 && s_flags->width > s_flags->point
	&& s_flags->point < ft_strlen(*arg))
		*width = ft_fill_str(s_flags->zero, s_flags->width -
		ft_strlen(*arg));
}

void	ft_is_pt(char **arg, char **width, t_struct *s_flags, char **precision)
{
	if ((s_flags->width > 0 && (s_flags->width > s_flags->point &&
	s_flags->zero == ' ')) || (s_flags->width > 0 &&
	(s_flags->point <= ft_strlen(*arg))))
		*width = ft_fill_str(s_flags->zero, s_flags->width - ft_strlen(*arg));
	else if (s_flags->width > s_flags->point && s_flags->point == 0
	&& s_flags->zero == '0')
	{
		*arg = ft_ptrcut(*arg, ft_strlen(*arg) - 2);
		*precision = ft_ptrzero(s_flags->width - ft_strlen(*arg));
		*arg = ft_strjoin(*precision, *arg, s_flags);
	}
	else if (s_flags->point > s_flags->width ||
	s_flags->point > ft_strlen(*arg))
	{
		*arg = ft_ptrcut(*arg, ft_strlen(*arg) - 2);
		*precision = ft_ptrzero(s_flags->point - ft_strlen(*arg) + 2);
		*arg = ft_strjoin(*precision, *arg, s_flags);
	}
}

void	ft_is_x(char **arg, char **width, t_struct *s_flags, char **precision)
{
	if ((s_flags->width > 0 && s_flags->point == 0) ||
	(s_flags->width > s_flags->point && s_flags->point <= ft_strlen(*arg)))
		*width = ft_fill_str(s_flags->zero, s_flags->width - ft_strlen(*arg));
	else if ((s_flags->point > 0 && s_flags->width == 0) ||
	s_flags->point >= s_flags->width)
	{
		*precision = ft_fill_str('0', s_flags->point - ft_strlen(*arg));
		*arg = ft_strjoin(*precision, *arg, s_flags);
	}
	else if (s_flags->width > s_flags->point &&
	s_flags->point > ft_strlen(*arg))
	{
		*precision = ft_fill_str('0', s_flags->point - ft_strlen(*arg));
		*arg = ft_strjoin(*precision, *arg, s_flags);
		*width = ft_fill_str(s_flags->zero, s_flags->width -
		s_flags->point);
	}
}
