/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create_string.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 15:29:33 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/05 09:37:45 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

t_list		*ft_create_string(char *form_str, t_flag *flag)
{
	char	*str;
	size_t	len;
	t_list	*new;

	len = 0;
	while (form_str[len] != '%' && form_str[len] != '\0')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, form_str, len + 1);
	flag->flag_len = (int)len;
	new = ft_new_element(str, (int)len);
	flag->print_len += (int)len;
	return (new);
}
