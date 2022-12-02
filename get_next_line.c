/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:49:04 by amakhrou          #+#    #+#             */
/*   Updated: 2022/11/30 13:18:00 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*saved(char *line)
{
	char	*s;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	s = ft_substr(line, (i + 1), ft_strlen(line));
	free(line);
	line = NULL;
	return (s);
}

char	*lines(char **line)
{
	int	i;

	i = 0;
	if (!line[0][i])
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	return (ft_substr(*line, 0, (i + 1)));
}

char	*redline(int fd, char *line)
{
	char	*s;
	ssize_t	i;

	i = 3;
	s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (0);
	if (!line)
		line = ft_strdup("");
	while (!ft_strchr(line) && i != 0)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i < 0)
		{
			free(s);
			free(line);
			line = NULL;
			return (NULL);
		}
		s[i] = '\0';
		line = ft_strjoin(line, s);
	}
	free(s);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = redline(fd, line);
	if (line == NULL)
		return (NULL);
	s = lines(&line);
	if (s == NULL)
		return (NULL);
	line = saved(line);
	return (s);
}
