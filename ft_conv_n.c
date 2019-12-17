/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_n.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 07:50:43 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/17 09:11:24 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_apply_modifier(long long **amount, t_flag *flag)
{
	if (flag->modifier == 0)
		*amount = (long long *)(int *)*amount;
	if (flag->modifier == 1)
		*amount = (long long *)(long *)*amount;
	if (flag->modifier == 3)
		*amount = (long long *)(short *)*amount;
	if (flag->modifier == 4)
		*amount = (long long *)(signed char *)*amount;
}

void		ft_conv_n(va_list args, t_flag *flag, int print_len)
{
	long long			*amount;

	amount = (long long *)va_arg(args, int *);
	ft_apply_modifier(&amount, flag);
	*amount = (long long)print_len;
}
