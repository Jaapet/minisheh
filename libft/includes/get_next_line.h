/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:20:16 by ggualerz          #+#    #+#             */
/*   Updated: 2023/05/18 20:42:58 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

void	ft_clear_lst(t_list **lst);
void	ft_get_line(t_list *lst, char **line);
void	ft_lstaddback(t_list **lst, char *buffer, int red_bytes);
void	ft_read_to_lst(int fd, t_list **lst);
char	*get_next_line(int fd);

int		ft_search_nl(t_list *lst);
t_list	*ft_lstgetend(t_list *lst);
void	ft_makeline(char **line, t_list *lst);
void	ft_lstclearall(t_list *lst);
size_t	ft_strlen_gnl(const char *s);

#endif
