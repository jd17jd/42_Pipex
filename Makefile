# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 13:52:27 by jvivas-g          #+#    #+#              #
#    Updated: 2024/10/28 01:54:43 by jvivas-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# Colores
COLOR_RESET = "\033[0m"
COLOR_VERDE = "\033[32m"

# Lista de archivos fuente
SOURCES = src/ft_pipex_utils.c src/ft_pipex.c

# Lista de archivos objeto
OBJECTS = src/ft_pipex_utils.o src/ft_pipex.o

# Libreria
LIBFT = lib/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

# Regla principal
$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) -L lib -lft -o $(NAME)
	@echo $(COLOR_VERDE) "Created $(NAME)" $(COLOR_RESET)

src/ft_pipex_utils.o: src/ft_pipex_utils.c
	@echo "Compiling ft_pipex_utils.c"
	@$(CC) $(CFLAGS) -c src/ft_pipex_utils.c -o src/ft_pipex_utils.o

src/ft_pipex.o: src/ft_pipex.c
	@echo "Compiling ft_pipex.c"
	@$(CC) $(CFLAGS) -c src/ft_pipex.c -o src/ft_pipex.o


all: $(NAME)

# Limpiar archivos objeto
clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) -C lib clean
	@echo $(COLOR_VERDE) "All objects cleaned" $(COLOR_RESET)

# Limpiar todo
fclean: clean
	@$(RM)	$(NAME)
	@$(MAKE) -C lib fclean
	@echo $(COLOR_VERDE) "All executable cleaned" $(COLOR_RESET)

# Recompilar todo
re: fclean all

$(LIBFT):
	@$(MAKE) -C lib

.PHONY: all clean fclean re
