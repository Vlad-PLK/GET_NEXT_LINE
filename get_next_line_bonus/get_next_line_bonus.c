/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:29:16 by vpolojie          #+#    #+#             */
/*   Updated: 2023/08/22 14:02:35 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(char *line, size_t n, size_t size)
{
	unsigned long	i;

	i = 0;
	line = malloc(n * size);
	while (i != (n * size))
	{
		line[i] = 0;
		i++;
	}
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{	
	char			*str;
	int				i;
	int				k;

	k = 0;
	str = malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		str[i] = s2[k];
		k++;
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_cut_line(char *line, char *buffer, int i)
{
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	ft_strcpy(buffer, line + i);
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char			*buffer[OPEN_MAX];
	char				*line;
	int					rd;
	int					i;

	rd = 1;
	line = NULL;
	i = 0;
	line = ft_calloc(line, 1, sizeof(char));
	if (!buffer[fd])
		buffer[fd] = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	line = ft_strjoin(line, buffer[fd]);
	while (ft_check(buffer[fd]) == 0 && rd > 0)
	{
		rd = read(fd, buffer[fd], BUFFER_SIZE);
		if ((rd == -1) || (rd == 0 && line && line[0] == '\0'))
		{
			free(line);
			free(buffer[fd]);
			return (NULL);
		}	
		buffer[fd][rd] = 0;
		line = ft_strjoin(line, buffer[fd]);
	}
	line = ft_cut_line(line, buffer[fd], i);
	return (line);
}
