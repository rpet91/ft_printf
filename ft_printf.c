/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 09:45:38 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/25 12:29:25 by rpet          ########   odam.nl         */
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
	t_list		*head;
	char		*form_str;

	form_str = malloc(sizeof(char*));
	if (form_str == NULL)
		return (0);
	form_str = (char *)format;
	head = NULL;
	va_start(args, format);
	printf("Originele format: [%s]\n\n", format);
	while (*form_str)
	{
		if (*form_str == '%'  && *(form_str + 1) != '%')
		{
			form_str++;
			flag = ft_check_flag(args, form_str);
			new = ft_check_conv(args, flag);
			form_str = form_str + flag->flag_len;
		}
		else
			new = ft_create_string(&form_str);
		ft_add_to_list(new, &head);
		form_str++;
		printf("string na verwerking: [%s]\n", form_str);
	}
	printf("Resultaat: ");
	while (head)
	{
		printf("[%s]", head->content);
		head = head->next;
	}
	va_end(args);
	return (0);
}
