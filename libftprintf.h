/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_libftprintf.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 10:14:36 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/16 16:07:17 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <wchar.h>

typedef struct		s_flag
{
	int				padding;
	int				leading;
	int				hash;
	int				decimal;
	int				width;
	int				precision;
	int				modifier;
	char			conversion;
	int				flag_len;
}					t_flag;

int					ft_printf(const char *format, ...);
t_flag				*ft_empty_flag(void);
void				ft_check_flag(va_list args, char *form_str, t_flag *flag);
int					ft_create_string(const char *format, t_flag *flag);
int					ft_check_conv(va_list args, t_flag *flag, int print_len);
int					ft_conv_c(va_list args, t_flag *flag);
int					ft_conv_s(va_list args, t_flag *flag);
int					ft_conv_p(va_list args, t_flag *flag);
int					ft_conv_i(va_list args, t_flag *flag);
int					ft_conv_u(va_list args, t_flag *flag);
int					ft_conv_x(va_list args, t_flag *flag);
void				ft_conv_n(va_list args, t_flag *flag, int print_len);
int					ft_conv_f(va_list args, t_flag *flag);
char				*ft_filling(char *str, char fill, int size);
wchar_t				*ft_wfilling(wchar_t *str, char fill, int size);
wchar_t				*ft_wstrdup(wchar_t *wstr);
wchar_t				*ft_str_to_wstr(char *str);
void				ft_wstr_to_str(wchar_t *wstr, unsigned char *str, int size);
int					ft_count_bytes(wchar_t wchar);
unsigned long long	ft_create_dec_nb(double arg_dbl, t_flag *flag);
int					ft_check_special(double arg_dbl, t_flag *flag);
char				*ft_create_special(double arg_dbl, char *str, t_flag *flag);

#endif
