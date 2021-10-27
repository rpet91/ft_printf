# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rpet <marvin@codam.nl>                       +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/13 09:40:33 by rpet          #+#    #+#                  #
#    Updated: 2021/10/27 09:16:00 by rpet          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TESTNAME = printf
SRCS = ft_printf.c ft_empty_flag.c ft_check_flag.c ft_check_conv.c \
	   ft_create_string.c ft_conv_c.c ft_conv_s.c ft_conv_p.c ft_conv_i.c \
	   ft_conv_u.c ft_conv_x.c ft_conv_n.c ft_conv_f.c ft_conv_e.c ft_conv_g.c \
	   ft_build_string.c ft_wchar_functions.c ft_float_functions.c \
	   ft_exponent_functions.c ft_zero_removal.c
OBJS = $(SRCS:.c=.o)
LIBDIR = libft/
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus test

all: $(NAME)

$(NAME): $(OBJS)
	cd $(LIBDIR) && make all
	mv $(LIBDIR)/libft.a libftprintf.a
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	gcc -c $? -o $@ -I. $(FLAGS)

clean:
	cd $(LIBDIR) && make clean
	rm -f $(OBJS)

fclean: clean
	cd $(LIBDIR) && make fclean
	rm -f $(NAME)
	rm -f $(TESTNAME)

re: fclean all

test: all
	gcc $(NAME) main.c -o $(TESTNAME) && ./$(TESTNAME)

bonus: $(NAME)
