/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_bytes.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 15:23:24 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/06 16:15:38 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int		ft_count_bytes(wchar_t wchar)
{
	int		size;

	if (wchar <= 0x7F)
		size = 1;
	else if (wchar <= 0x7FF)
		size = 2;
	else if (wchar <= 0x7FFF)
		size = 3;
	else
		size = 4;
	return (size);
}
