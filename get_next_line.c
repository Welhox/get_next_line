/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:43 by clundber          #+#    #+#             */
/*   Updated: 2023/12/08 12:52:39 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	linecheck(char *str)

{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_reader(char *temp, int fd)
{
	char	*buffer;
	char	*ptr;
	int		rd;

	ptr = temp;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(&temp));
	rd = read(fd, buffer, BUFFER_SIZE);
	if (rd <= 0)
		return (rd_check(buffer, temp, rd));
	buffer[rd] = '\0';
	if (!temp)
		temp = ft_substr(buffer, 0, rd);
	else
	{
		temp = ft_strjoin(ptr, buffer);
		free (ptr);
	}
	free (buffer);
	if (!temp)
		return (0);
	if (linecheck(temp) == 0)
		temp = ft_reader(temp, fd);
	return (temp);
}

char	*ft_rowmaker(char *temp, char *row)

{
	int		i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			row = ft_substr(temp, 0, i +1);
			if (!row)
				return (0);
			return (row);
		}
		else if (temp[i +1] == '\0')
		{
			row = ft_strdup(temp);
			if (!row)
				return (0);
			return (row);
		}
		i++;
	}
	return (0);
}

char	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

char	*get_next_line(int fd)

{
	char		*row;
	static char	*temp;
	char		*ptr;

	row = NULL;
	ptr = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = ft_reader(temp, fd);
	if (!temp)
		return (0);
	row = ft_rowmaker(temp, row);
	if (!row)
		return (ft_free(&temp));
	if (linecheck(row) == 1 && (ft_strlen(row) < ft_strlen(temp)))
	{
		ptr = temp;
		temp = ft_substr(ptr, ft_strlen(row), ft_strlen(temp) - ft_strlen(row));
		ft_free(&ptr);
		return (row);
	}
	ft_free(&temp);
	return (row);
}
