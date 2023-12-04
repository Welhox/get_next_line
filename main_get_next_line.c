/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:37:37 by clundber          #+#    #+#             */
/*   Updated: 2023/12/04 14:24:46 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"


int	main(void)

{
	int	fd;
	int	row;
	//char *ptr;

	row = 0;
	fd = open("file_to_read.txt", O_RDONLY);
	//fd = open("file_to_read.txt", O_RDONLY);
	//printf ("%d\n", fd);
	if (fd == -1)
		printf("open failed");
	//printf("%d\n", fd);
	
	while (row < 10)
	{
	printf("%s", get_next_line(fd));
	//printf("and now i want the next line :\n");
	//printf("%s\n", get_next_line(fd));

	//printf ("%d %s", row, ptr);
	row++;
	//free (ptr);
	}
	close (fd);
		if (fd < 0)
			printf("close failed");
	
}