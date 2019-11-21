/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:51:08 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/21 17:47:27 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

#include <stdio.h>

int		ft_conv_c(va_list args, t_flag *flag)
{
	//char	*str;
	char	c;
	int		len;
	int		pad;

	c = (char)va_arg(args, int);
	len = flag->width;
	pad = flag->padding;
	printf("lengte: [%i]\n", len);
	printf("padding: [%i]\n", pad);
	//if (flag->padding == 1)
	printf("Als hier komt is het joepie: [%666c]\n", c);		
	return (len);
}
