/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:42 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/08 15:34:32 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_struct
{
	int width;
	int minus;
	int star;
	int zero;
	int point;
}				t_struct;

int				ft_printf(const char *str, ...);
void			ft_print_char(char c);
void			ft_print_str(char *str);
void			ft_print_nbr(int nb);
char			ft_get_char(va_list list);
char			*ft_get_str(va_list list);
int				ft_get_int(va_list list);
unsigned int	ft_get_unsigned(va_list list);
unsigned long	ft_get_pointer(va_list list);
void			ft_print_hexa(int nb, char x);
void			ft_base_low(long n);
void			ft_base_caps(long n);
void			ft_print_unsigned(unsigned int nb);
void			ft_print_address(unsigned long ad);
int				ft_atoi(const char *str);

#endif
