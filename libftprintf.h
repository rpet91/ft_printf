/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_libftprintf.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 10:14:36 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/09 16:20:17 by rpet          ########   odam.nl         */
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
	int				print_len;
}					t_flag;

typedef struct		s_list
{
	struct s_print	*current;
	struct s_list	*next;
}					t_list;

typedef struct		s_print
{
	void			*content;
	int				length;
}					t_print;

int					ft_printf(const char *format, ...);
t_flag				*ft_empty_flag(void);
void				ft_check_flag(va_list args, char *form_str, t_flag *flag);
t_list				*ft_create_string(char *form_str, t_flag *flag);
t_list				*ft_new_element(void *str, int length);
void				ft_add_to_list(t_list *new, t_list **head);
t_list				*ft_check_conv(va_list args, t_flag *flag, int print_len);
t_list				*ft_conv_c(va_list args, t_flag *flag);
t_list				*ft_conv_s(va_list args, t_flag *flag);
t_list				*ft_conv_p(va_list args, t_flag *flag);
t_list				*ft_conv_i(va_list args, t_flag *flag);
t_list				*ft_conv_u(va_list args, t_flag *flag);
t_list				*ft_conv_x(va_list args, t_flag *flag);
void				ft_conv_n(va_list args, t_flag *flag, int print_len);
char				*ft_filling(char *str, char fill, int size);
wchar_t				*ft_wfilling(wchar_t *str, char fill, int size);
int					ft_count_bytes(wchar_t wchar);
void				ft_wstr_to_str(wchar_t *wstr, unsigned char *str, int size);
wchar_t				*ft_str_to_wstr(char *str);

#endif
