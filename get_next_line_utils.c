/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:49:07 by amakhrou          #+#    #+#             */
/*   Updated: 2022/11/30 13:20:10 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l;
	char	*p;
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	x = 0;
	y = 0;
	l = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(l + 1);
	if (p == NULL)
		return (NULL);
	while (s1[x])
	{
		p[i++] = s1[x++];
	}
	while (s2[y])
	{
		p[i++] = s2[y++];
	}
	p[i] = '\0';
	free(s1);
	return (p);
}

char	*ft_strdup(char *s1)
{
	int		l;
	char	*p;
	int		i;

	i = 0;
	l = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	p = malloc(l + 1);
	if (p == NULL)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	l;
	char	*p;
	size_t	i;

	i = 0;
	l = ft_strlen(s);
	if (len > l)
		len = l;
	if (start > l)
		return (ft_strdup(""));
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
