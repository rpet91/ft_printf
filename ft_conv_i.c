/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_i.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:52:13 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/17 16:06:46 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

static char	*ft_create_s(char *str, t_flag *flag, long long arg_int, int amount)
{
	int		size;
	int		sign;
	char	fill;
	char	*arg_str;

	size = (flag->width > amount) ? flag->width : amount;
	sign = (arg_int < 0) ? '-' : flag->leading;
	fill = (flag->precision == -1 && flag->padding == 2) ? '0' : ' ';
	str = ft_filling(str, fill, size);
	if (sign != 0 && flag->padding == 0)
		str[size - amount] = sign;
	else if (sign != 0 && flag->padding != 0)
		str[0] = sign;
	sign = (arg_int < 0 || flag->leading != 0) ? 1 : 0;
	arg_int *= (arg_int < 0) ? -1 : 1;
	arg_str = ft_itoa_dec(arg_int, amount, flag->decimal);
	str = ft_strmerge(str, arg_str, flag->padding, sign);
	free(arg_str);
	return (str);
}

static void	ft_apply_modifier(long long *arg_int, t_flag *flag)
{
	if (flag->modifier == 0)
		*arg_int = (long long)(int)*arg_int;
	if (flag->modifier == 1)
		*arg_int = (long long)(long)*arg_int;
	if (flag->modifier == 3)
		*arg_int = (long long)(short)*arg_int;
	if (flag->modifier == 4)
		*arg_int = (long long)(signed char)*arg_int;
}

int			ft_conv_i(va_list args, t_flag *flag)
{
	char		*str;
	long long	arg_int;
	int			size;
	int			amount;

	if (flag->precision != -1 && flag->padding == 2)
		flag->padding = 0;
	arg_int = va_arg(args, long long);
	ft_apply_modifier(&arg_int, flag);
	amount = (arg_int < 0) ? ft_intlen(-arg_int) : ft_intlen(arg_int);
	flag->decimal = (flag->decimal == 1) ? (amount - 1) / 3 : 0;
	amount += flag->decimal;
	amount = (amount < flag->precision) ? flag->precision : amount;
	amount = (arg_int == 0 && flag->precision == 0) ? 0 : amount;
	amount = (flag->leading != 0 || arg_int < 0) ? amount + 1 : amount;
	size = (flag->width > amount) ? flag->width : amount;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_create_s(str, flag, arg_int, amount);
	write(1, str, size);
	free(str);
	return (size);
}
