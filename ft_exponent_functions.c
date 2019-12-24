/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exponent_functions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 08:22:39 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/23 11:37:06 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

int			ft_exp_front_nb(double arg_dbl, t_flag *flag)
{
	int		front_nb;

	if (arg_dbl == 0)
		return (0);
	while (arg_dbl >= 10 || arg_dbl < 1)
		arg_dbl = (arg_dbl < 1) ? arg_dbl * 10 : arg_dbl / 10;
	front_nb = (int)arg_dbl + ft_rounding(arg_dbl, flag);
	while (front_nb > 9)
		front_nb /= 10;
	return (front_nb);
}

char		*ft_exp_mid_nb(double arg_dbl, t_flag *flag)
{
	char				*arg_str;
	unsigned long long	mid_nb;
	int					temp_precision;

	while ((arg_dbl >= 10 || arg_dbl < 1) && arg_dbl != 0)
		arg_dbl = (arg_dbl < 1) ? arg_dbl * 10 : arg_dbl / 10;
	mid_nb = (unsigned long long)arg_dbl + ft_rounding(arg_dbl, flag);
	arg_dbl -= mid_nb;
	temp_precision = flag->precision;
	while (0 < flag->precision)
	{
		arg_dbl *= 10;
		flag->precision--;
	}
	mid_nb = (unsigned long long)arg_dbl + ft_rounding(arg_dbl, flag);
	flag->precision = temp_precision;
	arg_str = ft_itoa_dec(mid_nb, flag->precision, 0);
	return (arg_str);
}

int			ft_calculate_exp_nb(double arg_dbl, t_flag *flag)
{
	unsigned long long	temp;
	int					result;

	temp = (unsigned long long)arg_dbl + ft_rounding(arg_dbl, flag);
	result = 0;
	if (temp >= 10)
	{
		while (temp >= 10)
		{
			temp /= 10;
			result++;
		}
	}
	else if (arg_dbl < 1 && arg_dbl != 0)
	{
		while (arg_dbl < 1)
		{
			arg_dbl *= 10;
			result++;
		}
	}
	return (result);
}

char		*ft_exp_end_nb(double arg_dbl, t_flag *flag)
{
	char	*exp_str;
	char	sign;
	int		dec_nb_r;
	int		dec_nb_l;

	dec_nb_r = 0;
	sign = (arg_dbl >= 1 || arg_dbl == 0) ? '+' : '-';
	dec_nb_r = ft_calculate_exp_nb(arg_dbl, flag);
	exp_str = ft_strdup("e+00");
	exp_str[1] = sign;
	dec_nb_l = dec_nb_r / 10;
	exp_str[2] = (char)dec_nb_l + '0';
	exp_str[3] = (char)(dec_nb_r - (dec_nb_l * 10)) + '0';
	return (exp_str);
}
