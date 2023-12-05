/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:43 by clundber          #+#    #+#             */
/*   Updated: 2023/12/05 15:31:30 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //delete
#include "get_next_line.h"

size_t	ft_strlen(const char *s)

{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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


char	*ft_reader(char *temp, int fd, int *rd)
{
	char	*buffer;
	char	*ptr;

	ptr = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return(0);
	*rd = read(fd, buffer, BUFFER_SIZE);
	if (*rd <= 0)
	{
		free (buffer);
		if (*rd == 0 && temp)
			return (temp);
		free(temp);
		return (0);
	}
	buffer[*rd] = '\0';
	if (!temp)
	{
 		temp = ft_strdup(buffer);
		free (buffer);
	} 
 	else if (temp && (linecheck(temp) == 0))
	{ 
		ptr = temp;
		temp = ft_strjoin(temp, buffer);
		free (buffer);
		free (ptr);
	}
	return(temp);
}

char	*ft_rowmaker(char *temp, char *row)

{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if (!temp)
		return (0);
	while(temp[i])
	{
		if(temp[i] == '\n')
		{	
			row = ft_substr(temp, 0, i+1);
			return (row);
		}
		else if (temp[i+1] == '\0')
		{	
			row = ft_strdup(temp);
			return(row);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)

{
	char 			*row;
	int				check;
	int				*rd;
	static char		*temp;
	char			*ptr;

	row = NULL;
	ptr = NULL;
	check = 1;
	rd = &check;
	if (!fd || fd < 0 || fd >= 256 || BUFFER_SIZE <= 0)
		return(0);
	printf("11111\n");
	while (check > 0 && (linecheck(temp) != 1))
		if ((temp = ft_reader(temp, fd, rd)) == 0)
		{
			printf("33333\n");
			if (temp)
			//	free(temp);
			return(0);
		}
	printf("222222\n");
	if ((row = ft_rowmaker(temp, row)) == 0)
		return (0);
	if (linecheck(row) == 1)
	{
		ptr = temp;
		temp = ft_substr(temp, ft_strlen(row), ft_strlen(temp) - ft_strlen(row));
		free(ptr);
		return(row);
	}
	else if (row)
	{
		free(temp);
		return (row);
	}
	return (0);
}
/*
	Allowed is read, malloc & free
	read syntax = int read(int fileDescriptor, void *buffer, size_t bytesToRead)
*/