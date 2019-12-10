/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 09:45:38 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/10 11:20:58 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

static void	ft_write_list(t_list *head)
{
	t_list		*temp;

	while (head)
	{
		write(1, head->current->content, head->current->length);
		temp = head->next;
		free(head->current->content);
		free(head->current);
		free(head);
		head = temp;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_flag		*flag;
	t_list		*new;
	t_list		*head;
	int			print_len;

	head = NULL;
	print_len = 0;
	va_start(args, format);
	while (*format)
	{
		flag = ft_empty_flag();
		if (*format == '%')
		{
			ft_check_flag(args, format, flag);
			new = ft_check_conv(args, flag, print_len);
		}
		else
			new = ft_create_string(format, flag);
		ft_add_to_list(new, &head);
		format += flag->flag_len;
		print_len += (new) ? new->current->length : 1;
		free(flag);
	}
	ft_write_list(head);
	va_end(args);
	return (print_len);
}
