/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_zero_removal.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 14:30:09 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/30 14:47:52 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_count_zeros(char *str)
{
	int		i;
	int		amount;
	
	i = (int)ft_strlen(str) - 1;
	amount = 0;
	while (str[i] == '0')
	{
		amount++;
		i--;
	}
	return (amount);
}

static char		*ft_create_nb_str1(double arg_dbl, t_flag *flag)
{
	unsigned long long	nb;

	if (flag->conversion != 'f')
		return (ft_exp_mid_nb(arg_dbl, flag));
	nb = (unsigned long long)arg_dbl + ft_rounding(arg_dbl, flag);
	nb = (nb == 0) ? 1 : nb;
	return (ft_itoa_dec(nb, ft_countdigits(nb), 0));	
}

int				ft_erase_zeros(double arg_dbl, t_flag *flag)
{
	unsigned long long	nb;
	int					ret;
	int					temp_precision;
	char				*nb_str1;
	char				*nb_str2;

	if (arg_dbl == 0)
		return (flag->precision);
	arg_dbl *= (arg_dbl < 0) ? -1 : 1;
	nb_str1 = ft_create_nb_str1(arg_dbl, flag);
	if (flag->conversion != 'f')
		return (ft_count_zeros(nb_str1));
	temp_precision = flag->precision;
	while (flag->precision > 0)
	{
		arg_dbl *= 10;
		flag->precision--;
	}
	nb = (unsigned long long)arg_dbl + ft_rounding(arg_dbl, flag);
	flag->precision = temp_precision;
	nb_str2 = ft_itoa_dec(nb, ft_countdigits(nb), 0);
	ret = ft_count_zeros(nb_str2) - ft_count_zeros(nb_str1);
	return (ret);
}
