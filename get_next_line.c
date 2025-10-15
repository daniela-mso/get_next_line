/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:07:31 by danielad          #+#    #+#             */
/*   Updated: 2025/10/15 19:05:09 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


static char	*g_string = NULL;

static int string()
{
	if (g_string == NULL)
	{
		g_string = malloc(1);
		if (!g_string)
			return (-1);
		g_string[0] = '\0';
	}
	return (0);
}



static char	*read_line(int fd)
{
	char		*read_data;
	ssize_t		n_bytes_read;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (string() != 0)
		return NULL;
	read_data = malloc(BUFFER_SIZE + 1);
	if (!read_data)
		return (NULL);
	n_bytes_read = read(fd, read_data, BUFFER_SIZE);
	while (n_bytes_read > 0)
	{
		read_data[n_bytes_read] = '\0';
		temp = ft_strjoin(g_string, read_data);
		if (temp == NULL)
		{
			free(read_data);
			return (NULL);
		}
		free(g_string);
		g_string = temp;
		if (ft_strchr(read_data, '\n'))
			break ;
		n_bytes_read = read(fd, read_data, BUFFER_SIZE);
	}
	free(read_data);
	return (g_string);
}


char	*get_next_line(int fd)
{
	char		*line;
	int			i;
	int			j;
	char		*temp;
	// static char	*g_string = NULL;

	// g_string = NULL;
	i = 0;
	j = 0;
	if (!g_string || *g_string == '\0')
	{
		free(g_string);
		g_string = NULL;
		return (NULL);
	}
	else
		g_string = read_line(fd);
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










// static char	*g_string = NULL;

// static char	*read_line(int fd)
// {
// 	char	*read_data;
// 	ssize_t	n_bytes_read;
// 	char	*temp_strings;

// 	if (fd < 0 || BUFFER_SIZE <= 0){
// 		printf("fd (%d) BUFFER_SIZE (%d).\n", fd, BUFFER_SIZE);
// 		return (NULL);
// 	}
// 	if (!g_string)
// 	{
// 		g_string = malloc(1);
// 		if (!g_string)
// 			return (NULL);
// 		g_string[0] = '\0';
// 	}
// 	read_data = malloc(BUFFER_SIZE + 1);
// 	if (read_data == NULL)
//  		return (NULL);
// 	n_bytes_read = read(fd, read_data, BUFFER_SIZE);
// 	printf("read_line: Read data: '%s'\n", read_data);
// 	while (n_bytes_read > 0)
// 	{
// 		read_data[n_bytes_read] = '\0';
// 		temp_strings = ft_strjoin(g_string, read_data);
// 		free(g_string);
// 		g_string = temp_strings;
// 		if (ft_strchr(read_data, '\n'))
// 			break ;
// 		n_bytes_read = read(fd, read_data, BUFFER_SIZE);
// 	}
// 	free(read_data);
// 	return (g_string);
// }

// char	*get_next_line(int fd)
// {
// 	char	*line_to_return;
// 	int		i;
// 	int		index;
// 	char	*temp_strings;

// 	i = 0;
// 	g_string = read_line(fd);
// 	if (!g_string || *g_string == '\0')
// 		return (NULL);
// 	while (g_string[i] && g_string[i] != '\n')
// 		i++;
// 	if (g_string[i] == '\n')
// 		i++;
// 	line_to_return = malloc(i + 1);
// 	if (line_to_return == NULL)
// 		return (NULL);
// 	index = -1;
// 	while (++index < i)
// 		line_to_return[index] = g_string[index];
// 	line_to_return[i] = '\0';
// 	temp_strings = ft_strjoin(g_string + i, "");
// 	free(g_string);
// 	g_string = temp_strings;
// 	return (line_to_return);
// }






///////////////////////////////////////

// static char	*read_line(int fd)
// {
// 	char		*read_data;
// 	ssize_t		n_bytes_read;
// 	char		*temp;
// 	static char	*g_string;

// 	g_string = NULL;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (g_string == NULL)
// 	{
// 		g_string = malloc(1);
// 		if (!g_string)
// 			return (NULL);
// 		g_string[0] = '\0';
// 	}
// 	read_data = malloc(BUFFER_SIZE + 1);
// 	if (!read_data)
// 		return (NULL);
// 	n_bytes_read = read(fd, read_data, BUFFER_SIZE);
// 	while (n_bytes_read > 0)
// 	{
// 		read_data[n_bytes_read] = '\0';
// 		temp = ft_strjoin(g_string, read_data);
// 		if (!temp)
// 		{
// 			free(read_data);
// 			free(g_string);
// 			return (NULL);
// 		}
// 		free(g_string);
// 		g_string = temp;
// 		if (ft_strchr(read_data, '\n'))
// 			break ;
// 		n_bytes_read = read(fd, read_data, BUFFER_SIZE);
// 	}
// 	free(read_data);
// 	return (g_string);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	int			i;
// 	int			j;
// 	char		*temp;
// 	static char	*g_string;

// 	g_string = NULL;
// 	i = 0;
// 	j = 0;
// 	g_string = read_line(fd);
// 	if (!g_string || *g_string == '\0')
// 	{
// 		free(g_string);
// 		g_string = NULL;
// 		return (NULL);
// 	}
// 	while (g_string[i] && g_string[i] != '\n')
// 		i++;
// 	if (g_string[i] == '\n')
// 		i++;
// 	line = malloc(i + 1);
// 	if (line == NULL)
// 		return (NULL);
// 	while (j < i)
// 	{
// 		line[j] = g_string[j];
// 		j++;
// 	}
// 	line[j] = '\0';
// 	temp = ft_strdup(g_string + i);
// 	free(g_string);
// 	g_string = temp;
// 	return (line);
// }



///////////////////////////////////////////


// char	*get_next_line(int fd)
// {
// 	static char	*string = NULL;
// 	char	*read_data;				
// 	char	*line_to_return;           
// 	char	*temp_strings;
// 	ssize_t	n_bytes_read;

// 	if (string == NULL) {
// 		string = malloc(1);
// 		*string = '\0';
// 	}
// 	if (fd < 0 )				
// 		return (NULL);
// 	read_data = malloc(BUFFER_SIZE + 1);
// 	if (!read_data)
// 		return (NULL); 
// 	while ((n_bytes_read = read(fd, read_data, BUFFER_SIZE)) > 0)
// 	{
// 		read_data[n_bytes_read] = '\0';
// 		temp_strings = ft_strjoin(string, read_data);
// 		free(string);
// 		string = temp_strings;
// 		if (ft_strchr(read_data, '\n'))     
// 			break;	
// 	}
// 	free(read_data);
// 	if (!string || *string == '\0')
// 		return NULL;
// 	int i = 0;
// 	while (string[i] && string[i] != '\n')
// 		i++;
// 	if (string[i] == '\n')
// 		i++;
// 	line_to_return = malloc(i + 1);                    
// 	if (!line_to_return)
// 		return NULL;
// 	int	index = 0;
// 	while (index < i)
// 	{
// 		line_to_return[index] = string[index];
// 		index++;
// 	}
// 	line_to_return[i] = '\0';
// 	temp_strings = ft_strjoin(string + i, "");
// 	free(string);
// 	string = temp_strings;
// 	return (line_to_return);
// }

// Return value Read line: correct behavior
// NULL: there is nothing else to read, or an error
// occurred
// External functs. read, malloc, free
// Description Write a function that returns a line read from a
// file descriptor


