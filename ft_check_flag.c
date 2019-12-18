/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_flag.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 16:24:44 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/18 17:16:36 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

/*
** padding = 0 --> didn't find -/0
** padding = 1 --> found a -
** padding = 2 --> found a 0 and not a -
** leading = 0 --> didn't find +/'_'
** leading = 1 --> found a +
** leading = 2 --> found a space and not a +
** hash = 0 --> didn't find a #
** hash = 1 --> found a #
** decimal = 0 --> didn't find an '
** decimal = 1 --> found an '
** width = 0 --> didn't find a * or number
** width = number --> found a * or number
** precision = -1 --> no precision found
** precision = 0 ---> found a . only or number = 0
** precision = number --> found a . and number or *
** modifier = 0 --> didn't find l/ll/h/hh
** modifier = 1 --> found l
** modifier = 2 --> found ll
** modifier = 3 --> found h
** modifier = 4 --> found hh
*/

static int		ft_check_modifier(char *form_str, t_flag *flag)
{
	if (*form_str == 'l' && *(form_str + 1) != 'l')
	{
		flag->modifier = 1;
		flag->flag_len = flag->flag_len + 1;
		return (1);
	}
	if (*form_str == 'l' && *(form_str + 1) == 'l')
	{
		flag->modifier = 2;
		flag->flag_len = flag->flag_len + 2;
		return (2);
	}
	if (*form_str == 'h' && *(form_str + 1) != 'h')
	{
		flag->modifier = 3;
		flag->flag_len = flag->flag_len + 1;
		return (1);
	}
	if (*form_str == 'h' && *(form_str + 1) == 'h')
	{
		flag->modifier = 4;
		flag->flag_len = flag->flag_len + 2;
		return (2);
	}
	return (0);
}

static int		ft_check_precision(va_list args, char *form_str, t_flag *flag)
{
	int		i;

	i = 1;
	form_str++;
	if (*form_str != '*' && ft_isdigit(*form_str) == 0)
		flag->precision = 0;
	if (*form_str == '*')
	{
		flag->precision = va_arg(args, int);
		flag->precision = (flag->precision < 0) ? -1 : flag->precision;
		i = 2;
	}
	while (ft_isdigit(*form_str) == 1 && *form_str != '\0')
	{
		flag->precision = flag->precision * 10 + *form_str - '0';
		form_str++;
		i++;
	}
	flag->flag_len = flag->flag_len + i;
	return (i);
}

static int		ft_check_width(va_list args, char *form_str, t_flag *flag)
{
	int		i;

	i = 0;
	if (*form_str == '*')
	{
		flag->width = va_arg(args, int);
		if (flag->width < 0)
		{
			flag->width *= -1;
			flag->padding = 1;
		}
		i = 1;
	}
	while (ft_isdigit(*form_str) == 1 && *form_str != '\0')
	{
		flag->width = flag->width * 10 + *form_str - '0';
		form_str++;
		i++;
	}
	flag->flag_len = flag->flag_len + i;
	return (i);
}

static int		ft_check_flags(char *form_str, t_flag *flag)
{
	int		i;

	i = 0;
	while (ft_strchr("-0+ #'", form_str[i]) && form_str[i] != '\0')
	{
		if (form_str[i] == '-')
			flag->padding = 1;
		if (form_str[i] == '0' && flag->padding != 1)
			flag->padding = 2;
		if (form_str[i] == '+')
			flag->leading = '+';
		if (form_str[i] == ' ' && flag->leading != '+')
			flag->leading = ' ';
		if (form_str[i] == '#')
			flag->hash = 1;
		if (form_str[i] == '\'')
			flag->decimal = 1;
		i++;
	}
	flag->flag_len = flag->flag_len + i;
	return (i);
}

void			ft_check_flag(va_list args, char *form_str, t_flag *flag)
{
	int			str_i;

	form_str++;
	flag->flag_len++;
	str_i = ft_check_flags(form_str, flag);
	form_str = form_str + str_i;
	str_i = ft_check_width(args, form_str, flag);
	form_str = form_str + str_i;
	if (*form_str == '.')
	{
		str_i = ft_check_precision(args, form_str, flag);
		form_str = form_str + str_i;
	}
	else
		flag->precision = -1;
	str_i = ft_check_modifier(form_str, flag);
	form_str = form_str + str_i;
	if (*form_str == '\0')
		flag->conversion = *form_str;
	else
	{
		flag->conversion = *form_str;
		flag->flag_len++;
	}
}
