/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 09:45:38 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/21 17:47:23 by rpet          ########   odam.nl         */
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
	t_flag		*flag;
	char		*form_str;
	int			malloc_size;

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
			flag = ft_check_flag(args, &form_str);
			malloc_size = ft_check_conv(args, flag);
		}
		form_str++;
		printf("\nstring na flags: [%s]\n", form_str);
	}
	printf("\nstruct na hele loop:\npadding: [%i]\nleading: [%i]\nhash: [%i]\nwidth: [%i]\nprecision: [%i]\nmodifier: [%i]\nconversion: [%c]\n", flag->padding, flag->leading, flag->hash, flag->width, flag->precision, flag->modifier, flag->conversion);
	va_end(args);
	return (0);
}
