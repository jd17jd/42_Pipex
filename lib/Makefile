# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 18:38:00 by jvivas-g          #+#    #+#              #
#    Updated: 2024/01/28 01:19:17 by jvivas-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Colores
COLOR_RESET = "\033[0m"
COLOR_VERDE = "\033[32m"

# Directorios de origen
SRC = src
INC = inc

# Lista de archivos fuente
SOURCES := $(wildcard $(SRC)/*/*.c)

# Lista de archivos cabecera
INCLUDE := $(wildcard $(INC)/*.h)

CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# Creación de objetos
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

# Reglas de compilación
%.o: %.c
	@echo "Compiling $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Reglas principales
$(NAME): $(OBJECTS) $(INCLUDE)
	@ar rsc $(NAME) $(OBJECTS)
	@echo $(COLOR_VERDE) "Created $(NAME)" $(COLOR_RESET)

all: $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@echo $(COLOR_VERDE) "All objects cleaned" $(COLOR_RESET)

fclean: clean
	@$(RM)	$(NAME)
	@echo $(COLOR_VERDE) "All executable cleaned" $(COLOR_RESET)

re: fclean all

.PHONY: all clean fclean re
