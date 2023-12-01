/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:54:17 by clundber          #+#    #+#             */
/*   Updated: 2023/12/01 12:23:27 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)

{
	int		len;
	char	*dupe;
	int		i;

	i = 0;
	len = 0;
	while (s[len] && len < BUFFER_SIZE)
		len++;
	dupe = malloc ((len + 1) * sizeof(char));
	if (!dupe)
	{
		//free (dupe);
		return (0);
	}
	while (len > 0)
	{
		dupe[i] = s[i];
		i++;
		len--;
	}
	dupe[i] = '\0';
	return (dupe);
}

void	*ft_calloc(size_t nmemb, size_t size)

{
	void	*ptr;
	size_t	maxsize;

	maxsize = 0 - 1;
	if (nmemb != 0 && size != 0)
	{
		if ((maxsize / nmemb) < size)
			return (0);
	}
	if (nmemb * size > 2147483424)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

void	ft_bzero(void *str, size_t n)

{
	unsigned char	*ptr;

	ptr = str;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
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

char	*ft_strjoin(char const *s1, char const *s2, int rd)

{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc ((ft_strlen(s1) + rd + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && j < rd)
		str[i++] = s2[j++];
	str[i] = '\0';
	//free (s1);
	//free ((void*)s2);
	return (str);
}