/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:34:07 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/25 17:38:20 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libftprintf.h"
#include "libft.h"

int		main(void)
{
	char	*format;
	char	*str;
	char	c1;
	int		i;

	c1 = 't';
	i = -1234;
	str = strdup("fjkdgkjdfs");
	ft_printf("%10i", i);
//	printf("printf: [%10.4i]\n", i);
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
