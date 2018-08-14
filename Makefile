# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 16:11:01 by ghaddad           #+#    #+#              #
#    Updated: 2018/07/16 16:11:15 by ghaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			lem-in

CC =			gcc
CFLAGS =		-c -Wall -Wextra -Werror

SRC_PATH =		srcs/
INCLUDES_PATH =	includes/
OBJ_PATH =		obj/
LIBFT_PATH =	libft/
LIBFT_A =		libft.a

SRC_NAME =		check_data.c \
				clear_fourm.c \
				create_anthill.c \
				create_room.c \
				del_table.c \
				direct_ants.c \
				error.c \
				fill_struct.c \
				generate_ants.c \
				get_tubes.c \
				getdata.c \
				intmaxatoi.c \
				joinfree_space.c \
				lemin.c \
				lemin_solver.c \
				set_path.c \
				shortest_path.c

OBJ_NAME =		$(SRC_NAME:.c=.o)

SRC = 			$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = 			$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: comp_libft $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
				$(CC) -o $@ $(OBJ) $(LIBFT_PATH)$(LIBFT_A)

$(OBJ_PATH):
				mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				$(CC) $(CFLAGS) -c -o $@ $< -I$(INCLUDES_PATH)

comp_libft:
				make -C $(LIBFT_PATH)

clean:
				rm -rf $(OBJ_PATH)
				make -C $(LIBFT_PATH) clean

fclean: clean
				rm $(NAME)
				rm $(LIBFT_PATH)$(LIBFT_A)

re: fclean all

.PHONY: all, clean, fclean, re