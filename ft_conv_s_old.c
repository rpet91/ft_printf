/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:51:19 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/05 15:01:50 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

static char	*ft_create_str(char *str, char *arg_str, t_flag *flag, int amount)
{
	int		i;
	int		size;
	char	fill;

	size = (amount < flag->width) ? flag->width : amount;
	fill = (flag->padding == 2) ? '0' : ' ';
	str = ft_filling(str, fill, size);
	i = 0;
	while (i < amount)
	{
		if (flag->padding == 1)
			str[i] = arg_str[i];
		else
			str[i + (size - amount)] = arg_str[i];
		i++;
	}
	return (str);
}

t_list		*ft_conv_s(va_list args, t_flag *flag)
{
	char	*str;
	char	*arg_str;
	t_list	*new;
	int		size;
	int		amount;

	arg_str = va_arg(args, char*);
	if (arg_str == NULL)
		arg_str = ft_strdup("(null)");
	amount = (int)ft_strlen(arg_str);
	if (flag->precision == -1)
		flag->precision = amount;
	amount = (amount < flag->precision) ? amount : flag->precision;
	size = (amount < flag->width) ? flag->width : amount;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str = ft_create_str(str, arg_str, flag, amount);
	new = ft_new_element(str, size);
	flag->print_len += size;
	return (new);
}
