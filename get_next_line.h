/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:55:28 by clundber          #+#    #+#             */
/*   Updated: 2023/11/30 15:42:30 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2, int rd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s); //is it needed?
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *str, size_t n);
char	*get_next_line(int fd);
int		linecheck(char *str);
char	*ft_reader(char *buffer, char *temp, int fd, int rd);

#endif
