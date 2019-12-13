/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wstr_convert.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 13:47:02 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/13 14:55:59 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "libft.h"

wchar_t		*ft_wstrdup(wchar_t *wstr)
{
	wchar_t		*ret;
	int			i;

	i = 0;
	while (wstr[i] != '\0')
		i++;
	ret = malloc(sizeof(wchar_t) * (i + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (wstr[i] != '\0')
	{
		ret[i] = wstr[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

wchar_t		*ft_str_to_wstr(char *str)
{
	wchar_t		*ret;
	int			i;

	ret = malloc(sizeof(wchar_t) * (ft_strlen(str) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static int	ft_convert_to_wchar(wchar_t arg_char, unsigned char *str)
{
	if (arg_char <= 0x7F)
	{
		str[0] = arg_char;
		return (1);
	}
	else if (arg_char <= 0x7FF)
	{
		str[0] = 0xC0 | arg_char >> 6;
		str[1] = 0x80 | (arg_char & 0x3F);
		return (2);
	}
	else if (arg_char <= 0x7FFF)
	{
		str[0] = 0xE0 | arg_char >> 12;
		str[1] = 0x80 | (arg_char >> 6 & 0x3F);
		str[2] = 0x80 | (arg_char & 0x3F);
		return (3);
	}
	str[0] = 0xF0 | arg_char >> 18;
	str[1] = 0x80 | (arg_char >> 12 & 0x3F);
	str[2] = 0x80 | (arg_char >> 6 & 0x3F);
	str[3] = 0x80 | (arg_char & 0x3F);
	return (4);
}

void		ft_wstr_to_str(wchar_t *wstr, unsigned char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		str += ft_convert_to_wchar(wstr[i], str);
		i++;
	}
	*str = '\0';
}

int			ft_count_bytes(wchar_t wchar)
{
	if (wchar <= 0x7F)
		return (1);
	else if (wchar <= 0x7FF)
		return (2);
	else if (wchar <= 0x7FFF)
		return (3);
	return (4);
}
