/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_countdigits.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 10:21:06 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/19 10:34:26 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_countdigits(unsigned long long number)
{
	int		result;

	result = 0;
	number += (number == 0) ? 1 : 0;
	while (number != 0)
	{
		number /= 10;
		result++;
	}
	return (result);
}
