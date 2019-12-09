/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_to_wstr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 16:15:29 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/09 17:04:01 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

wchar_t		*ft_str_to_wstr(char *str)
{
	wchar_t		*ret;
	size_t		i;

	i = ft_strlen(str);
	ret = malloc(sizeof(wchar_t) * (i + 1));
	i = 0;
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
