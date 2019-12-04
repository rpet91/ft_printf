/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_i.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:52:13 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/04 14:58:47 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

static char	*ft_fill_integer(long long arg_int, int amount)
{
	int		i;
	char	*arg_str;

	i = 0;
	arg_str = malloc(sizeof(char) * (amount + 1));
	if (arg_str == NULL)
		return (NULL);
	if (arg_int < 0)
		arg_int = -arg_int;
	while (i < amount)
	{
		arg_str[amount - (i + 1)] = arg_int % 10 + '0';
		i++;
		arg_int = arg_int / 10;
	}
	arg_str[i] = '\0';
	return (arg_str);
}

static char	*ft_cpy_str(char *str, t_flag *flag, long long arg_int, int amount)
{
	int		i;
	int		size;
	int		sign;
	char	*arg_str;

	i = 0;
	size = (flag->width > amount) ? flag->width : amount;
	arg_str = ft_fill_integer(arg_int, amount);
	sign = (arg_int < 0) ? '-' : flag->leading;
	while (i < amount - (0 < sign))
	{
		if (flag->padding == 1)
			str[i + (0 < sign)] = arg_str[i + (0 < sign)];
		else
			str[i + (0 < sign) + (size - amount)] = arg_str[i + (0 < sign)];
		i++;
	}
	free(arg_str);
	return (str);
}

static char	*ft_create_s(char *str, t_flag *flag, long long arg_int, int amount)
{
	int		size;
	int		sign;
	int		i;
	char	fill;

	i = 0;
	size = (flag->width > amount) ? flag->width : amount;
	sign = (arg_int < 0) ? '-' : flag->leading;
	fill = (flag->precision == -1 && flag->padding == 2) ? '0' : ' ';
	str = ft_filling(str, fill, size);
	if (sign != 0 && flag->padding == 0)
		str[size - amount] = sign;
	else if (sign != 0 && flag->padding != 0)
		str[i] = sign;
	str = ft_cpy_str(str, flag, arg_int, amount);
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

t_list		*ft_conv_i(va_list args, t_flag *flag)
{
	char		*str;
	t_list		*new;
	long long	arg_int;
	int			size;
	int			amount;

	if (flag->precision != -1 && flag->padding == 2)
		flag->padding = 0;
	arg_int = va_arg(args, long long);
	ft_apply_modifier(&arg_int, flag);
	amount = (arg_int < 0) ? ft_intlen(arg_int * -1) : ft_intlen(arg_int);
	amount = (amount < flag->precision) ? flag->precision : amount;
	if (arg_int == 0 && flag->precision == 0)
		amount = 0;
	if (flag->leading != 0 || arg_int < 0)
		amount++;
	size = (flag->width > amount) ? flag->width : amount;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_create_s(str, flag, arg_int, amount);
	new = ft_new_element(str, size);
	return (new);
}
