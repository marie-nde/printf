/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:42 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/17 15:39:57 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flags
{
	char	zero;
	char	minus;
	int		point;
	int		width;
	char	*conversion;
	char	type;

}				t_struct;

int				ft_printf(const char *str, ...);
void			ft_print_char(char c);
int				ft_print_str(char *str);
char			ft_get_char(va_list list);
char			*ft_get_str(va_list list);
int				ft_get_int(va_list list);
unsigned int	ft_get_unsigned(va_list list);
unsigned long	ft_get_pointer(va_list list);
int				ft_atoi(const char *str);
char			*ft_strdup(char *str);
char			*ft_itoa(int n);
char			*ft_xtoa(int n, char x);
char			*ft_ctoa(int c);
int				ft_check(char c);
int				ft_minus(const char *str, t_struct *s_flags);
int				ft_zero(const char *str, t_struct *s_flags);
int				ft_width(const char *str, va_list list);
int				ft_point(const char *str, va_list list);
char			*ft_conversion(const char *str, va_list list);
char			*ft_ptoa(unsigned long nb);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_utoa(unsigned int nb);
int				ft_strlen(char *str);
int				ft_check_conv(char c);
char			*ft_strcut(char *str);
char			*ft_strregular(char *arg, char c, int compt);
char			*ft_strpoint_minus(char *arg, t_struct *s_flags);
int				ft_checkpoint(const char *str);
char			*ft_strboth(int len, char c);
char			*ft_strwidth_minus(int len);
char			*ft_width_only(t_struct *s_flags, char *arg, char *str);
char			*ft_point_regular(t_struct *s_flags, char *arg, char *str);
char			*ft_more_width(t_struct *s_flags, char *arg, char *str, char *str2);
int				ft_type(const char *str);
char			*ft_ptrcut(char *str);
char			*ft_ptrpoint(char *arg, t_struct *s_flags);

#endif
