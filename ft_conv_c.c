/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:51:08 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/17 16:02:11 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#include "libftprintf.h"

int						ft_conv_c(va_list args, t_flag *flag)
{
	wchar_t			c;
	wchar_t			*wstr;
	char			*str;
	int				size;
	char			fill;

	c = (flag->conversion == '%') ? '%' : (wchar_t)va_arg(args, wint_t);
	fill = (flag->padding == 2) ? '0' : ' ';
	flag->width = (flag->width == 0) ? 1 : flag->width;
	size = (ft_count_bytes(c) > flag->width) ? ft_count_bytes(c) : flag->width;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_filling(str, fill, size);
	wstr = ft_str_to_wstr((char *)str);
	if (flag->padding == 1)
		wstr[0] = c;
	else
		wstr[size - ft_count_bytes(c)] = c;
	ft_wstr_to_str(wstr, (unsigned char *)str, size - ft_count_bytes(c) + 1);
	write(1, str, size);
	free(wstr);
	free(str);
	return (size);
}
