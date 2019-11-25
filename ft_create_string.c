/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create_string.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 15:29:33 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/25 08:51:42 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

t_list		*ft_create_string(char **form_str)
{
	char	*str;
	int		i;
	int		len;
	t_list	*new;

	len = 0;
	while (*(*form_str + len) != '%' && *(*form_str + len) != '\0')
		len++;
	if ()
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = *(*form_str + i);
		i++;
	}
	str[i] = '\0';
	*form_str = *form_str + (i - 1);
	new = ft_new_element(str);
	return (new);
}
