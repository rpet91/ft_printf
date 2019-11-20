/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_empty_flag.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 16:27:09 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/20 16:37:12 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

t_flag		*ft_empty_flag(void)
{
	t_flag		*empty;

	empty = malloc(sizeof(t_flag));
	if (empty == NULL)
		return (NULL);
	empty->zerodash = 0;
	empty->spaceplus = 0;
	empty->hash = 0;
	empty->width = 0;
	empty->precision = 0;
	empty->conversion = 0;
	return (empty);
}
