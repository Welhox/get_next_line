/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:43 by clundber          #+#    #+#             */
/*   Updated: 2023/12/01 14:27:26 by clundber         ###   ########.fr       */
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

char	*ft_reader(char *buffer, char *temp, int fd, int rd, char *ptr)
{
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
		{	
			free (buffer); //unessisary freeing occurs at the moment	
			return (0);
		}
		if (temp && buffer[0])
		{	
			ptr = temp;
			temp = ft_strjoin(temp, buffer, rd);
			free (ptr);
		}
		else if (buffer[0] && !temp)
		{
			//free (temp); //test
			temp = ft_strdup(buffer);
		}
		if (linecheck(temp) == 1)
		{
			free (buffer);
			return (temp);
		}
	}
	free(buffer);
	return (temp);

}

char	*get_next_line(int fd)

{
	char 			*buffer;
	char 			*row;
	int				rd;
	static char		*temp;
	int				i;
	char			*ptr;
	
	ptr = NULL;
	row = NULL;
	i = 0;
	rd = 1;
	if (!fd || fd <= 2/*ehka 0*/ || fd >= 256 || BUFFER_SIZE <= 0)
		return(0);
	buffer = ft_calloc(BUFFER_SIZE, 1);
	if (!buffer)
		return(0);
	//printf("1\n");
	if (linecheck(temp) == 0)
		temp = ft_reader(buffer, temp, fd, rd, ptr);
	else
		free(buffer);
	if (temp == 0)
		return (0);
	//printf("2\n");
	//printf("temp = %s\n", temp);

	while(temp[i])
	{
		if(temp[i] == '\n')
		{	
			row = ft_substr(temp, 0, i+1);
			ptr = temp;
			temp = ft_substr(temp, i+1, (ft_strlen(temp) - i));
			free (ptr);
			return (row);
		}
		else if (temp[i+1] == '\0') //&& !buffer[0])
		{	
			row = ft_substr(temp, 0, i+1);
			temp[0] = '\0';
			free(temp);
			return(row);
		}
		i++;
	}
	return (0);
	//row = ft_substr(temp, 0, i+1);
	//temp = ft_substr(temp, i+1, (ft_strlen(temp) - i));
	//printf("2\n");
	//if (!row)
	//	row = ft_strdup("");

}
/*
	Allowed is read, malloc & free
	read syntax = int read(int fileDescriptor, void *buffer, size_t bytesToRead)
*/