/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_f.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:06:10 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/19 09:19:10 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

static char	*ft_put_dec_nb(char *str, t_flag *flag, double arg_dbl, int amount)
{
	int							i;
	unsigned long long			dec_nb;

	dec_nb = ft_create_dec_nb(arg_dbl, flag);
	i = 0;
	while (i < flag->precision)
	{
		if (flag->padding == 1)
			str[amount - (i + 1)] = dec_nb % 10 + '0';
		else
			str[ft_strlen(str) - (i + 1)] = dec_nb % 10 + '0';
		dec_nb /= 10;
		i++;
	}
	return (str);
}

static char	*ft_cpy_str(char *str, t_flag *flag, double arg_dbl, int amount)
{
	int					i;
	int					size;
	int					front_size;
	unsigned long long	front_nb;
	char				*arg_str;

	size = (flag->width > amount) ? flag->width : amount;
	i = (arg_dbl < 0 || flag->leading != 0) ? 1 : 0;
	arg_dbl *= (arg_dbl < 0) ? -1 : 1;
	front_nb = arg_dbl;
	front_nb += (arg_dbl - (unsigned long long)arg_dbl >= 0.5) ? 1 : 0;
	str = ft_put_dec_nb(str, flag, arg_dbl, amount);
	front_size = ft_intlen(front_nb) + i + flag->decimal;
	arg_str = ft_itoa_dec(front_nb, front_size, flag->decimal);
	while (i < front_size)
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

static char	*ft_create_s(char *str, t_flag *flag, double arg_dbl, int amount)
{
	int		size;
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
		str[amount - (flag->precision + 1)] = '.';
	else if (flag->precision != 0 || flag->hash == 1)
		str[size - (flag->precision + 1)] = '.';
	if (ft_check_special(arg_dbl, flag) == 0)
		str = ft_cpy_str(str, flag, arg_dbl, amount);
	else
		str = ft_create_special(arg_dbl, str, flag);
	return (str);
}

static int	ft_calc_amount(double arg_dbl, t_flag *flag)
{
	int		amount;
	int		digits_arg;

	digits_arg = (arg_dbl < 0) ? ft_intlen(-arg_dbl) : ft_intlen(arg_dbl);
	amount = digits_arg;
	if (ft_rounding(arg_dbl, flag) == 1)
		amount += (digits_arg + 1 == ft_intlen(arg_dbl + 1)) ? 1 : 0;
	flag->decimal = (flag->decimal == 1) ? (amount - 1) / 3 : 0;
	amount += flag->decimal;
	amount += (flag->precision == 0) ? 0 : flag->precision + 1;
	amount += (flag->leading != 0 || arg_dbl < 0) ? 1 : 0;
	amount += (flag->hash == 1 && flag->precision == 0) ? 1 : 0;
	return (amount);
}

int			ft_conv_f(va_list args, t_flag *flag)
{
	char		*str;
	double		arg_dbl;
	int			size;
	int			amount;

	arg_dbl = va_arg(args, double);
	flag->precision = (flag->precision == -1) ? 6 : flag->precision;
	amount = ft_check_special(arg_dbl, flag);
	if (amount == 0)
		amount = ft_calc_amount(arg_dbl, flag);
	size = (flag->width > amount) ? flag->width : amount;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_create_s(str, flag, arg_dbl, amount);
	write(1, str, size);
	free(str);
	return (size);
}
