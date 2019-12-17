/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create_string.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 15:29:33 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/17 16:13:47 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"

int		ft_create_string(const char *format, t_flag *flag)
{
	char	*str;
	int		size;

	size = 0;
	while (format[size] != '%' && format[size] != '\0')
		size++;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str[size] = '\0';
	ft_memcpy(str, format, (size_t)size);
	flag->flag_len = size;
	write(1, str, size);
	free(str);
	return (size);
}
