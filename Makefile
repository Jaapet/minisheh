# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 17:43:32 by ggualerz          #+#    #+#              #
#    Updated: 2023/07/09 20:28:01 by ndesprez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES  = 	parsing/parser.c parsing/proc_utils.c parsing/line_splitter.c parsing/word_utils.c parsing/env_utils.c parsing/tokenizer.c parsing/token_utils.c parsing/utils.c
NAME     = minishell
OBJECTS  = ${SOURCES:.c=.o}

LIBFT_PATH = ./libft
LIBFT      = $(LIBFT_PATH)/libft.a

CFLAGS     = -Wall -Wextra -Werror -g -fdiagnostics-color=always
LDFLAGS    = -L${LIBFT_PATH} -lft -lreadline

# READLINE_INSTALLED := $(shell brew list --formula | grep -q '^readline$$' && echo 1)

# ifeq ($(READLINE_INSTALLED),1)
#     # Readline is installed
#     # Add necessary flags or commands here
# else
#     # Readline is not installed
#     $(error "Readline is not installed. Please install it using Homebrew.")
# endif

.c.o:
	gcc $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(LIBFT) ${OBJECTS}
	gcc $(CFLAGS) $(LDFLAGS) -o $(NAME) ${OBJECTS}

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -f ${OBJECTS}

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all