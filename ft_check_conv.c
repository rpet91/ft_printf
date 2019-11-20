/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_conv.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:17:00 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/20 09:02:56 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_check_conv(t_flag *flag)
{
	if (flag->conversion == 'c')
		return (ft_conv_c(flag));
/*	else if (flag->conversion == 's')
		return (ft_conv_s('s', flag));
	else if (flag->conversion == 'p')
		return (ft_conv_p('p', flag));
	else if (flag->conversion == 'd')
		return (ft_conv_d('d', flag));
	else if (flag->conversion == 'i')
		return (ft_conv_i('i', flag));
	else if (flag->conversion == 'u')
		return (ft_conv_u('u', flag));
	else if (flag->conversion == 'x')
		return (ft_conv_x_low('x', flag));
	else if (flag->conversion == 'X')
		return (ft_conv_x_upp('X', flag));
	else if (flag->conversion == '%')
		return (ft_conv_perc('%', flag));*/
	return ("0");
}
