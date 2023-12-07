/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:43 by clundber          #+#    #+#             */
/*   Updated: 2023/12/07 19:45:34 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //delete
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

	ptr = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(&temp));
	rd = read(fd, buffer, BUFFER_SIZE);
	if (rd == 0)
	{
		free (buffer);
		return (temp);
	}
	if (rd < 0)
	{
		free (buffer);
		//free (temp);
		return (ft_free(&temp));
	}
	buffer[rd] = '\0';
	if (!temp)
	{
		temp = ft_substr(buffer, 0, rd);
		free (buffer);
	}
	else
	{
		ptr = temp;
		temp = ft_strjoin(ptr, buffer);
		free (buffer);
		free (ptr);
	}
	if (!temp)
		return(0);
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
			return (row);
		}
		else if (temp[i +1] == '\0')
		{
			row = ft_strdup(temp);
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
	if (fd < 0 || fd >= 256 || BUFFER_SIZE <= 0)
		return (0);
	temp = ft_reader(temp, fd);
	//{
	//	return(0);
		//printf("888");
		//return(ft_free(&temp));
	//}
	//printf("456");
   	if (!temp)
		return (0);
	//printf("789");	   
	row = ft_rowmaker(temp, row);
	if (!row)
		return (0);
	if (linecheck(row) == 1 && (ft_strlen(row) < ft_strlen(temp)))
	{
		ptr = temp;
		temp = ft_substr(temp, ft_strlen(row), ft_strlen(temp) - ft_strlen(row));
		ft_free(&ptr);
		return (row);
	}
	ft_free(&temp);
/* 	free(temp);
	temp = NULL; */
	return (row);
}
/*
	Allowed is read, malloc & free
	read syntax = int read(int fileDescriptor, void *buffer, size_t bytesToRead)
*/