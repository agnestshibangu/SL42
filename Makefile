# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeza <jeza@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 16:48:24 by jeguerin          #+#    #+#              #
#    Updated: 2024/02/08 15:33:02 by jeza             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'executable
NAME := so_long

# Compilateur
CC := gcc

# Options de compilation
CFLAGS := -Wall -Wextra -Werror -Iheaders/

#Liste des fichiers source.
SRCS := mainavanced.c	

# Options de la bibliotheque MiniLibX et des bibliotheques systeme
LIBRARY := -Lminilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz 
OBJS = $(SRCS:.c=.o)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regle pour creer l'executable en liant les objets.
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)

# Regle pour nettoyer les fichiers objets.
clean:
	$(RM) $(OBJS) 
	make clean 

# Regle pour reconstruire le projet (clean, puis all)
re: author fclean all

# Declarer les regles comme des cibles .phony pour eviter des conflits avec
# des fichiers du meme nom.
.PHONY: all clean fclean re