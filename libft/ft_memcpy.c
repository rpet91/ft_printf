/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 09:46:43 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/16 17:43:02 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;
	size_t				i;

	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > i)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}
