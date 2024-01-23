# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 18:38:00 by jvivas-g          #+#    #+#              #
#    Updated: 2023/10/09 01:27:21 by jvivas-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = \
		ft_atoi.c ft_bzero.c ft_calloc.c \
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
		
BONUS = \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \

INCLUDE = libft.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

%.o: %.c ${INCLUDE}
		@echo "Compiling\n"
		@${CC} ${CFLAGS} -c $< -o $@
		
		
OBJECTS = ${SOURCES:.c=.o}
BONUS_OBJECTS = ${BONUS:.c=.o}


${NAME}: ${OBJECTS} $(INCLUDE)
		@ar -rsc ${NAME} ${OBJECTS}
		@echo "Created $(NAME)\n"
	
bonus: ${OBJECTS} ${BONUS_OBJECTS} $(INCLUDE)
		@ar -rsc $(NAME) $^
		@echo "Bonus compiled correctly $(NAME)\n"

all: ${NAME}

clean:
		@${RM} ${OBJECTS} ${BONUS_OBJECTS}
		@echo "All objects cleaned\n"

fclean: clean
		@${RM} ${NAME}
		@${RM} bonus
		@echo "All executable cleaned\n"

re: fclean all

.PHONY: all clean fclean re
