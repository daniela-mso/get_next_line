/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:07:31 by danielad          #+#    #+#             */
/*   Updated: 2025/10/23 14:49:06 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_data(int fd)
{
	char	*was_read;
	ssize_t	b_read;

	if (was_read == NULL)
	{
		was_read = ft_strdup("");
		if (was_read == NULL)
			return (NULL);
	}
	was_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (was_read == NULL)
		return (NULL);
	b_read = read(fd, was_read, BUFFER_SIZE);

	
	
}

static char	*set_line(char *line_buffer)
{
	 
}

char	*get_next_line(int fd)
{
	if (fd < 0)
		return (NULL);
}















// TODO: test with BUFFER_SIZE of 1, test with BUFFER_SIZE of 2048, with BUFFER_SIZE of 1 million 
// make a script to test EVERY SINGLE file 
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
		if (g_string == NULL)
			return (NULL);
	}
	read_data = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read_data == NULL)
		return (NULL);
	// TODO: check if n_bytes_read is == -1 (then there is an error and NULL is returned)
	n_bytes_read = read(fd, read_data, BUFFER_SIZE);
	while (n_bytes_read > 0)
	{
		read_data[n_bytes_read] = '\0';
		temp = ft_strjoin(g_string, read_data);
		if (temp == NULL)
		{
			free(read_data);
			free(g_string);
			return (NULL);
		}
		free(g_string);
		g_string = temp;
		if (ft_strchr(read_data, '\n') != NULL)
			break ;
		n_bytes_read = read(fd, read_data, BUFFER_SIZE);
	}
	free(read_data);
	if (g_string == NULL || *g_string == '\0')
	{
		free(g_string);
		g_string = NULL;
		return (NULL);
	}
	while (g_string[i] != '\0' && g_string[i] != '\n')
		i++;
	if (g_string[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = g_string[j];
		j++;
	}
	line[j] = '\0';
	temp = ft_strdup(g_string + i);
	if (temp == NULL)
		return (NULL);
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


