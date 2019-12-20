/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:34:07 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/20 14:00:56 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "libftprintf.h"
#include <locale.h>
#include <limits.h>
#include <math.h>

int		main(void)
{
	setlocale(LC_ALL, "en_US");
	int					a;
	int					b;
	wchar_t				*str;
	wchar_t				*str2;
	char				c;
	int					i;
	char				*s;
	void				*ptr;
	double				f1;
	double				f2;
	long long			ll1;
	long long			ll2;
	long				l;
	unsigned long long	u;
	double				u1;

//	u = 0x7FF0000000000000; //inf
//	u = 0xFFF0000000000000; //-inf
//	u = 0x7FF0000000000001; //nan
	u = 0x8000000000000000; //-0
	u1 = *(double *)&u;
	ll1 = LLONG_MIN;
	ll2 = LLONG_MAX;
	l = 4223372036854775800;
	i = -1;
	f1 = 0;//15394.351;
	f2 = -2396421.02510421;
	c = 'R';
	ptr = &i;
	s = strdup("Remkoe");
	str = ft_wstrdup(L"egg plant ");
	str[3] = 0x1F95A;
	str[9] = 0x1F331;
	wchar_t t[4];
	t[0] = 65; // = 1
	t[1] = 191; // = 2
	t[2] = 128519; // = 4
	t[3] = 0;
	ft_printf("[");
	a = ft_printf("%.e", f1);
	printf("] | <--- mijn functie\n[");
	b = printf("%.e", f1);
	printf("] | <--- echte printf\n");
	printf("a: [%i]\n", a);
	printf("b: [%i]\n", b);
	free(str);
	free(s);
	//while(1);
	return (0);
}//127  2047  65535
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
