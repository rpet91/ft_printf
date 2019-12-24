/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_g.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 11:07:21 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/24 13:41:01 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

int			ft_conv_g(va_list args, t_flag *flag)
{
	va_list		arg_cpy;
	double		arg_dbl;
	int			exp_nb;

	va_copy(arg_cpy, args);
	arg_dbl = va_arg(arg_cpy, double);
	va_end(arg_cpy);
	flag->precision = (flag->precision == -1) ? 6 : flag->precision;
	flag->precision = (flag->precision == 0) ? 1 : flag->precision;
	arg_dbl *= (arg_dbl < 0) ? -1 : 1;
	exp_nb = ft_calculate_exp_nb(arg_dbl, flag);
	exp_nb *= (arg_dbl < 1) ? -1 : 1;
//	printf("precision: [%i]\n", flag->precision);
//	printf("exp_nb: [%i]\n", exp_nb);
	if (flag->precision > exp_nb && exp_nb >= -4)
	{
		flag->precision = flag->precision - exp_nb - 1;
//		printf("precision in f: [%i]\n", flag->precision);
		return (ft_conv_f(args, flag));
	}
	else
	{
		flag->precision--;
		return (ft_conv_e(args, flag));
	}
}
