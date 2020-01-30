/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:42 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/30 15:52:58 by mnaude           ###   ########.fr       */
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
	int		special_char;

}				t_struct;

int				ft_printf(const char *str, ...);
int				ft_print_char(char c);
int				ft_print_str(char *str, t_struct *s_flags);
char			ft_get_char(va_list list);
char			*ft_get_str(va_list list);
int				ft_get_int(va_list list);
unsigned int	ft_get_unsigned(va_list list);
unsigned long	ft_get_pointer(va_list list);
int				ft_atoi(char *str);
char			*ft_strdup(char *str);
char			*ft_itoa(int n);
char			*ft_xtoa(int n, char x);
char			*ft_ctoa(int c);
int				ft_check(char c);
int				ft_minus(char *str, t_struct *s_flags);
int				ft_zero(char *str, t_struct *s_flags);
int				ft_width(char *str, va_list list);
int				ft_point(char *str, va_list list);
char			*ft_conversion(char *str, va_list list, t_struct *s_flags);
char			*ft_ptoa(unsigned long nb, t_struct *s_flags);
char			*ft_strjoin(char *s1, char *s2, t_struct *s_flags);
char			*ft_utoa(unsigned int nb);
int				ft_strlen(char *str);
int				ft_check_conv(char c);
char			*ft_strcut(char *str, t_struct *s_flags);
int				ft_checkpoint(char *str);
int				ft_type(char *str);
char			*ft_fill_str(char c, int len);
char			*ft_ptrcut(char *arg, int le);
char			*ft_ptrzero(int len);
char			*ft_minus_cut(char *arg);
char			*ft_minus_point(int len);
void			ft_is_str(char **arg, char **width, t_struct *s_flags);
void			ft_is_char(char **arg, char **width, t_struct *s_flags);
void			ft_is_un(char **arg, char **width, t_struct *s_flags,
char **precision);
void			ft_is_pt(char **arg, char **width, t_struct *s_flags,
char **precision);
void			ft_is_x(char **arg, char **width, t_struct *s_flags,
char **precision);
void			ft_is_int(char **arg, char **width, t_struct *s_flags,
char **precision);
int				ft_special_char(t_struct *s_flags);

#endif
