# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 13:52:27 by jvivas-g          #+#    #+#              #
#    Updated: 2024/01/27 19:57:50 by jvivas-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES = \
		src/ft_pipex.c \
		src/ft_pipex_utils.c \

LIBFT = lib/libft.a

INCLUDE = inc/ft_pipex.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

%.o: %.c ${INCLUDE}
		@echo "Compiling\n"
		@${CC} ${CFLAGS} -c $< -o $@

OBJECTS = ${SOURCES:.c=.o} 

${NAME}: ${OBJECTS} ${LIBFT}
		@${CC} ${CFLAGS} ${OBJECTS} -L lib -lft -o ${NAME}
		@echo "Created $(NAME)\n"

all: ${NAME}

clean:
		@${RM} ${OBJECTS}
		@$(MAKE) -C lib clean
		@echo "All objects cleaned\n"

fclean: clean
		@${RM} ${NAME}
		@$(MAKE) -C lib fclean
		@echo "All executable cleaned\n"

re: fclean all

${LIBFT}:
	@$(MAKE) -C lib

.PHONY: all clean fclean re
