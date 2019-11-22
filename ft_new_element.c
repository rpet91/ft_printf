/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_new_element.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 10:41:17 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/22 11:14:08 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

t_list	*ft_new_element(char *str)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->content = str;
	element->next = NULL;
	return (element);
}
