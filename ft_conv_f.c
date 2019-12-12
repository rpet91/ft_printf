/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_f.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:06:10 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/12 15:22:54 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>

static int	ft_place_decimal(char *str, t_flag *flag, double arg_double, int amount)
{
	int							i;
	unsigned long long			dec_int;
	char						*arg_dec;
	int							temp;
	int							rounding;

	arg_dec = malloc(sizeof(char) * (flag->precision + 1));
	if (arg_dec == NULL)
		return (0);
	i = 0;
	dec_int = 1;
	while (i < flag->precision + 1)
	{
		dec_int = dec_int * 10;
		i++;
	}
	arg_double *= (arg_double < 0) ? -1 : 1;
	dec_int = ((arg_double - (unsigned long long)arg_double) * dec_int);
	temp = dec_int - (dec_int / 10) * 10;
	dec_int = (temp < 5) ? dec_int / 10 : (dec_int / 10) + 1;
	rounding = (5 <= temp && flag->precision < ft_intlen(dec_int)) ? 1 : 0;
	i = 0;
	while (i < flag->precision)
	{
		if (flag->padding == 1)
			str[amount - (i + 1)] = dec_int % 10 + '0';
		else
			str[ft_strlen(str) - (i + 1)] = dec_int % 10 + '0';
		dec_int = dec_int / 10;
		i++;
	}
	return (rounding);
}

static char	*ft_place_integer(int front, t_flag *flag, int sign)
{
	int		i;
	int		size;
	char	*arg_str;

	i = 0;
	size = ft_intlen(front) + sign;
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
			arg_str[size - (i + 1)] = front % 10 + '0';
			front = front / 10;
		}
		i++;
	}
	arg_str[i] = '\0';
	return (arg_str);
}

static char	*ft_cpy_str(char *str, t_flag *flag, double arg_double, int amount)
{
	int		i;
	int		size;
	int		sign;
	int		front;
	char	*arg_str;

	size = (flag->width > amount) ? flag->width : amount;
	front = (arg_double < 0) ? -(int)arg_double : (int)arg_double;
//	printf("flag->leading: [%i]\n", flag->leading);
	sign = (arg_double < 0 || flag->leading != 0) ? 1 : 0;
	front += ft_place_decimal(str, flag, arg_double, amount);
//	printf("str na decimal: [%s]\n", str);
	arg_str = ft_place_integer(front, flag, sign);
	i = sign;
//	printf("sign: [%i]\n", sign);
	while (i < ft_intlen(front) + sign)
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

static char	*ft_create_s(char *str, t_flag *flag, double arg_double, int amount)
{
	int		size;
	int		sign;
	char	fill;

	size = (flag->width > amount) ? flag->width : amount;
	sign = (arg_double < 0) ? '-' : flag->leading;
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
//	printf("str voor alle shit: [%s]\n", str);
	str = ft_cpy_str(str, flag, arg_double, amount);
	return (str);
}

t_list		*ft_conv_f(va_list args, t_flag *flag)
{
	char		*str;
	t_list		*new;
	double		arg_double;
	int			size;
	int			amount;

	arg_double = va_arg(args, double);
//	printf("arg_double: [%f]\n", arg_double);
	flag->precision = (flag->precision == -1) ? 6 : flag->precision;
//	printf("precision: [%i]\n", flag->precision);
	amount = (int)arg_double;
	amount = (arg_double < 0) ? ft_intlen(-amount) : ft_intlen(amount);
//	printf("amount len : [%i]\n", amount);
	amount += (flag->decimal == 1) ? (amount - 1) / 3 : 0;
//	printf("amount dec : [%i]\n", amount);
	amount += (flag->precision == 0) ? 0 : flag->precision + 1;
//	printf("amount pre : [%i]\n", amount);
	amount += (flag->leading != 0 || arg_double < 0) ? 1 : 0;
//	printf("amount sign: [%i]\n", amount);
	amount += (flag->hash == 1 && flag->precision == 0) ? 1 : 0;
//	printf("amount hash: [%i]\n", amount);
	size = (flag->width > amount) ? flag->width : amount;
//	printf("size malloc: [%i]\n", size);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_create_s(str, flag, arg_double, amount);
	new = ft_new_element(str, size);
	flag->print_len += size;
	return (new);
}
