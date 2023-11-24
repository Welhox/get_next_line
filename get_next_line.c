/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:43 by clundber          #+#    #+#             */
/*   Updated: 2023/11/24 15:38:37 by clundber         ###   ########.fr       */
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
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*get_next_line(int fd)

{
	char 			*buffer;
	char 			*row;
	int				rd;
	static char		*temp;
	int				i;

	row = NULL;
	i = 0;
	rd = 1;
	if (!fd || fd <= 2 || fd >= 256 || BUFFER_SIZE <= 0)
		return(0);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return(0);
	//printf("2\n");
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		printf("2\n");
		//printf("%d\n", rd)
		if (rd <= 0 && !temp)
		{
			free(buffer);
			return (0);
		}
		//printf("2\n");
		if (temp && buffer[0])
		{	
			temp = ft_strjoin(temp, buffer);
			free (buffer);
		}
		else if (buffer[0])
			temp = ft_strdup(buffer);
		if (linecheck(temp) == 1)
			break;
	}
	//i = 0;
	printf("1\n");
	while(temp[i])
	{
		if(temp[i] == '\n')
		{	
			row = ft_substr(temp, 0, i+1);
			temp = ft_substr(temp, i+1, (ft_strlen(temp) - i));
			break;
		}
		else if (temp[i+1] == '\0') //&& !buffer[0])
		{	
			row = ft_strdup(temp);
			temp[0] = '\0';
			free(buffer);
			free(temp);
			return(row);
		}
		i++;
	}
	//row = ft_substr(temp, 0, i+1);
	//temp = ft_substr(temp, i+1, (ft_strlen(temp) - i));
	//printf("2\n");
	free(buffer);
	//if (!row)
	//	row = ft_strdup("");
	return (row);


}
/*
	Allowed is read, malloc & free
	read syntax = int read(int fileDescriptor, void *buffer, size_t bytesToRead)
*/