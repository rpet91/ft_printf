/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_u.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:52:40 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/17 09:53:30 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

static char	*ft_create_s(char *str, t_flag *flag,
										unsigned long long arg_int, int amount)
{
	int		size;
	char	fill;
	char	*arg_str;

	size = (flag->width > amount) ? flag->width : amount;
	fill = (flag->precision == -1 && flag->padding == 2) ? '0' : ' ';
	str = ft_filling(str, fill, size);
	arg_str = ft_itoa_dec(arg_int, amount, flag->decimal);
	str = ft_strmerge(str, arg_str, flag->padding, 0);
	free(arg_str);
	return (str);
}

static int	ft_ull_len(unsigned long long arg_int)
{
	int		len;

	len = 0;
	if (arg_int == 0)
		return (1);
	while (arg_int != 0)
	{
		arg_int = arg_int / 10;
		len++;
	}
	return (len);
}

static void	ft_apply_modifier(unsigned long long *arg_int, t_flag *flag)
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

int			ft_conv_u(va_list args, t_flag *flag)
{
	char				*str;
	unsigned long long	arg_int;
	int					size;
	int					amount;

	arg_int = va_arg(args, unsigned long long);
	if (flag->precision != -1 && flag->padding == 2)
		flag->padding = 0;
	ft_apply_modifier(&arg_int, flag);
	amount = ft_ull_len(arg_int);
	flag->decimal = (flag->decimal == 1) ? (amount - 1) / 3 : 0;
	amount += flag->decimal;
	amount = (amount < flag->precision) ? flag->precision : amount;
	amount = (arg_int == 0 && flag->precision == 0) ? 0 : amount;
	size = (flag->width > amount) ? flag->width : amount;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_create_s(str, flag, arg_int, amount);
	write(1, str, size);
	free(str);
	return (size);
}
