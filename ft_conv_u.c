/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_u.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:52:40 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/04 14:59:30 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include <stdio.h>

static char	*ft_fill_unsigned(unsigned long long arg_int, int amount)
{
	int		i;
	char	*arg_str;

	i = 0;
	arg_str = malloc(sizeof(char) * (amount + 1));
	if (arg_str == NULL)
		return (NULL);
	while (i < amount)
	{
		arg_str[amount - (i + 1)] = arg_int % 10 + '0';
		i++;
		arg_int = arg_int / 10;
	}
	arg_str[i] = '\0';
	return (arg_str);
}

static char	*ft_create_s(char *str, t_flag *flag,
										unsigned long long arg_int, int amount)
{
	int		size;
	int		i;
	char	fill;
	char	*arg_str;

	size = (flag->width > amount) ? flag->width : amount;
	fill = (flag->precision == -1 && flag->padding == 2) ? '0' : ' ';
	str = ft_filling(str, fill, size);
	arg_str = ft_fill_unsigned(arg_int, amount);
	i = 0;
	while (i < amount)
	{
		if (flag->padding == 1)
			str[i] = arg_str[i];
		else
			str[i + (size - amount)] = arg_str[i];
		i++;
	}
	free(arg_str);
	return (str);
}

static int	ft_ull_len(unsigned long long arg_int)
{
	int		i;

	i = 0;
	if (arg_int == 0)
		return (1);
	while (arg_int != 0)
	{
		arg_int = arg_int / 10;
		i++;
	}
	return (i);
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

t_list		*ft_conv_u(va_list args, t_flag *flag)
{
	char				*str;
	t_list				*new;
	unsigned long long	arg_int;
	int					size;
	int					amount;

	arg_int = va_arg(args, unsigned long long);
	if (flag->precision != -1 && flag->padding == 2)
		flag->padding = 0;
	ft_apply_modifier(&arg_int, flag);
	amount = ft_ull_len(arg_int);
	amount = (amount < flag->precision) ? flag->precision : amount;
	if (arg_int == 0 && flag->precision == 0)
		amount = 0;
	size = (flag->width > amount) ? flag->width : amount;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_create_s(str, flag, arg_int, amount);
	new = ft_new_element(str, size);
	return (new);
}
