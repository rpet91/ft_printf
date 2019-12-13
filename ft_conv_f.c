/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_f.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:06:10 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/13 11:23:46 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>

static int	ft_put_dec_nb(char *str, t_flag *flag, double arg_dbl, int amount)
{
	int							i;
	int							rounding;
	unsigned long long			dec_nb;
	char						*arg_dec;

	arg_dec = malloc(sizeof(char) * (flag->precision + 1));
	if (arg_dec == NULL)
		return (0);
	arg_dbl *= (arg_dbl < 0) ? -1 : 1;
	dec_nb = ft_create_dec_nb(arg_dbl, flag);
	rounding = ft_intlen(dec_nb);
	i = 0;
	while (i < flag->precision)
	{
		if (flag->padding == 1)
			str[amount - (i + 1)] = dec_nb % 10 + '0';
		else
			str[ft_strlen(str) - (i + 1)] = dec_nb % 10 + '0';
		dec_nb = dec_nb / 10;
		i++;
	}
	rounding = (flag->precision == 0 || (flag->precision < rounding)) ? 1 : 0;
	rounding *= (arg_dbl - (unsigned long long)arg_dbl >= 0.5) ? 1 : 0;
	return (rounding);
}

static char	*ft_put_front_nb(unsigned long long front_nb, t_flag *flag, int sign)
{
	int		i;
	int		size;
	char	*arg_str;

	i = 0;
	size = ft_intlen(front_nb) + sign;
	arg_str = malloc(sizeof(char) * (size + 1));
	if (arg_str == NULL)
		return (NULL);
	while (i < size)
	{
		if (flag->decimal > 0 && i % 4 == 3)
		{
			arg_str[size - (i + 1)] = ',';
			flag->decimal--;
		}
		else
		{
			arg_str[size - (i + 1)] = front_nb % 10 + '0';
			front_nb = front_nb / 10;
		}
		i++;
	}
	arg_str[i] = '\0';
	return (arg_str);
}

static char	*ft_cpy_str(char *str, t_flag *flag, double arg_dbl, int amount)
{
	int					i;
	int					size;
	int					sign;
	unsigned long long	front_nb;
	char				*arg_str;

	size = (flag->width > amount) ? flag->width : amount;
	sign = (arg_dbl < 0 || flag->leading != 0) ? 1 : 0;
	front_nb = (arg_dbl < 0) ? -arg_dbl : arg_dbl;
	front_nb += ft_put_dec_nb(str, flag, arg_dbl, amount);
	arg_str = ft_put_front_nb(front_nb, flag, sign);
	i = sign;
	while (i < ft_intlen(front_nb) + sign)
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
	str = ft_cpy_str(str, flag, arg_dbl, amount);
	return (str);
}

t_list		*ft_conv_f(va_list args, t_flag *flag)
{
	char		*str;
	t_list		*new;
	double		arg_dbl;
	int			size;
	int			amount;

	arg_dbl = va_arg(args, double);
	flag->precision = (flag->precision == -1) ? 6 : flag->precision;
	amount = (int)arg_dbl;
	amount = (arg_dbl < 0) ? ft_intlen(-amount) : ft_intlen(amount);
	amount += (flag->decimal == 1) ? (amount - 1) / 3 : 0;
	amount += (flag->precision == 0) ? 0 : flag->precision + 1;
	amount += (flag->leading != 0 || arg_dbl < 0) ? 1 : 0;
	amount += (flag->hash == 1 && flag->precision == 0) ? 1 : 0;
	size = (flag->width > amount) ? flag->width : amount;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_create_s(str, flag, arg_dbl, amount);
	new = ft_new_element(str, size);
	flag->print_len += size;
	return (new);
}
