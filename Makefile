# Nom de l'executable
NAME := so_long

# Compilateur
CC := cc
# CC := gcc

# Options de compilation
CFLAGS := -Wall -Wextra -Werror -g
# CFLAGS := -Wall -Wextra -Werror -Iheaders/

#Liste des fichiers source.
SRCS := main.c	

# Options de la bibliotheque MiniLibX et des bibliotheques systeme
LIBRARY := -Lminilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz 
# LIBRARY := -L./minilibx -lmlx -lXext -lX11 -lm
OBJS = $(SRCS:.c=.o)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regle pour creer l'executable en liant les objets.
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)

# Regle pour nettoyer les fichiers objets.
clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

# # Regle pour reconstruire le projet (clean, puis all)
# fclean: clean
# 	@make clean -C minilibx
# 	@rm -rf $(OBJS)

re: fclean all
# re: author fclean all

# Declarer les regles comme des cibles .phony pour eviter des conflits avec
# des fichiers du meme nom.
.PHONY: all clean fclean re