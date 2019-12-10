/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:34:07 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/10 14:15:40 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"
#include <locale.h>
#include <limits.h>

int		main(void)
{
	setlocale(LC_NUMERIC, "en_US");
	setlocale(LC_ALL, "");
	wchar_t			*str;
	wchar_t			*str2;
	char			c;
	int				i;
	int				a;
	int				b;
	char			*s;
	void			*ptr;
	double			f;

	i = 1235464;
	f = 11/6;
	c = 'R';
	ptr = &i;
	s = strdup("kaas");
	str = malloc(sizeof(wchar_t) * 10);
	str[0] = 'k';
	str[1] = 'a';
	str[2] = 'a';
	str[3] = 's';
	str[4] = 0x1F9C0;
	str[5] = 'k';
	str[6] = 'i';
	str[7] = 'p';
	str[8] = 0x1F414;
	str[9] = 0;
	str2 = L"NULL";
	ft_printf("[");
	a = ft_printf("%lc", 0x7FA);
	printf("] | <--- mijn functie\n[");
	b = printf("%lc", 0x7FA);
	printf("] | <--- echte printf\n");
	printf("a: [%i]\n", a);
	printf("b: [%i]\n", b);
	free(str);
	free(s);
	//while(1);
	return (0);
}
/*
tests die falen:
("Kashim a %c histoires à raconter", 1001);
("%c\n", INT_MAX);



conversions verduidelijking:
'c' = character.
's' = string.
'p' = pointer.
'd' = decimal signed integer.
'i' = decimal signed integer.
'u' = unsigned integer.
'x' = hex integer. icm een # geen 0x.
'X' = hex integer (met hoofdletter). icm een # geen 0X.
'%' = plaats alleen de %.
'n' = slaat op hoeveel characters op dat moment zijn geprint.
'f' = 
'g' = 
'e' = 
*/
