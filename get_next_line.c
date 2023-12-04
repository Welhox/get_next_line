/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:43 by clundber          #+#    #+#             */
/*   Updated: 2023/12/04 14:48:26 by clundber         ###   ########.fr       */
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


char	*ft_reader(char *temp, int fd)
{
	char	*buffer;
	int		rd;
	char	*ptr;

	ptr = NULL;
	rd = 0;
	if (linecheck(temp) == 1)
		return (temp);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return(0);
	rd = read(fd, buffer, BUFFER_SIZE);
	buffer[rd] = '\0';
	if (rd < 0)
	{
		free (buffer);
		return (0);
	}
	if (rd == 0)
	{
		free(buffer);
		return(temp);
	}
	if (!temp)
	{
 		temp = ft_strdup(buffer);
		free(buffer);
	} 
 	else if (temp)
	{ 
		ptr = temp;
		temp = ft_strjoin(temp, buffer);
		free (buffer);
		free (ptr);
		if (linecheck(temp) == 1 || rd == 0)
			return (temp);
		else
			return (ft_reader(temp, fd));
	}
	return(ft_reader(temp, fd));
}

char *ft_rowmaker(char **temp, char *row)

{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if (!temp)
		return (0);
	while(*temp[i])
	{
		if(*temp[i] == '\n')
		{	
			row = ft_substr(*temp, 0, i+1);
			*ptr = **temp;
			*temp = ft_substr(*temp, i+1, (ft_strlen(*temp) - i+1));
			free (ptr);
			return (row);
		}
		else if (temp[i+1] == '\0')
		{	
			row = ft_strdup(*temp);
			*temp[0] = '\0';
			free(*temp);
			return(row);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)

{
	char 			*row;
	int				rd;
	static char		*temp;
	row = NULL;

	rd = 1;
	if (!fd || fd < 0 || fd >= 256 || BUFFER_SIZE <= 0)
		return(0);
	temp = ft_reader(temp, fd);
	printf("TEMP = %s\n", temp);

/* 	while (linecheck(temp) == 0 && rd > 0)
	{	
		if ((temp = ft_reader(temp, ptr, fd, &rd)) == 0)
			return (0);
	} */
	row = ft_rowmaker(&temp, row);
/* 	//printf("TEMP = %s\n", temp);
	if (rd <= 0 && !temp)
		return (0); */

	return (row);

}
/*
	Allowed is read, malloc & free
	read syntax = int read(int fileDescriptor, void *buffer, size_t bytesToRead)
*/