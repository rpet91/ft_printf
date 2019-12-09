/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_new_element.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 10:41:17 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/09 08:50:00 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

t_list	*ft_new_element(void *str, int length)
{
	t_print	*data;
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	data = malloc(sizeof(t_print));
	if (data == NULL)
		return (NULL);
	data->content = str;
	data->length = length;
	element->current = data;
	element->next = NULL;
	return (element);
}
