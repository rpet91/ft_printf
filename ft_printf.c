/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 09:45:38 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/22 17:15:40 by rpet          ########   odam.nl         */
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
	t_list		*new;
	t_list		*print;
	char		*form_str;

	form_str = malloc(sizeof(char*));
	if (form_str == NULL)
		return (0);
	form_str = (char *)format;
	print = NULL;
	va_start(args, format);
	printf("Originele format: [%s]\n\n", format);
	while (*form_str)
	{
		if (*form_str == '%')
		{
			form_str++;
			flag = ft_check_flag(args, &form_str);
			new = ft_check_conv(args, flag);
		}
		else
			new = ft_create_string(&form_str);
		ft_add_to_list(new, &print);
		form_str++;
	}
	printf("Resultaat: ");
	while (print)
	{
		printf("%s", print->content);
		print = print->next;
	}
/*	printf("\n\nstruct na hele loop:\npadding: [%i]\nleading: [%i]\nhash: [%i]\nwidth: [%i]\nprecision: [%i]\nmodifier: [%i]\nconversion: [%c]\n", flag->padding, flag->leading, flag->hash, flag->width, flag->precision, flag->modifier, flag->conversion);*/
	va_end(args);
	return (0);
}
