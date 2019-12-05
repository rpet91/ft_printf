/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_to_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 11:24:36 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/05 15:01:08 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

void	ft_add_to_list(t_list *new, t_list **head)
{
	t_list		*last;

	if (new == NULL)
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
