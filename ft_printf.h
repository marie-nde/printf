/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:42 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/06 15:33:53 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

/*int		ft_printf(const *char);*/
void	ft_print_char(char c);
void	ft_print_str(char *str);
void	ft_print_nbr(int nb);
void	ft_print_hexa(int nb, char c);

# endif
