/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_libftprintf.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 10:14:36 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/21 17:47:28 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>

typedef struct	s_flag
{
	int			padding;
	int			leading;
	int			hash;
	int			width;
	int			precision;
	int			modifier;
	char		conversion;
}				t_flag;

int			ft_printf(const char *format, ...);
t_flag		*ft_empty_flag(void);
t_flag		*ft_check_flag(va_list args, char **form_str);
int			ft_check_conv(va_list args, t_flag *flag);
//iets		ft_flag_process(iets);
int			ft_conv_c(va_list args, t_flag *flag);
//iets		ft_conv_s(iets);
//iets		ft_conv_p(iets);
//iets		ft_conv_d(iets);
//iets		ft_conv_i(iets);
//iets		ft_conv_u(iets);
//iets		ft_conv_x_low(iets);
//iets		ft_conv_x_upp(iets);
//iets		ft_conv_perc(iets);

#endif
