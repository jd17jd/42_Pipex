# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 18:38:00 by jvivas-g          #+#    #+#              #
#    Updated: 2024/10/07 20:29:44 by jvivas-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Colores
COLOR_RESET = "\033[0m"
COLOR_VERDE = "\033[32m"

# Lista de archivos fuente
SOURCES = src/char/ft_isalnum.c \
          src/char/ft_isalpha.c \
          src/char/ft_isascii.c \
          src/char/ft_isdigit.c \
          src/char/ft_isprint.c \
          src/char/ft_tolower.c \
          src/char/ft_toupper.c \
		  src/errors/ft_error.c \
		  src/errors/ft_perror.c \
          src/fd/ft_putchar_fd.c \
          src/fd/ft_putendl_fd.c \
          src/fd/ft_putnbr_fd.c \
          src/fd/ft_putstr_fd.c \
		  src/gnl/get_next_line_bonus.c \
		  src/gnl/get_next_line_utils_bonus.c \
		  src/gnl/get_next_line_utils.c \
		  src/gnl/get_next_line.c \
          src/lists/ft_lstadd_back.c \
          src/lists/ft_lstadd_front.c \
          src/lists/ft_lstclear.c \
          src/lists/ft_lstdelone.c \
          src/lists/ft_lstiter.c \
          src/lists/ft_lstlast.c \
          src/lists/ft_lstmap.c \
          src/lists/ft_lstnew.c \
          src/lists/ft_lstsize.c \
		  src/matrix/ft_dup_matrix.c \
		  src/matrix/ft_free_matrix.c \
          src/mem/ft_bzero.c \
          src/mem/ft_calloc.c \
          src/mem/ft_memchr.c \
          src/mem/ft_memcmp.c \
          src/mem/ft_memcpy.c \
          src/mem/ft_memmove.c \
          src/mem/ft_memset.c \
		  src/printf/ft_printf_utils.c \
		  src/printf/ft_printf.c \
          src/str/ft_split.c \
          src/str/ft_strchr.c \
          src/str/ft_strdup.c \
          src/str/ft_striteri.c \
          src/str/ft_strjoin.c \
          src/str/ft_strlcat.c \
          src/str/ft_strlcpy.c \
          src/str/ft_strlen.c \
          src/str/ft_strmapi.c \
          src/str/ft_strncmp.c \
          src/str/ft_strnstr.c \
          src/str/ft_strrchr.c \
          src/str/ft_strtrim.c \
          src/str/ft_substr.c \
          src/str-nbr/ft_atoi.c \
          src/str-nbr/ft_itoa.c

# Lista de archivos objeto
OBJECTS = src/char/ft_isalnum.o \
          src/char/ft_isalpha.o \
          src/char/ft_isascii.o \
          src/char/ft_isdigit.o \
          src/char/ft_isprint.o \
          src/char/ft_tolower.o \
          src/char/ft_toupper.o \
		  src/errors/ft_error.o \
		  src/errors/ft_perror.o \
          src/fd/ft_putchar_fd.o \
          src/fd/ft_putendl_fd.o \
          src/fd/ft_putnbr_fd.o \
          src/fd/ft_putstr_fd.o \
		  src/gnl/get_next_line_bonus.o \
		  src/gnl/get_next_line_utils_bonus.o \
		  src/gnl/get_next_line_utils.o \
		  src/gnl/get_next_line.o \
          src/lists/ft_lstadd_back.o \
          src/lists/ft_lstadd_front.o \
          src/lists/ft_lstclear.o \
          src/lists/ft_lstdelone.o \
          src/lists/ft_lstiter.o \
          src/lists/ft_lstlast.o \
          src/lists/ft_lstmap.o \
          src/lists/ft_lstnew.o \
          src/lists/ft_lstsize.o \
		  src/matrix/ft_dup_matrix.o \
		  src/matrix/ft_free_matrix.o \
          src/mem/ft_bzero.o \
          src/mem/ft_calloc.o \
          src/mem/ft_memchr.o \
          src/mem/ft_memcmp.o \
          src/mem/ft_memcpy.o \
          src/mem/ft_memmove.o \
          src/mem/ft_memset.o \
		  src/printf/ft_printf_utils.o \
		  src/printf/ft_printf.o \
          src/str/ft_split.o \
          src/str/ft_strchr.o \
          src/str/ft_strdup.o \
          src/str/ft_striteri.o \
          src/str/ft_strjoin.o \
          src/str/ft_strlcat.o \
          src/str/ft_strlcpy.o \
          src/str/ft_strlen.o \
          src/str/ft_strmapi.o \
          src/str/ft_strncmp.o \
          src/str/ft_strnstr.o \
          src/str/ft_strrchr.o \
          src/str/ft_strtrim.o \
          src/str/ft_substr.o \
          src/str-nbr/ft_atoi.o \
          src/str-nbr/ft_itoa.o

# Librería
LIBFT = lib/libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# Regla principal
$(NAME): $(OBJECTS)
	@ar rsc $(NAME) $(OBJECTS)
	@echo $(COLOR_VERDE) "Created $(NAME)" $(COLOR_RESET)

# Reglas de compilación para cada archivo objeto
src/char/ft_isalnum.o: src/char/ft_isalnum.c
	@echo "Compiling ft_isalnum.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/char/ft_isalpha.o: src/char/ft_isalpha.c
	@echo "Compiling ft_isalpha.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/char/ft_isascii.o: src/char/ft_isascii.c
	@echo "Compiling ft_isascii.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/char/ft_isdigit.o: src/char/ft_isdigit.c
	@echo "Compiling ft_isdigit.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/char/ft_isprint.o: src/char/ft_isprint.c
	@echo "Compiling ft_isprint.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/char/ft_tolower.o: src/char/ft_tolower.c
	@echo "Compiling ft_tolower.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/char/ft_toupper.o: src/char/ft_toupper.c
	@echo "Compiling ft_toupper.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/errors/ft_error.o: src/errors/ft_error.c
	@echo "Compiling ft_error.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/errors/ft_perror.o: src/errors/ft_perror.c
	@echo "Compiling ft_perror.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/fd/ft_putchar_fd.o: src/fd/ft_putchar_fd.c
	@echo "Compiling ft_putchar_fd.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/fd/ft_putendl_fd.o: src/fd/ft_putendl_fd.c
	@echo "Compiling ft_putendl_fd.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/fd/ft_putnbr_fd.o: src/fd/ft_putnbr_fd.c
	@echo "Compiling ft_putnbr_fd.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/fd/ft_putstr_fd.o: src/fd/ft_putstr_fd.c
	@echo "Compiling ft_putstr_fd.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/gnl/get_next_line_bonus.o: src/gnl/get_next_line_bonus.c
	@echo "Compiling get_next_line_bonus.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/gnl/get_next_line_utils_bonus.o: src/gnl/get_next_line_utils_bonus.c
	@echo "Compiling get_next_line_utils_bonus.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/gnl/get_next_line_utils.o: src/gnl/get_next_line_utils.c
	@echo "Compiling get_next_line_utils.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/gnl/get_next_line.o: src/gnl/get_next_line.c
	@echo "Compiling get_next_line.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/lists/ft_lstadd_back.o: src/lists/ft_lstadd_back.c
	@echo "Compiling ft_lstadd_back.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/lists/ft_lstadd_front.o: src/lists/ft_lstadd_front.c
	@echo "Compiling ft_lstadd_front.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/lists/ft_lstclear.o: src/lists/ft_lstclear.c
	@echo "Compiling ft_lstclear.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/lists/ft_lstdelone.o: src/lists/ft_lstdelone.c
	@echo "Compiling ft_lstdelone.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/lists/ft_lstiter.o: src/lists/ft_lstiter.c
	@echo "Compiling ft_lstiter.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/lists/ft_lstlast.o: src/lists/ft_lstlast.c
	@echo "Compiling ft_lstlast.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/lists/ft_lstmap.o: src/lists/ft_lstmap.c
	@echo "Compiling ft_lstmap.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/lists/ft_lstnew.o: src/lists/ft_lstnew.c
	@echo "Compiling ft_lstnew.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/lists/ft_lstsize.o: src/lists/ft_lstsize.c
	@echo "Compiling ft_lstsize.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/matrix/ft_dup_matrix.o: src/matrix/ft_dup_matrix.c
	@echo "Compiling ft_dup_matrix.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/matrix/ft_free_matrix.o: src/matrix/ft_free_matrix.c
	@echo "Compiling ft_free_matrix.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/mem/ft_bzero.o: src/mem/ft_bzero.c
	@echo "Compiling ft_bzero.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/mem/ft_calloc.o: src/mem/ft_calloc.c
	@echo "Compiling ft_calloc.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/mem/ft_memchr.o: src/mem/ft_memchr.c
	@echo "Compiling ft_memchr.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/mem/ft_memcmp.o: src/mem/ft_memcmp.c
	@echo "Compiling ft_memcmp.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/mem/ft_memcpy.o: src/mem/ft_memcpy.c
	@echo "Compiling ft_memcpy.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/mem/ft_memmove.o: src/mem/ft_memmove.c
	@echo "Compiling ft_memmove.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/mem/ft_memset.o: src/mem/ft_memset.c
	@echo "Compiling ft_memset.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/printf/ft_printf_utils.o: src/printf/ft_printf_utils.c
	@echo "Compiling ft_printf_utils.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/printf/ft_printf.o: src/printf/ft_printf.c
	@echo "Compiling ft_printf.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_split.o: src/str/ft_split.c
	@echo "Compiling ft_split.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_strchr.o: src/str/ft_strchr.c
	@echo "Compiling ft_strchr.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_strdup.o: src/str/ft_strdup.c
	@echo "Compiling ft_strdup.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_striteri.o: src/str/ft_striteri.c
	@echo "Compiling ft_striteri.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_strjoin.o: src/str/ft_strjoin.c
	@echo "Compiling ft_strjoin.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_strlcat.o: src/str/ft_strlcat.c
	@echo "Compiling ft_strlcat.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_strlcpy.o: src/str/ft_strlcpy.c
	@echo "Compiling ft_strlcpy.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_strlen.o: src/str/ft_strlen.c
	@echo "Compiling ft_strlen.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_strmapi.o: src/str/ft_strmapi.c
	@echo "Compiling ft_strmapi.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_strncmp.o: src/str/ft_strncmp.c
	@echo "Compiling ft_strncmp.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_strnstr.o: src/str/ft_strnstr.c
	@echo "Compiling ft_strnstr.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_strrchr.o: src/str/ft_strrchr.c
	@echo "Compiling ft_strrchr.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_strtrim.o: src/str/ft_strtrim.c
	@echo "Compiling ft_strtrim.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str/ft_substr.o: src/str/ft_substr.c
	@echo "Compiling ft_substr.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str-nbr/ft_atoi.o: src/str-nbr/ft_atoi.c
	@echo "Compiling ft_atoi.c"
	@$(CC) $(CFLAGS) -c $< -o $@

src/str-nbr/ft_itoa.o: src/str-nbr/ft_itoa.c
	@echo "Compiling ft_itoa.c"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

# Limpiar archivos objeto
clean:
	@$(RM) $(OBJECTS)
	@echo $(COLOR_VERDE) "All objects cleaned" $(COLOR_RESET)

# Limpiar todo
fclean: clean
	@$(RM) $(NAME)
	@echo $(COLOR_VERDE) "All executable cleaned" $(COLOR_RESET)

# Recompilar todo
re: fclean all

.PHONY: all clean fclean re

