# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:30:21 by ggualerz          #+#    #+#              #
#    Updated: 2023/04/20 06:37:34 by ggualerz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	= ft_atoi.c \
ft_tolower.c ft_toupper.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_isprint.c \
ft_memchr.c ft_memcpy.c ft_memmove.c ft_memcmp.c ft_memset.c \
ft_calloc.c ft_bzero.c \
ft_strlcpy.c ft_strnstr.c ft_strchr.c ft_strlen.c ft_strrchr.c ft_strlcat.c ft_strncmp.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_split.c ft_itoa.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
\
ft_itoa_sign.c ft_ptoa_h.c ft_itoa_h.c ft_uitoa.c ft_strjoin_free.c ft_atol.c \
\
ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_p.c ft_printf_s.c ft_printf_u.c ft_printf_utils.c ft_printf_x.c\
get_next_line.c get_next_line_utils.c
NAME	= libft.a
OBJECTS	=  ${SOURCES:.c=.o}

.c.o	:
		gcc -Wall -Wextra -Werror -I "includes" -c $< -o ${<:.c=.o}

${NAME} : ${OBJECTS}
		ar rc ${NAME} ${OBJECTS}

all : ${NAME}

clean :
		rm -f ${OBJECTS}

fclean : clean
		rm -f ${NAME}

re : fclean all
