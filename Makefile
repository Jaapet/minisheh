# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 17:43:32 by ggualerz          #+#    #+#              #
#    Updated: 2023/07/11 22:17:31 by ndesprez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES  = 	main.c utils_main.c clean.c\
			parsing/env_utils.c parsing/line_splitter.c parsing/parser.c parsing/proc_utils.c parsing/token_utils.c parsing/tokenizer.c parsing/utils.c parsing/word_utils.c parsing/free_utils.c\
			exec/exec.c exec/exec_utils.c exec/exec_redir.c exec/exec_fd.c exec/exec_fork.c exec/exec_acess.c exec/exec_path.c\
			sexy/sexy.c\
			builtin/pwd.c builtin/cd.c builtin/echo.c builtin/env.c builtin/export.c builtin/utils.c builtin/unset.c builtin/exit.c\
			signals/signals.c

NAME     = minishell
OBJECTS  = ${SOURCES:.c=.o}

LIBFT_PATH = ./libft
LIBFT      = $(LIBFT_PATH)/libft.a

CFLAGS     = -Wall -Wextra -Werror -g -fdiagnostics-color=always 
LDFLAGS    = -L${LIBFT_PATH} -lft -lreadline -L ~/.brew/Cellar/readline/8.2.1/lib/ 

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

re: fclean all