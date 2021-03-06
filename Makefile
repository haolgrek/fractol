# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rluder <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 13:41:47 by rluder            #+#    #+#              #
#    Updated: 2016/03/26 20:02:38 by rluder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJET_NAME = $(SRC_NAME:.c=.o)
	CC = gcc
	EXE = fractol
	LIBRARY = libfractol.a
	MAKELIB = make -C ./libft
	CLEANLIB = make clean -C ./libft
	FCLEANLIB = make fclean -C ./libft
	MAIN = main.o
	CFLAGS = -Werror -Wextra -Werror
	SRC_NAME = main.c algos.c algos_bonus.c mlx.c mlx2.c init.c

all : $(EXE)

$(EXE) : $(LIBRARY) $(MAIN)
		$(MAKELIB)
		$(CC) -o $(EXE) $(CFLAGS) $(MAIN) $(LIBRARY) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit

$(LIBRARY) : $(OBJET_NAME)
		ar -r $(LIBRARY) $(OBJET_NAME)

$(MAIN) : main.c
		$(CC) $(CFLAGS) -c $<

%.o : %.c
		$(CC) -c $(CFLAGS) $<

clean :
		rm -rf $(SRC_NAME:.c=.o) main.o
		$(CLEANLIB)

fclean : clean
		rm -rf $(EXE) $(LIBRARY)
		$(FCLEANLIB)

re : fclean all
