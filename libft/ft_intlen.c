/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 12:55:54 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/02 12:11:08 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_intlen(long long n)
{
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + neg);
}
