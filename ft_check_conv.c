/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_conv.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:17:00 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/25 16:54:45 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

t_list		*ft_check_conv(va_list args, t_flag *flag)
{
	if (flag->conversion == 'c')
		return (ft_conv_c(args, flag));
	if (flag->conversion == 's')
		return (ft_conv_s(args, flag));
//	if (flag->conversion == 'p')
//		return (ft_conv_p(args, flag));
	if (flag->conversion == 'd' || flag->conversion == 'i')
		return (ft_conv_di(args, flag));
//	if (flag->conversion == 'u')
//		return (ft_conv_u(args, flag));
//	if (flag->conversion == 'x')
//		return (ft_conv_x_low(args, flag));
//	if (flag->conversion == 'X')
//		return (ft_conv_x_upp(args, flag));
	return (0);
}
