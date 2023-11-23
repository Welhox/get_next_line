/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welhox <welhox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:43 by clundber          #+#    #+#             */
/*   Updated: 2023/11/23 22:38:30 by welhox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //delete
#include "get_next_line.h"

char	*ft_strdup(const char *s)

{
	int		len;
	char	*dupe;
	int		i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	dupe = malloc ((len + 1) * sizeof(char));
	if (!dupe)
		return (0);
	while (len >= 0)
	{
		dupe[i] = s[i];
		i++;
		len--;
	}
	return (dupe);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	int		i;
	char	*substr;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) || len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && len > 0)
	{
		substr[i++] = s[start++];
		len--;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)

{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)

{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/* static t_list	*ft_lstlast(t_list *lst)

{
	t_list	*ptr;

	ptr = NULL;
	if (!lst)
		return (0);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
} */

/* static void	ft_lstadd_back(t_list **lst, t_list *new)

{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
	new->next = 0;
} */

char	*get_next_line(int fd)

{
	int	buf = 42; //should use buf_size instead
	char *buffer;
	buffer = calloc(42, 1);

	static char	**array;
	char 			*row;
	int				rd;
	char			*temp;
	int				i;

	i = 0;
	rd = 0;
	//printf("1\n");
	//if it is already found then :
	//else 
	rd = read(fd, buffer, buf); //should be sizeofbuffer
	if (rd <= 0 && !array)
		return (0);
	while (buffer[i] && i < buf)
	{
		i++;
		if (i == buf)
			buffer[i] = '\0';
	}
	printf("5\n");
 	if (array)
	{
		row = array[0];
		temp = ft_strjoin(row, buffer);
		//row = ft_strjoin(temp, buffer);
		//temp = ft_strdup(row);
	}	
	else
		temp = ft_strdup(buffer);
	printf("2\n");
	i = 0;
	while(temp[i] && temp[i] != '\n')
	{
		i++;
		if(temp[i] == '\n')
		{	
			row = ft_substr(temp, 0, i+1);
			temp = ft_substr(temp, i+1, (ft_strlen(temp) - i));
		}
		else if (temp[i] == '\0' && !buffer[0])
		{	
			//free (temp);
			free (buffer);
			free (array[0]);
			free (array);
			return(temp);
		}
	}	
	printf("3\n");
	array = malloc(sizeof(char*) * fd);
	array[0] = temp;
	//printf("the stored buffer is = %s \n", temp);
	free(buffer);
	//printf("4\n");
	//free (temp);
	return (row);


}
	//row = malloc(sizeof(char) * buf);





/* 	//i = 0;
	//i = line_break;
	rd = 0;
	while (j < buf)
	{
		i = 0;
		rd = read(fd, buffer, 1); //should be sizeof(buffer)
		if (rd <= 0)
			return (0); //or something else
		buffer[rd + 1] = '\0';
		*temp++ = buffer[i++];
		*temp = '\0'; 
		if (buf_check == 1)
			return (line_maker);
		j++;
	}	
	while ((buffer[i] != '\0' && buffer[i] != '\n') && i < rd)
	{
		i++;
		if (buffer[i] == '\n')
		{
			i++;
			break;
		}
	} */



/*
	Allowed is read, malloc & free
	read syntax = int read(int fileDescriptor, void *buffer, size_t bytesToRead)
*/