/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_filling.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:18:20 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/06 16:17:24 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

char	*ft_filling(char *str, char fill, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		str[i] = fill;
		i++;
	}
	str[i] = '\0';
	return (str);
}

wchar_t	*ft_wfilling(wchar_t *str, char fill, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		str[i] = fill;
		i++;
	}
	str[i] = '\0';
	return (str);
}
