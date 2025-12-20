/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:32:18 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/01 17:32:18 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 4024

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl_list
{
	char				*buffer;
	struct s_gnl_list	*next;
}				t_gnl_list;

void		polish_list(t_gnl_list **list);

char		*get_line(t_gnl_list *list);

void		list_append(t_gnl_list **list, char *buff);

void		creat_gnl_list(t_gnl_list **list, int fd);

char		*get_next_line(int fd);

t_gnl_list	*find_last_node(t_gnl_list *lst);

int			len_new_line(t_gnl_list *list);

int			find_new_line(t_gnl_list *list);

void		copy_str(t_gnl_list *list, char *str);

void		free_list(t_gnl_list **list, t_gnl_list *clean_node,
				char *buff);

#endif