/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exponent_functions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 08:22:39 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/31 13:05:41 by rpet          ########   odam.nl         */
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
	int					result;
	unsigned long long	temp;

	arg_dbl *= (arg_dbl < 0) ? -1 : 1;
	temp = (unsigned long long)arg_dbl + ft_rounding(arg_dbl, flag);
	result = (temp > arg_dbl) ? 1 : 0;
	if (arg_dbl >= 10)
	{
		while (arg_dbl >= 10)
		{
			arg_dbl /= 10;
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
	char	*exp_nb_str;
	char	sign;
	int		exp_nb;
	int		size;

	exp_nb = 0;
	sign = (arg_dbl >= 1 || arg_dbl == 0) ? '+' : '-';
	exp_nb = ft_calculate_exp_nb(arg_dbl, flag);
	size = (exp_nb < 10) ? ft_countdigits(exp_nb) + 1 : ft_countdigits(exp_nb);
	exp_str = malloc(sizeof(char) * (size + 3));
	if (exp_str == NULL)
		return (NULL);
	exp_str[0] = 'e';
	exp_str[1] = sign;
	exp_str[size + 2] = '\0';
	exp_nb_str = ft_itoa_dec(exp_nb, size, 0);
	if (exp_nb_str == NULL)
		return (NULL);
	ft_memcpy(exp_str + 2, exp_nb_str, size + 2);
	free(exp_nb_str);
	return (exp_str);
}
