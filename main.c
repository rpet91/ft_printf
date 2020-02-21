/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:34:07 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/30 15:10:30 by rpet          ########   odam.nl         */
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
#include <float.h>

int		main(void)
{
	setlocale(LC_ALL, "en_US");
	int					a;
	int					b;
	wchar_t				*str;
	wchar_t				*str2;
	char				c;
	char				*s;
	void				*ptr;
	double				f1;
	double				f2;
	long long			ll1;
	long long			ll2;
	long				l;
	unsigned long long	u;
	double				u1;
	char				unit[200];
	int					t3 = -1;
	int					t4 = -1;
	int					i = 199;

	while (i--)
		unit[i] = '0';
	unit[199] = 0;
//	u = 0x7FF0000000000000; //inf
//	u = 0xFFF0000000000000; //-inf
//	u = 0x7FF0000000000001; //nan
//	u = 0x8000000000000000; //-0
	u = 0xffffffffffffffff;
	u1 = *(double *)&u;
	ll1 = LLONG_MIN;
	ll2 = LLONG_MAX;
	l = 4223372036854775800;
	i = INT_MAX;
	f1 = INT_MAX;
	f2 = DBL_MAX;
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
	t[3] = 0; 	ft_printf("[");
	a = ft_printf("%s%hhn ", unit, &t4);
	printf("] | <--- mijn functie\n[");
	b = printf("%s%hhn ", unit, &t3);
	printf("] | <--- echte printf\n");
	printf("a: [%hhi]\n", t4);
	printf("b: [%hhi]\n", t3);
	free(str);
	free(s);
	//while(1);
	return (0);
}
