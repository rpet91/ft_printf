/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 09:45:38 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/20 16:31:55 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libftprintf.h"
#include <stdlib.h>

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_flag		*new;
	char		*form_str;
	//char		*conv_str;

	form_str = malloc(sizeof(char*));
	if (form_str == NULL)
		return (0);
	form_str = (char *)format;
	va_start(args, format);
	printf("originele format: [%s]\n", format);
	while (*form_str)
	{
		if (*form_str == '%')
		{
			form_str++;
			new = ft_check_flag(&form_str);
			//conv_str = ft_check_conv(new);
		}
		form_str++;
		printf("string na flags: [%s]\n", form_str);
	}
	printf("struct na hele loop:\n[%i]\n[%i]\n[%i]\n[%i]\n[%i]\n[%c]\n", new->zerodash, new->spaceplus, new->hash, new->width, new->precision, new->conversion);
	va_end(args);
	return (0);
}
