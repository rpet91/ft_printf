/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wstrdup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:02:37 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/10 14:06:34 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>

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
