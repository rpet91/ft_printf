/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_di.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:52:13 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/25 17:38:15 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>

static char	*ft_fill_string(char *str, t_flag *flag, char *arg_int, int size)
{
	int	i;

	i = 0;
	if (size < flag->width)
		size = flag->width;
	while (i < size)
	{
		str[i] = arg_int[i];
		i++;
	}
	return (str);
}

t_list		*ft_conv_di(va_list args, t_flag *flag)
{
	char	*str;
	char	*arg_int;
	t_list	*new;
	int		size;

	arg_int = ft_itoa(va_arg(args, int));
	size = ft_strlen(arg_int);
	printf("arg_int: [%s]\n", arg_int);
	printf("size: [%i]\n", size);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	if (flag->padding != 1)
		str = ft_fill_string(str, flag, arg_int, size);
	new = ft_new_element(str);
	return (new);
}


