/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:27:46 by csilva-m          #+#    #+#             */
/*   Updated: 2023/08/18 19:07:08 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (s1 == NULL)
		dest = ft_calloc(1, 1);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	dest_i = 0;
	i = 0;
	while (s1[i])
	{
		dest[dest_i] = s1[i];
		i++;
		dest_i++;
	}
	i = 0;
	while (s2[i])
	{
		dest[dest_i] = s2[i];
		i++;
		dest_i++;
	}
	dest[dest_i] = '\0';
	free(s1);
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
