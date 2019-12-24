/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_e.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 07:31:21 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/24 13:10:12 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include <stdio.h>

static char	*ft_place_exp(char *str, char *exp, t_flag *flag, int amount)
{
	int		size;

	size = (flag->width > amount) ? flag->width : amount;
	if (flag->padding == 1)
		ft_memcpy(str + (amount - 4), exp, 4);
	else
		ft_memcpy(str + (size - 4), exp, 4);
	free(exp);
	return (str);
}
static char	*ft_place_mid(char *str, char *mid, t_flag *flag, int amount)
{
	int		size;
	int		mid_len;
	int		sign;

	size = (flag->width > amount) ? flag->width : amount;
	mid_len = (int)ft_strlen(mid);
	sign = (flag->leading > 0) ? 1 : 0;
	if (flag->padding == 1)
		ft_memcpy(str + 2 + sign, mid, mid_len);
	else
		ft_memcpy(str + (size - amount + 2 + sign), mid, mid_len);
	free(mid);
	return (str);
}


static char	*ft_fill_str(char *str, t_flag *flag, double arg_dbl, int amount)
{
	int					i;
	int					size;
	int					front_nb;
	char				*mid_nb;
	char				*exp_nb;

	size = (flag->width > amount) ? flag->width : amount;
	i = (arg_dbl < 0 || flag->leading != 0) ? 1 : 0;
	flag->leading = (arg_dbl < 0) ? '-' : flag->leading;
	arg_dbl *= (arg_dbl < 0) ? -1 : 1;
	front_nb = ft_exp_front_nb(arg_dbl, flag);
	mid_nb = ft_exp_mid_nb(arg_dbl, flag);
	exp_nb = ft_exp_end_nb(arg_dbl, flag);
	if (flag->padding == 1)
		str[0 + i] = front_nb + '0';
	else
		str[size - (amount - i)] = front_nb + '0';
	str = ft_place_mid(str, mid_nb, flag, amount);
	str = ft_place_exp(str, exp_nb, flag, amount);
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
		str[(0 < sign) + 1] = '.';
	else if (flag->precision != 0 || flag->hash == 1)
		str[size - (amount - (0 < sign) - 1)] = '.';
	if (ft_check_special(arg_dbl, flag) == 0)
		str = ft_fill_str(str, flag, arg_dbl, amount);
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
		if (flag->conversion == 'g')
			flag->precision = ft_erase_zeros(arg_dbl, flag);
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
