/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_build_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:18:20 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/31 13:02:20 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "libftprintf.h"

char		*ft_filling(char *str, char fill, int size)
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

wchar_t		*ft_wfilling(wchar_t *str, char fill, int size)
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

char		*ft_strmerge(char *dst, char *src, int padding, int sign)
{
	int		i;
	int		size;
	int		amount;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = sign;
	size = (int)ft_strlen(dst);
	amount = (int)ft_strlen(src);
	while (i < amount)
	{
		if (padding == 1)
			dst[i] = src[i];
		else
			dst[i + (size - amount)] = src[i];
		i++;
	}
	return (dst);
}

char		*ft_itoa_dec(unsigned long long arg_int, int size, int dec)
{
	int		i;
	char	*arg_str;

	arg_str = malloc(sizeof(char) * (size + 1));
	if (arg_str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		i++;
		if (dec > 0 && (i - 1) % 4 == 3)
		{
			arg_str[size - i] = ',';
			dec--;
		}
		else
		{
			arg_str[size - i] = arg_int % 10 + '0';
			arg_int /= 10;
		}
	}
	arg_str[i] = '\0';
	return (arg_str);
}
