/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:55:28 by clundber          #+#    #+#             */
/*   Updated: 2023/12/08 14:08:30 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>

char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_len(const char *s);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);
int		linecheck(char *str);
char	*ft_reader(char *temp, int fd);
char	*ft_rowmaker(char *temp, char *row);
char	*ft_free(char **str);
char	*rd_check(char *buffer, char *temp, int rd);

#endif
