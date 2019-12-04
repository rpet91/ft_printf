/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 09:45:38 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/04 15:05:05 by rpet          ########   odam.nl         */
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
	t_list		*temp;
	char		*form_str;
	int			res;

	form_str = malloc(sizeof(char*));
	if (form_str == NULL)
		return (0);
	form_str = (char *)format;
	head = NULL;
	va_start(args, format);
	while (*form_str)
	{
	//	printf("str voor: %s\n", form_str);
		flag = ft_empty_flag();
		if (*form_str == '%')
		{
			ft_check_flag(args, form_str, flag);
			new = ft_check_conv(args, flag);
		}
		else
			new = ft_create_string(form_str, flag);
		ft_add_to_list(new, &head);
		form_str = form_str + flag->flag_len;
	//	printf("str na: %s\n", form_str);
	}
	res = 0;
	while (head)
	{
		write(1, head->current->content, head->current->length);
		res = res + head->current->length;
		temp = head->next;
		free(head->current->content);
		free(head->current);
		free(head);
		head = temp;
	}
	va_end(args);
	return (res);
}
