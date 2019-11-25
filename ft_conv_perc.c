/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_perc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 08:10:40 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/22 18:24:07 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include <stdio.h>

t_list		*ft_conv_perc(char **form_str)
{
	char	*str;
	t_list	*new;

	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (0);
	*str = '%';
	str++;
	*str = '\0';
	*form_str = *form_str + 2;
	printf("string: [%s]\n", str);
	new = ft_new_element(str);
	return (new);
}
