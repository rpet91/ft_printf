/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_xtoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 11:52:32 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/03 12:01:51 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_xtoa(unsigned long long arg_int)
{
	int					i;
	unsigned long long	temp;
	char				*arg_str;

	i = 0;
	temp = arg_int;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	arg_str = malloc(sizeof(char) * (i + 1));
	while (arg_int != 0)
	{
		temp = arg_int % 16 + '0';
		if (temp < 10)
			arg_str[i] = temp;
		else
			arg_str[i] = 87 + temp;
		arg_int = arg_int / 16;
		i++;
	}
	arg_str[i] = '\0';
	return (arg_str);
}
