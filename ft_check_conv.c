/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_conv.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:17:00 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/24 08:05:12 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libftprintf.h"

int			ft_check_conv(va_list args, t_flag *flag, int print_len)
{
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
	else if (flag->conversion == 'f')
		return (ft_conv_f(args, flag));
	else if (flag->conversion == 'e')
		return (ft_conv_e(args, flag));
	else if (flag->conversion == 'g')
		return (ft_conv_g(args, flag));
	else
		flag->conversion = -1;
	return (0);
}
