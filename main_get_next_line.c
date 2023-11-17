/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:37:37 by clundber          #+#    #+#             */
/*   Updated: 2023/11/17 15:05:36 by clundber         ###   ########.fr       */
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
	char *ptr;

	row = 0;
	fd = open("file_to_read.txt", O_RDONLY);
	if (fd == -1)
		printf("open failed");
	printf("%d\n", fd);
	
	//while (row < 5)
	//{
	*ptr = *get_next_line(fd);


	printf ("%d %s", row, ptr);
	row++;
	free (ptr);
	//}
	close (fd);
		if (fd < 0)
			printf("close failed");
	
}