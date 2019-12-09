/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_conv.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:17:00 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/09 16:23:21 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include <stdio.h>

t_list		*ft_check_conv(va_list args, t_flag *flag, int print_len)
{
	//printf("conv char hier: [%c]\n", flag->conversion);
	if (flag->conversion == 'c' || flag->conversion == '%')
		return (ft_conv_c(args, flag));
	else if (flag->conversion == 's')
		return (ft_conv_s(args, flag));
	else if (flag->conversion == 'p')
		return (ft_conv_p(args, flag));
	else if (flag->conversion == 'd' || flag->conversion == 'i')
		return (ft_conv_i(args, flag));
	else if (flag->conversion == 'u')
		return (ft_conv_u(args, flag));
	else if (flag->conversion == 'x' || flag->conversion == 'X')
		return (ft_conv_x(args, flag));
	else if (flag->conversion == 'n')
		ft_conv_n(args, flag, print_len);
	return (NULL);
}
