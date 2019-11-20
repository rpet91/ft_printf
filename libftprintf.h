/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_libftprintf.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 10:14:36 by rpet          #+#    #+#                 */
/*   Updated: 2019/11/20 16:38:38 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

typedef struct	s_flag
{
	int			zerodash;
	int			spaceplus;
	int			hash;
	int			width;
	int			precision;
	char		conversion;
}				t_flag;

int			ft_printf(const char *format, ...);
t_flag		*ft_empty_flag(void);
t_flag		*ft_check_flag(char **form_str);
//char		*ft_check_conv(t_flag *flag);
/*iest	ft_flag_process(iets);*/
//char		*ft_conv_c(t_flag *flag);
/*iets	ft_conv_s(iets);
iets	ft_conv_p(iets);
iets	ft_conv_d(iets);
iets	ft_conv_i(iets);
iets	ft_conv_u(iets);
iets	ft_conv_x_low(iets);
iets	ft_conv_x_upp(iets);
iets	ft_conv_perc(iets);*/

#endif
