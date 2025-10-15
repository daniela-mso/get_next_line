/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:07:31 by danielad          #+#    #+#             */
/*   Updated: 2025/10/15 19:48:34 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char		*line;
	int			i;
	int			j;
	char		*temp;
	char		*read_data;
	ssize_t		n_bytes_read;

	static char	*g_string = NULL;

	line = NULL;
	i = 0;
	j = 0;
	if (fd < 0)
		return (NULL);
	if (g_string == NULL)
	{
		g_string = ft_strdup("");
		if (!g_string)
			return (NULL);
	}
	read_data = malloc(BUFFER_SIZE + 1);
	if (!read_data)
		return (NULL);
	n_bytes_read = read(fd, read_data, BUFFER_SIZE);
	while (n_bytes_read > 0)
	{
		read_data[n_bytes_read] = '\0';
		temp = ft_strjoin(g_string, read_data);
		if (!temp)
		{
			free(read_data);
			free(g_string);
			return (NULL);
		}
		free(g_string);
		g_string = temp;
		if (ft_strchr(read_data, '\n'))
			break ;
		n_bytes_read = read(fd, read_data, BUFFER_SIZE);
	}
	free(read_data);
	if (!g_string || *g_string == '\0')
	{
		free(g_string);
		g_string = NULL;
		return (NULL);
	}
	while (g_string[i] && g_string[i] != '\n')
		i++;
	if (g_string[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = g_string[j];
		j++;
	}
	line[j] = '\0';
	temp = ft_strdup(g_string + i);
	free(g_string);
	g_string = temp;
	return (line);
}


// Return value Read line: correct behavior
// NULL: there is nothing else to read, or an error
// occurred
// External functs. read, malloc, free
// Description Write a function that returns a line read from a
// file descriptor


