/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 07:51:59 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/02 18:01:16 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>



t_list		*ft_conv_p(va_list args, t_flag *flag)
{
	void	*arg_ptr;
	char	*str;
//	t_list	*new;
	int		size;
	int		kaas;

	arg_ptr = va_arg(args, void *);
	str = arg_ptr;
	kaas = flag->padding;
	printf("arg_ptr: [%p]\n", arg_ptr);
	printf("str: [%s]\n", str);
	size = (int)ft_strlen(arg_ptr);
	printf("size: [%i]\n", size);
//	str = malloc(sizeof(char) * (size + 1));
//	new = ft_new_element(str, size);
	return (0);
}
