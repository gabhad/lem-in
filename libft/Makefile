# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 08:20:38 by ghaddad           #+#    #+#              #
#    Updated: 2018/06/14 09:11:13 by ghaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a

CC =			gcc
CFLAGS =		-Wall -Wextra -Werror -c

PRINTF_H =		-I includes/

SRC_PATH = 		srcs/
INCLUDES_PATH =	includes/
OBJ_PATH =		obj/

SRC_NAME =		ft_printf.c \
				bconvert.c \
				cconvert.c \
				convert_arguments.c \
				dconvert.c \
				ft_itoa_base.c \
				ft_lltoa_base.c \
				init_flags.c \
				oconvert.c \
				pconvert.c \
				percent_convert.c \
				precision_solver.c \
				read_flags.c \
				read_strings.c \
				reset_flags.c \
				sconvert.c \
				solver.c \
				uconvert.c \
				xconvert.c \
				wide_cconvert.c \
				wide_sconvert.c \
				width_parser.c \
				ft_bzero.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c\
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_strsplit_whitespaces.c \
				ft_itoa.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_strjoinfree.c \
				get_next_line.c


SRC =			$(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ =			$(patsubst %.c, $(OBJ_PATH)%.o, $(SRC_NAME))

all: $(NAME)

$(OBJ_PATH):	
				@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ_PATH) $(OBJ)
				@ar rc $(NAME) $(OBJ_PATH)*.o
				@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@$(CC) $(CFLAGS) $< -o $@ $(PRINTF_H) $(LIBFT_H)

clean:
				@rm -rf $(OBJ_PATH)

fclean:
				@rm -rf $(OBJ_PATH) $(NAME)

re: fclean all

.PHONY:			all clean fclean re
