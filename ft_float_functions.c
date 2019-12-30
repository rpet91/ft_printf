/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 07:58:31 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/30 14:36:22 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

unsigned long long	ft_create_dec_nb(double arg_dbl, t_flag *flag)
{
	int					temp;
	unsigned long long	dec_nb;

	dec_nb = 1;
	temp = 0;
	while (temp < flag->precision + 1)
	{
		dec_nb *= 10;
		temp++;
	}
	dec_nb = ((arg_dbl - (unsigned long long)arg_dbl) * dec_nb);
	temp = dec_nb - (dec_nb / 10) * 10;
	dec_nb = (temp < 5) ? dec_nb / 10 : (dec_nb / 10) + 1;
	return (dec_nb);
}

int					ft_check_special(double arg_dbl, t_flag *flag)
{
	unsigned long long	temp;
	int					amount;

	temp = *(unsigned long long *)&arg_dbl;
	amount = 0;
	if (temp == 0x7FF0000000000000)
		amount = 3 + (flag->leading > 0);
	if (temp == 0xFFF0000000000000)
		amount = 4;
	if (temp >= 0x7FF0000000000001 && temp <= 0x7FFFFFFFFFFFFFFF)
	{
		flag->leading = 0;
		amount = 3;
	}
	if (temp == 0x8000000000000000)
		flag->leading = '-';
	if (amount != 0 && flag->padding == 2)
		flag->padding = 0;
	flag->precision = (amount != 0) ? 0 : flag->precision;
	return (amount);
}

char				*ft_create_special(double arg_dbl, char *str, t_flag *flag)
{
	unsigned long long	temp;
	char				*arg_str;
	int					i;
	int					sign;

	temp = *(unsigned long long *)&arg_dbl;
	if (temp == 0x7FF0000000000000 || temp == 0xFFF0000000000000)
		arg_str = ft_strdup("inf");
	else
		arg_str = ft_strdup("nan");
	i = 0;
	sign = (flag->leading != 0 || temp == 0xFFF0000000000000) ? 1 : 0;
	while (i < 3)
	{
		if (flag->padding == 1)
			str[i + sign] = arg_str[i];
		else
			str[i + ft_strlen(str) - 3] = arg_str[i];
		i++;
	}
	free(arg_str);
	return (str);
}

int					ft_rounding(double arg_dbl, t_flag *flag)
{
	int					rounding;
	unsigned long long	dec_nb;

	arg_dbl *= (arg_dbl < 0) ? -1 : 1;
	if (flag->precision == 0 && (arg_dbl - (unsigned long long)(arg_dbl) == 0.5
				&& (unsigned long long)arg_dbl % 2 == 1))
		return (1);
	dec_nb = ft_create_dec_nb(arg_dbl, flag);
	rounding = ft_countdigits(dec_nb);
	rounding = (flag->precision == 0 || (flag->precision < rounding)) ? 1 : 0;
	rounding *= ((arg_dbl) - (unsigned long long)(arg_dbl) > 0.5) ? 1 : 0;
	return (rounding);
}
