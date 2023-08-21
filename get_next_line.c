/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:47:55 by csilva-m          #+#    #+#             */
/*   Updated: 2023/08/21 16:35:31 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_next(int fd, char *buffer)
{
	char	*buff;
	int		byte_read;

	byte_read = 1;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (byte_read != 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buff);
			free(buffer);
			return (NULL);
		}
		buff[byte_read] = '\0';
		buffer = ft_strjoin(buffer, buff);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (buff);
}

// take a line for return
char	*ft_line(char *buffer)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

// delete line find
char	*ft_clean(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	buffer = ft_read_next(fd, buffer);
	line = ft_line(buffer);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	buffer = ft_clean(buffer);
	return (line);
}
