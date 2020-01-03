/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_n.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 07:50:43 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/31 10:20:36 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

void		ft_conv_n(va_list args, t_flag *flag, int print_len)
{
	long long			*amount;

	amount = (long long *)va_arg(args, int *);
	if (amount == NULL)
		return ;
	if (flag->modifier == 0)
		*((int *)amount) = (int)print_len;
	if (flag->modifier == 1)
		*((long *)amount) = (long)print_len;
	if (flag->modifier == 2)
		*((long long *)amount) = (long long)print_len;
	if (flag->modifier == 3)
		*((short *)amount) = (short)print_len;
	if (flag->modifier == 4)
		*((signed char *)amount) = (signed char)print_len;
}
