#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	mult;
	char	*tmp;
	size_t	i;

	mult = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (mult > __INT_MAX__ || mult / nmemb != size)
		return (NULL);
	ptr = (void *)malloc(mult);
	if (ptr == NULL)
		return (NULL);
	tmp = (char *)ptr;
	i = 0;
	while (i < mult)
	{
		tmp[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		dest_i;
	int		i;

	dest_i = 0;
	i = 0;
	if (!s1)
		dest = ft_calloc(1, 1);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1 && s1[i])
		dest[dest_i++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[dest_i++] = s2[i++];
	dest[dest_i] = '\0';
	if (s1)
		free(s1);
	return (dest);
}

static char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != c && str[i] != '\0')
	{
		str++;
	}
	return (str);
}

char	*ft_read_next(int fd, char *buffer)
{
	char	*buff;
	int		byte_read;

	byte_read = 1;
	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
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

int	main(void)
{
	char *file_name;
	int fd;
	file_name = "teste.txt";

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);

	while (1)
	{
		char *line;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		usleep(5000);
		free(line);
	}
	close(fd);
}