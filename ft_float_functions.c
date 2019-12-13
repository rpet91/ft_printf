/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 07:58:31 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/13 11:22:23 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long long	ft_create_dec_nb(double arg_dbl, t_flag *flag)
{
	int					temp;
	unsigned long long	dec_nb;

	dec_nb = 1;
	temp = 0;
	while (temp < flag->precision + 1)
	{
		dec_nb *= 10;
		temp++;
	}
	dec_nb = ((arg_dbl - (unsigned long long)arg_dbl) * dec_nb);
	temp = dec_nb - (dec_nb / 10) * 10;
	dec_nb = (temp < 5) ? dec_nb / 10 : (dec_nb / 10) + 1;
	return (dec_nb);
}
