# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 17:43:32 by ggualerz          #+#    #+#              #
#    Updated: 2023/06/17 17:27:42 by ggualerz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES  = 	main.c \
			exec/exec.c exec/exec_utils.c exec/exec_redir.c exec/exec_fd.c exec/exec_fork.c\
			sexy/sexy.c
			# parsing/parser.c parsing/line_splitter.c
NAME     = minishell
OBJECTS  = ${SOURCES:.c=.o}

LIBFT_PATH = ./libft
LIBFT      = $(LIBFT_PATH)/libft.a

CFLAGS     = -Wall -Wextra -Werror -g -fdiagnostics-color=always 
LDFLAGS    = -L${LIBFT_PATH} -lft -lreadline

READLINE_INSTALLED := $(shell brew list --formula | grep -q '^readline$$' && echo 1)

ifeq ($(READLINE_INSTALLED),1)
    # Readline is installed
    # Add necessary flags or commands here
else
    # Readline is not installed
    $(error "Readline is not installed. Please install it using Homebrew.")
endif

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
