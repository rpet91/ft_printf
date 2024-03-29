/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 09:45:38 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/31 13:16:21 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

static int	ft_invalid_conversion(va_list args, t_flag *flag, int print_len)
{
	free(flag);
	va_end(args);
	return (print_len);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_flag		*flag;
	char		*format_string;
	int			print_len;

	format_string = (char *)format;
	print_len = 0;
	va_start(args, format);
	while (*format_string)
	{
		flag = ft_empty_flag();
		if (*format_string == '%')
		{
			ft_check_flag(args, format_string, flag);
			print_len += ft_check_conv(args, flag, print_len);
			if (flag->conversion == -1)
				return (ft_invalid_conversion(args, flag, print_len));
		}
		else
			print_len += ft_create_string(format_string, flag);
		format_string += flag->flag_len;
		free(flag);
	}
	va_end(args);
	return (print_len);
}
