/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:43 by clundber          #+#    #+#             */
/*   Updated: 2023/11/17 15:41:25 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //delete
#include "get_next_line.h"

char	*get_next_line(int fd)

{
	static int	linebreak;
	char	*line;
	int		rd;
	int		i;

	char *buffer;
	buffer = calloc(42, 1);

	i = 0;
	rd = 0;
	rd = read(fd, buffer, 42); //should be sizeof(buffer)
	if (rd <= 0)
		return (0); //or something else
	printf("2\n");
	buffer[rd] = '\0';
	while ((buffer[i] != '\0' || buffer[i] != '\n') && i < sizeof(buffer))
	{
		i++;
		//if (buffer[i+1] == '\n')
			//i++;
	}
	printf("3\n");
	line = malloc(sizeof(char) * i +1);
	while (i > 0)
	{
		*line = *buffer;
		line++;
		buffer++;
		i--;
		if (i == 0)
			*line = '\0';
	}
	free (buffer);
	return (line);
}

/*
	Allowed is read, malloc & free
	read syntax = int read(int fileDescriptor, void *buffer, size_t bytesToRead)
*/