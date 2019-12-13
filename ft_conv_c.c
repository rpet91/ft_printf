/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:51:08 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/13 12:13:52 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#include "libftprintf.h"

static unsigned char	*ft_fill_str(unsigned char *result,
							t_flag *flag, wchar_t c, int size)
{
	int				i;
	int				str_size;
	wchar_t			*wstr;

	str_size = (size - ft_count_bytes(c)) + 1;
	wstr = malloc(sizeof(wchar_t) * (str_size + 1));
	if (wstr == NULL)
		return (NULL);
	i = 0;
	while (i < str_size)
	{
		if (flag->padding == 1 && i == 0)
			wstr[i] = c;
		else if (flag->padding != 1 && i == str_size - 1)
			wstr[i] = c;
		else if (flag->padding == 2 && i < str_size - 1)
			wstr[i] = '0';
		else
			wstr[i] = ' ';
		i++;
	}
	wstr[i] = '\0';
	ft_wstr_to_str(wstr, result, str_size);
	free(wstr);
	return (result);
}

int						ft_conv_c(va_list args, t_flag *flag)
{
	wchar_t			c;
	unsigned char	*str;
	int				size;

	c = (flag->conversion == '%') ? '%' : (wchar_t)va_arg(args, wint_t);
	if (flag->width == 0)
		flag->width = 1;
	size = (ft_count_bytes(c) > flag->width) ? ft_count_bytes(c) : flag->width;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str = ft_fill_str(str, flag, c, size);
	write(1, str, size);
	free(str);
	return (size);
}
