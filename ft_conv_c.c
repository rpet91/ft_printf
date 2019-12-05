/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:51:08 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/05 09:30:12 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

static char		*ft_fill_string(char *str, t_flag *flag, char c)
{
	int		i;

	i = 0;
	while (i < flag->width)
	{
		if (flag->padding == 1 && i == 0)
			str[i] = c;
		else if (flag->padding != 1 && i == flag->width - 1)
			str[i] = c;
		else if (flag->padding == 2 && i < flag->width - 1)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_list			*ft_conv_c(va_list args, t_flag *flag)
{
	char		*str;
	char		c;
	t_list		*new;

	if (flag->width == 0)
		flag->width = 1;
	str = malloc(sizeof(char) * (flag->width + 1));
	if (str == NULL)
		return (0);
	c = (flag->conversion == '%') ? '%' : (char)va_arg(args, int);
	str = ft_fill_string(str, flag, c);
	new = ft_new_element(str, flag->width);
	flag->print_len += flag->width;
	return (new);
}
