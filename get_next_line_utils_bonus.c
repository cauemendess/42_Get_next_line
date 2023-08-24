/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:59:06 by csilva-m          #+#    #+#             */
/*   Updated: 2023/08/24 15:59:07 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
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
