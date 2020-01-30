/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:46:49 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/30 15:44:12 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_print_str(char *str, t_struct *s_flags)
{
	int	i;

	i = 0;
	while (str && str[i])
		ft_print_char(str[i++]);
	if (str && s_flags->special_char == 1)
	{
		write(1, &str[i++], 1);
		while (i < s_flags->width)
			ft_print_char(str[i++]);
	}
	free(str);
	return (i);
}
