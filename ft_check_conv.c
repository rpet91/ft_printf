/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_conv.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:17:00 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/20 14:00:36 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libftprintf.h"

static void	ft_not_a_valid_conversion(va_list args)
{
	void	*error;

	error = va_arg(args, void *);
	write(1, "Not a valid conversion", 23);
}

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
	else
		ft_not_a_valid_conversion(args);
	return (0);
}
