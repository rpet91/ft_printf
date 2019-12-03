/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_libftprintf.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 10:14:36 by rpet          #+#    #+#                 */
/*   Updated: 2019/12/03 10:56:11 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>

typedef struct		s_flag
{
	int				padding;
	int				leading;
	int				hash;
	int				width;
	int				precision;
	int				modifier;
	char			conversion;
	int				flag_len;
}					t_flag;

typedef struct		s_list
{
	struct s_print	*current;
	struct s_list	*next;
}					t_list;

typedef struct		s_print
{
	char			*content;
	int				length;
}					t_print;

int					ft_printf(const char *format, ...);
t_flag				*ft_empty_flag(void);
t_flag				*ft_check_flag(va_list args, char *form_str);
t_list				*ft_create_string(char **form_str);
t_list				*ft_new_element(char *str, int length);
void				ft_add_to_list(t_list *new, t_list **start);
t_list				*ft_check_conv(va_list args, t_flag *flag);
t_list				*ft_conv_c(va_list args, t_flag *flag);
t_list				*ft_conv_s(va_list args, t_flag *flag);
//t_list				*ft_conv_p(va_list args, t_flag *flag);
t_list				*ft_conv_i(va_list args, t_flag *flag);
t_list				*ft_conv_u(va_list args, t_flag *flag);
t_list				*ft_conv_x_low(va_list args, t_flag *flag);
//iets				ft_conv_x_upp(iets);
char				*ft_filling(char *str, char fill, int size);

#endif
