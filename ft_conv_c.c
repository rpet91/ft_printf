/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:51:08 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/30 15:00:13 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#include "libftprintf.h"

static char				*ft_put_c(char *str, t_flag *flag, wchar_t c)
{
	wchar_t			*wstr;
	int				size;

	if (flag->modifier == 1)
	{
		size = (int)ft_strlen(str);
		wstr = ft_str_to_wstr(str);
		if (flag->padding == 1)
			wstr[0] = c;
		else
			wstr[size - ft_count_bytes(c)] = c;
		size += ft_count_bytes(c);
		ft_wstr_to_str(wstr, (unsigned char *)str, (size - 1));
	}
	else
	{
		if (flag->padding == 1)
			str[0] = c;
		else
			str[flag->width - 1] = c;
	}
	return (str);
}

int						ft_conv_c(va_list args, t_flag *flag)
{
	wchar_t			c;
	char			*str;
	int				size;
	char			fill;
	char			perc;

	perc = flag->conversion;
	if (flag->modifier == 1)
		c = (perc == '%') ? '%' : (wchar_t)va_arg(args, wint_t);
	else
		c = (perc == '%') ? '%' : (wchar_t)(unsigned char)va_arg(args, int);
	fill = (flag->padding == 2) ? '0' : ' ';
	flag->width = (flag->width == 0) ? 1 : flag->width;
	size = (ft_count_bytes(c) > flag->width) ? ft_count_bytes(c) : flag->width;
	size = (flag->modifier != 1) ? flag->width : size;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_filling(str, fill, size);
	str = ft_put_c(str, flag, c);
	write(1, str, size);
	free(str);
	return (size);
}
