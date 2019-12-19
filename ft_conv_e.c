/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_e.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 07:31:21 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/19 17:40:11 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include <stdio.h>

static char	*ft_put_exp(char *str, t_flag *flag, double arg_dbl, int amount)
{
	int		i;
	int		size;
	char	*exp;

	size = (flag->width > amount) ? flag->width : amount;
	i = (arg_dbl < 0 || flag->leading != 0) ? 1 : 0;
	arg_dbl *= (arg_dbl < 0) ? -1 : 1;
	exp = ft_create_exponent(arg_dbl);
//	printf("str voor: [%s]\n", str);
//	printf("i: [%i]\n", i);
//	printf("amount: [%i]\n", amount);
//	printf("size: [%i]\n", size);
	if (flag->padding == 1)
		ft_memcpy(str + i + (amount - 4), exp, 4);
	else
		ft_memcpy(str + (size - 4), exp, 4);
	free(exp);
//	printf("str na: [%s]\n", str);
	return (str);
}

static char	*ft_cpy_str(char *str, t_flag *flag, double arg_dbl, int amount)
{
	int					size;
	unsigned long long	nb;

	size = (flag->width > amount) ? flag->width : amount;
	nb = (arg_dbl < 0) ? -arg_dbl : arg_dbl;
	str = ft_put_exp(str, flag, arg_dbl, amount);
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
/*	if (flag->padding == 1 && (flag->precision != 0 || flag->hash == 1))
		str[amount - (flag->precision + 1)] = '.';
	else if (flag->precision != 0 || flag->hash == 1)
		str[size - (flag->precision + 1)] = '.';*/
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
		amount = (arg_dbl < 0) ? ft_intlen(-arg_dbl) : ft_intlen(arg_dbl);
//		printf("a1: [%i]\n", amount);
		amount += (flag->precision == 0) ? 0 : flag->precision + 1;
//		printf("a2: [%i]\n", amount);
		amount += (flag->leading != 0 || arg_dbl < 0) ? 1 : 0;
//		printf("a3: [%i]\n", amount);
		amount += (flag->hash == 1 && flag->precision == 0) ? 1 : 0;
//		printf("a4: [%i]\n", amount);
		amount += 4;
//		printf("a5: [%i]\n", amount);
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
