/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:58:02 by csilva-m          #+#    #+#             */
/*   Updated: 2023/08/18 18:48:00 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);


#endif
