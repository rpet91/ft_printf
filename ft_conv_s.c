/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:51:19 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/25 17:02:01 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

static char		*ft_str_right(char *str, t_flag *flag, char *arg_str, int size)
{
	int		i;
	int		j;
	char	pad;

	i = 0;
	j = 0;
	while (i < (size - flag->precision))
	{
		pad = (flag->padding == 0) ? ' ' : '0';
		str[i] = pad;
		i++;
	}
	while (i + j < size)
	{
		str[i + j] = arg_str[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

static char		*ft_str_left(char *str, t_flag *flag, char *arg_str, int size)
{
	int		i;

	i = 0;
	while (i < flag->precision)
	{
		str[i] = arg_str[i];
		i++;
	}
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int		ft_check_size(t_flag *flag, int arg_len)
{
	int		size;
	int		precision;
	int		width;

	size = 0;
	precision = flag->precision;
	width = flag->width;
	size = (arg_len <= precision) ? arg_len : precision;
	size = (size <= width) ? width : size;
	return (size);
}

t_list			*ft_conv_s(va_list args, t_flag *flag)
{
	char	*str;
	char	*arg_str;
	t_list	*new;
	int		size;
	int		arg_len;

	arg_str = va_arg(args, char *);
	arg_len = (int)ft_strlen(arg_str);
	if (flag->precision == -1)
		flag->precision = arg_len;
	size = ft_check_size(flag, arg_len);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	if (flag->precision > arg_len)
		flag->precision = arg_len;
	if (flag->padding != 1)
		str = ft_str_right(str, flag, arg_str, size);
	else
		str = ft_str_left(str, flag, arg_str, size);
	new = ft_new_element(str);
	return (new);
}
