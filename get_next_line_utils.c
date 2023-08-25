/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:27:46 by csilva-m          #+#    #+#             */
/*   Updated: 2023/08/25 15:47:13 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		dest_i;
	int		i;

	dest_i = 0;
	i = 0;
	if (s1 == NULL)
		s1 = ft_strdup("");
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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*chr;

	if (s == NULL)
		return (NULL);
	i = 0;
	chr = NULL;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			chr = (char *)&s[i];
			return (chr);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		chr = (char *)&s[i];
	}
	return (chr);
}

char	*ft_strdup(char *s)
{
	size_t	index;
	char	*new_string;

	new_string = malloc(ft_strlen(s) + 1);
	index = 0;
	if (new_string == NULL)
		return (NULL);
	while (s[index])
	{
		new_string[index] = s[index];
		index++;
	}
	new_string[index] = '\0';
	return (new_string);
}
