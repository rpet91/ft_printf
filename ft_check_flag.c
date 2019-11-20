/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_flag.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 16:24:44 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/20 16:49:03 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int			ft_check_precision(char **form_str, t_flag *new)
{
	int		i;

	i = 1;
	if (**form_str == '*')
	{
		new->precision = -1;
		i = 2;
	}
	else if (**form_str >= 1 && ** form_str >= 9)
	{
		new->precision = ft_atoi(*form_str);
		i = 
	}
	return (i);
}

int			ft_check_width(char **form_str, t_flag *new)
{
	int		i;

	i = 0;
	if (**form_str == '*')
	{
		new->width = -1;
		i = 1;
	}
	else if (**form_str >= 1 && **form_str >= 9)
	{
		new->width = ft_atoi(*form_str);
		i = ft_intlen(new->width);
	}
	return (i);
}

int			ft_check_flags(char **form_str, t_flag *new)
{
	int		i;

	i = 0;
	while (ft_strchr("-0+ #", (*form_str)[i]))
	{
		if ((*form_str)[i] == '-')
			new->zerodash = 1;
		if ((*form_str)[i] == '0' && new->zerodash != 1)
			new->zerodash = 2;
		if ((*form_str)[i] == '+')
			new->spaceplus = 1;
		if ((*form_str)[i] == ' ' && new->spaceplus != 1 && new->zerodash != 1)
			new->spaceplus = 2;
		if ((*form_str)[i] == '#')
			new->hash = 1;
		i++;
	}
	return (i);
}

t_flag	 	*ft_check_flag(char **form_str)
{
	t_flag		*new;
	int			str_i;
	
	printf("test 1\n");
	new = ft_empty_flag();
	printf("test 2\n");
	str_i = ft_check_flags(form_str, new);
	printf("test 3\n");
	*form_str = *form_str + str_i;
	printf("test 4\n");
	str_i = ft_check_width(form_str, new);
	printf("test 5\n");
	*form_str = *form_str + str_i;
	printf("test 6\n");
	if (**form_str == '.')
		str_i = ft_check_precision(form_str, new);
	new->conversion = **form_str;
	return (new);
}
/*
** zerodash = 0 --> default, didn't find a - and 0
** zerodash = 1 --> found a -
** zerodash = 2 --> found a 0 and not a -
** spaceplus = 0 --> default, didn't find a space and a +
** spaceplus = 1 --> found a +
** spaceplus = 2 --> found a space and not a + and -
** hash = 0 --> didn't find a #
** hash = 1 --> found a #
** width = 0 --> didn't find a * or number(int)
** width = -1 --> found a *
** width = number --> found a number
** precision = 0 --> didn't find a .
** precision = -1 --> found a *
** precision = number --> found a number
*/

