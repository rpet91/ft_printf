/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:51:19 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/19 15:11:08 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#include "libftprintf.h"

static unsigned char	*ft_create_str(unsigned char *str, wchar_t *arg_str,
							t_flag *flag, int amount)
{
	int			i;
	int			size;
	int			byte_i;
	char		fill;
	wchar_t		*wstr;

	size = (amount < flag->width) ? flag->width : amount;
	fill = (flag->padding == 2) ? '0' : ' ';
	wstr = malloc(sizeof(wchar_t) * (size + 1));
	if (wstr == NULL)
		return (NULL);
	wstr = ft_wfilling(wstr, fill, size);
	i = 0;
	byte_i = 0;
	while (byte_i < amount)
	{
		if (flag->padding == 1)
			wstr[i] = arg_str[i];
		else
			wstr[i + (size - amount)] = arg_str[i];
		byte_i += ft_count_bytes(wstr[i]);
		i++;
	}
	ft_wstr_to_str(wstr, str, size);
	free(wstr);
	return (str);
}

static int				ft_count_bytes_string(wchar_t *arg_str, t_flag *flag)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (arg_str[i] != '\0')
	{
		//printf("size: [%i]\n", size);
		size += ft_count_bytes(arg_str[i]);
		if (size > flag->precision && flag->precision != -1)
		{
			size -= ft_count_bytes(arg_str[i]);
			break ;
		}
		i++;
	}
	return (size);
}

static wchar_t			*ft_check_modifier(va_list args, t_flag *flag)
{
	char		*convert_str;
	wchar_t		*arg_wstr;

	if (flag->modifier == 1)
	{
		arg_wstr = va_arg(args, wchar_t *);
		if (arg_wstr == NULL)
			arg_wstr = ft_str_to_wstr("(null)");
		else
			arg_wstr = ft_wstrdup(arg_wstr);
	}
	else
	{
		convert_str = va_arg(args, char *);
		if (convert_str == NULL)
			arg_wstr = ft_str_to_wstr("(null)");
		else
			arg_wstr = ft_str_to_wstr(convert_str);
	}
	return (arg_wstr);
}

int						ft_conv_s(va_list args, t_flag *flag)
{
	unsigned char	*str;
	wchar_t			*arg_str;
	int				size;
	int				amount;

	arg_str = ft_check_modifier(args, flag);
	amount = ft_count_bytes_string(arg_str, flag);
	//printf("amount: [%i]\n", amount);
	flag->precision = (flag->precision == -1) ? amount : flag->precision;
	amount = (amount < flag->precision) ? amount : flag->precision;
	size = (amount < flag->width) ? flag->width : amount;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_create_str(str, arg_str, flag, amount);
	write(1, str, size);
	free(arg_str);
	free(str);
	return (size);
}
