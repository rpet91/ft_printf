/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_e.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 07:31:21 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/20 13:47:26 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include <stdio.h>

static char	*ft_create_mid_nb(t_flag *flag, double arg_dbl)
{
	int					temp_precision;
	unsigned long long	temp;
	unsigned long long	result;
	char				*arg_str;

	temp_precision = flag->precision;
	temp = 1;
	while (arg_dbl > 9 || (arg_dbl < 1 && arg_dbl != 0))
		arg_dbl = (arg_dbl > 9) ? arg_dbl / 10 : arg_dbl * 10;
	while (flag->precision > 0)
	{
		temp *= 10;
		arg_dbl *= 10;
		flag->precision--;
	}
//	printf("arg_dbl: [%f]\n", arg_dbl);
//	printf("temp   : [%llu]\n", temp); 
//	printf("precision: [%i]\n", flag->precision);
	result = ((unsigned long long)arg_dbl - temp) + ft_rounding(arg_dbl, flag);
	flag->precision = temp_precision;
//	printf("result: [%llu]\n", result);
	arg_str = ft_itoa_dec(result, ft_countdigits(result), 0);
	return (arg_str);
}


static char	*ft_put_exp(char *str, t_flag *flag, double arg_dbl, int amount)
{
	int		i;
	int		size;
	int		front_nb;
	char	*exp;

	size = (flag->width > amount) ? flag->width : amount;
	i = (arg_dbl < 0 || flag->leading != 0) ? 1 : 0;
	arg_dbl *= (arg_dbl < 0) ? -1 : 1;
	exp = ft_create_exponent(arg_dbl);
	if (flag->padding == 1)
		ft_memcpy(str + (amount - 4), exp, 4);
	else
		ft_memcpy(str + (size - 4), exp, 4);
	free(exp);
	while (arg_dbl > 9 || (arg_dbl < 1 && arg_dbl != 0))
		arg_dbl = (arg_dbl > 9) ? arg_dbl / 10 : arg_dbl * 10;
	front_nb = (int)arg_dbl;
	front_nb += ft_rounding(arg_dbl, flag);
	if (flag->padding == 1)
		str[0 + i] = front_nb + '0';
	else
		str[size - (amount - i)] = front_nb + '0';
	return (str);
}

static char	*ft_cpy_str(char *str, t_flag *flag, double arg_dbl, int amount)
{
	int			i;
	int			size;
	char		*arg_str;
	size_t		arg_len;

	size = (flag->width > amount) ? flag->width : amount;
	i = (arg_dbl < 0 || flag->leading != 0) ? 1 : 0;
	str = ft_put_exp(str, flag, arg_dbl, amount);
	arg_dbl *= (arg_dbl < 0) ? -1 : 1;
	if (flag->precision != 0)
		arg_str = ft_create_mid_nb(flag, arg_dbl);
	arg_len = (flag->precision != 0) ? ft_strlen(arg_str) : 0;
	if (flag->padding == 1)
		ft_memcpy(str + i + 2, arg_str, ft_strlen(arg_str));
	else
		ft_memcpy(str + (size - (int)arg_len - 4), arg_str, arg_len);
	return (str);
}

static char	*ft_create_s(char *str, t_flag *flag, double arg_dbl, int amount)
{
	int 	size;
	int		sign;
	char	fill;

	size = (flag->width > amount) ? flag->width : amount;
	sign = (arg_dbl < 0) ? '-' : flag->leading;
	fill = (flag->padding == 2) ? '0' : ' ';
	str = ft_filling(str, fill, size);
	if (sign != 0 && flag->padding == 0)
		str[size - amount] = sign;
	else if (sign != 0 && flag->padding != 0)
		str[0] = sign;
	if (flag->padding == 1 && (flag->precision != 0 || flag->hash == 1))
		str[(0 < sign) + 2] = '.';
	else if (flag->precision != 0 || flag->hash == 1)
		str[size - (amount - (0 < sign) - 1)] = '.';
	if (ft_check_special(arg_dbl, flag) == 0)
		str = ft_cpy_str(str, flag, arg_dbl, amount);
	else
		str = ft_create_special(arg_dbl, str, flag);
	return (str);
}

int			ft_conv_e(va_list args, t_flag *flag)
{
	char	*str;
	double	arg_dbl;
	int		size;
	int		amount;

	arg_dbl = va_arg(args, double);
	flag->precision = (flag->precision == -1) ? 6 : flag->precision;
	amount = ft_check_special(arg_dbl, flag);
	if (amount == 0)
	{
		amount += (flag->precision == 0) ? 0 : flag->precision + 1;
		amount += (flag->leading != 0 || arg_dbl < 0) ? 1 : 0;
		amount += (flag->hash == 1 && flag->precision == 0) ? 1 : 0;
		amount += 5;
	}
	size = (flag->width > amount) ? flag->width : amount;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_create_s(str, flag, arg_dbl, amount);
	write(1, str, size);
	free(str);
	return (size);
}
