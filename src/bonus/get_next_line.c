/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:29:13 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/24 15:17:26 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > gnl_strlen(s))
		return (malloc(1));
	if (len > gnl_strlen(s + start))
		len = gnl_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*gnl_read_line(int fd, char *save, char *buffer)
{
	int		bytes_read;

	bytes_read = 1;
	while (!gnl_strchr(save, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(save);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		save = gnl_strjoin(save, buffer);
	}
	return (save);
}

char	*gnl_save_line(char *line)
{
	char	*next;
	int		len;

	len = 0;
	while (line[len] != '\0' && line[len] != '\n')
		len++;
	if (line[len] == 0 || line[1] == 0)
		return (NULL);
	next = gnl_substr(line, len + 1, gnl_strlen(line) - len);
	if (*next == 0)
	{
		free(next);
		next = NULL;
	}
	line[len + 1] = '\0';
	return (next);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*save;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(save);
		free(buffer);
		save = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = gnl_read_line(fd, save, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	save = gnl_save_line(line);
	return (line);
}
