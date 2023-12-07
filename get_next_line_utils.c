/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:54:17 by clundber          #+#    #+#             */
/*   Updated: 2023/12/07 19:46:20 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h> //delete

char	*ft_strdup(char *s)

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
	{
		s = NULL;
		return (0);
		//return(ft_free(&s));
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

size_t	ft_strlen(const char *s)

{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)

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
	{
		//ft_free(&s);
		//printf("123");
		return (0);
		//return (ft_free(&s));
	}
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
