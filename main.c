/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:34:07 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/09 18:00:16 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_NUMERIC, "en_US");
	setlocale(LC_ALL, "");
	wchar_t			*str;
	char			c;
	int				i;
	int				a;
	int				b;
	char			*s;
	
	i = 1235464;
	c = 'R';
	s = strdup("NULL");
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
	a = ft_printf("%ls", str);
	printf(" | <--- mijn functie\n");
	b = printf("%ls", str);
	printf(" | <--- echte printf\n");
	printf("a: [%i]\n", a);
	printf("b: [%i]\n", b);
//	while(1);
	return (0);
}
/*
flag verduidelijking:
'-' = zet output links neer ipv rechts (default).
'0' = vult de rest van de string met nullen. Wordt genegeerd door '-'.
'.' = alles na de . gaat over length_modifier. 
'*' = kijkt naar waarde van volgende argument, moet een int zijn.
'width' = minimale width van string. is een getal of *.
'.*' = gaat over length modifier. gaat alleen samen met 'sefgdiuxX'.
'l' =  
'll'= 
'h' = 
'hh'= 
`'` = 
'#' = werkt alleen met de conversions 'xXfge'. zet 0x/0X voor x/X.
' ' = zet een spatie vooraan de output. Wordt genegeerd door '+' en '-'.
'+' = zet een plus vooraan de output.

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
'n' = 
'f' = 
'g' = 
'e' = 
*/
