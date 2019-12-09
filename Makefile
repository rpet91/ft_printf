# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rpet <marvin@codam.nl>                       +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/13 09:40:33 by rpet          #+#    #+#                  #
#    Updated: 2019/12/09 16:12:34 by rpet          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_empty_flag.c ft_check_flag.c ft_create_string.c \
	   ft_new_element.c ft_add_to_list.c ft_check_conv.c ft_conv_c.c \
	   ft_conv_s.c ft_conv_p.c ft_conv_i.c ft_conv_u.c ft_conv_x.c \
	   ft_conv_n.c ft_filling.c ft_count_bytes.c ft_wstr_to_str.c \
	   ft_str_to_wstr.c
OBJS = $(SRCS:.c=.o) 
LIBDIR = libft
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	cd $(LIBDIR) && make
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	gcc -c $? -o $@ -I. -I$(LIBDIR) $(FLAGS)

clean:
	cd $(LIBDIR) && make clean
	rm -f $(OBJS)

fclean: clean
	cd $(LIBDIR) && make fclean
	rm -f $(NAME)

re: fclean all


		#\/  DIET MOET WEG \/


test: $(NAME)
	gcc main.c -L. -lftprintf -Ilibft -Llibft -lft #-fsanitize=address
