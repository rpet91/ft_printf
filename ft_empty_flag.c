/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_empty_flag.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 16:27:09 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/03 10:56:01 by rpet          ########   odam.nl         */
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
	empty->padding = 0;
	empty->leading = 0;
	empty->hash = 0;
	empty->width = 0;
	empty->precision = 0;
	empty->modifier = 0;
	empty->conversion = 0;
	empty->flag_len = 0;
	return (empty);
}
