/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wstr_to_str.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 13:47:02 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/09 16:12:31 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

static int		ft_convert_to_wchar(wchar_t arg_char, unsigned char *str)
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

void			ft_wstr_to_str(wchar_t *wstr, unsigned char *str, int size)
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
