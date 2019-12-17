/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_x.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:54:44 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/17 11:25:50 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

static char		*ft_fill_unsigned(unsigned long long arg_int, t_flag *flag,
					int amount)
{
	unsigned long long	temp;
	char				*arg_str;
	int					upp;

	arg_str = malloc(sizeof(char) * (amount + 1));
	if (arg_str == NULL)
		return (NULL);
	arg_str[amount] = '\0';
	upp = (flag->conversion == 'X') ? 32 : 0;
	temp = arg_int;
	while (0 < amount)
	{
		amount--;
		temp = arg_int % 16;
		arg_str[amount] = (temp < 10) ? '0' + temp : 'a' + temp - 10 - upp;
		arg_int = arg_int / 16;
	}
	return (arg_str);
}

static char		*ft_create_s(char *str, t_flag *flag,
					unsigned long long arg_int, int amount)
{
	int		size;
	int		i;
	char	fill;
	char	*arg_str;

	size = (flag->width > amount) ? flag->width : amount;
	fill = (flag->precision == -1 && flag->padding == 2) ? '0' : ' ';
	str = ft_filling(str, fill, size);
	arg_str = ft_fill_unsigned(arg_int, flag, amount);
	i = 0;
	if (flag->hash == 1 && arg_int != 0)
		arg_str[1] = flag->conversion;
	str = ft_strmerge(str, arg_str, flag->padding, 0);
	free(arg_str);
	return (str);
}

static int		ft_hexlen(unsigned long long arg_int)
{
	int		i;

	if (arg_int == 0)
		return (1);
	i = 0;
	while (arg_int != 0)
	{
		arg_int = arg_int / 16;
		i++;
	}
	return (i);
}

static void		ft_apply_modifier(unsigned long long *arg_int, t_flag *flag)
{
	if (flag->modifier == 0)
		*arg_int = (unsigned long long)(unsigned int)*arg_int;
	if (flag->modifier == 1)
		*arg_int = (unsigned long long)(unsigned long)*arg_int;
	if (flag->modifier == 3)
		*arg_int = (unsigned long long)(unsigned short)*arg_int;
	if (flag->modifier == 4)
		*arg_int = (unsigned long long)(unsigned char)*arg_int;
}

int				ft_conv_x(va_list args, t_flag *flag)
{
	char				*str;
	unsigned long long	arg_int;
	int					size;
	int					amount;

	arg_int = va_arg(args, unsigned long long);
	if (flag->precision != -1 && flag->padding == 2)
		flag->padding = 0;
	ft_apply_modifier(&arg_int, flag);
	amount = ft_hexlen(arg_int);
	amount = (amount < flag->precision) ? flag->precision : amount;
	amount = (arg_int == 0 && flag->precision == 0) ? 0 : amount;
	size = (flag->width > amount) ? flag->width : amount;
	if (flag->hash == 1 && arg_int > 0)
		amount = (flag->hash == 1) ? amount + 2 : amount;
	size = (amount - size < 0) ? size : size + (amount - size);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	amount = (flag->padding == 2) ? size : amount;
	str = ft_create_s(str, flag, arg_int, amount);
	write(1, str, size);
	free(str);
	return (size);
}
