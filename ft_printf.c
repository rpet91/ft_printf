/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 09:45:38 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/02 15:37:47 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_flag		*flag;
	t_list		*new;
	t_list		*head;
	t_list		*jemoeder;
	char		*form_str;

	form_str = malloc(sizeof(char*));
	if (form_str == NULL)
		return (0);
	form_str = (char *)format;
	head = NULL;
	va_start(args, format);
	while (*form_str)
	{
		if (*form_str == '%')
		{
			form_str++;
			flag = ft_check_flag(args, form_str);
			new = ft_check_conv(args, flag);
			form_str = form_str + flag->flag_len;
		}
		else
			new = ft_create_string(&form_str);
	//	printf("nieuwe str: [%s]\n", new);
		ft_add_to_list(new, &head);
		form_str++;
		//printf("string na verwerking: [%s]\n", form_str);
	}
//	write(1, "Resultaat: ", 11);
	while (head)
	{
		//printf("[%s]", head->current->content);
		write(1, head->current->content, head->current->length);
		jemoeder = head->next;
		free(head->current->content);
		free(head->current);
		free(head);
		head = jemoeder;
	}
	va_end(args);
	return (0);
}
