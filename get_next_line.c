/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:07:31 by danielad          #+#    #+#             */
/*   Updated: 2025/10/31 13:58:10 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*read_data(int fd)
// {
// 	char	was_read[BUFFER_SIZE + 1];
// 	ssize_t	b_read;
// 	static char	*stored_line;


// 	b_read = read(fd, was_read, BUFFER_SIZE); 
// 	if (was_read == NULL)
// 		return (NULL);
// 	b_read = read(fd, was_read, BUFFER_SIZE);
// 	if (stored_line == NULL)
// 	{
// 		stored_line = ft_strdup("");
// 		if (stored_line == NULL)
// 			return (NULL);
// 	}
// 	while (b_read > 0)
// 	{
// 		was_read[b_read] = '\0';
// 		ft_strjoin(stored_line, was_read);

// 	}
// 	return (was_read);
	
// }

//  char	*set_line(int fd)
// {
// 	char	*line;
// 	static char	*stored_line;

// 	stored_line = ft_strdup("");
// 	if (stored_line == NULL)
// 		return (NULL);
// 	while (!ft_strchr(line, '\n') || !ft_strchr(line, '\0'));
// 	{
		
// 	}
	
// }

// char	*get_next_line(int fd)
// {
// 	if (fd < 0)
// 		return (NULL);
// }









// // TODO: test with BUFFER_SIZE of 1, test with BUFFER_SIZE of 2048, with BUFFER_SIZE of 1 million 
// // make a script to test EVERY SINGLE file 
// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	int			i;
// 	int			j;
// 	char		*temp;
// 	char		*read_data;
// 	ssize_t		n_bytes_read;
// 	static char	*g_string = NULL;

// 	line = NULL;
// 	i = 0;
// 	j = 0;
// 	if (fd < 0)
// 		return (NULL); 
// if (g_string == NULL)
// 	{
// 		g_string = ft_strdup("");
// 		if (g_string == NULL)
// 			return (NULL);
// 	}
// 	read_data = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (read_data == NULL)
// 		return (NULL);
// 	// TODO: check if n_bytes_read is == -1 (then there is an error and NULL is returned)
// 	n_bytes_read = read(fd, read_data, BUFFER_SIZE);
// 	while (n_bytes_read > 0)
// 	{
// 		read_data[n_bytes_read] = '\0';
// 		temp = ft_strjoin(g_string, read_data);
// 		if (temp == NULL)
// 		{
// 			free(read_data);
// 			free(g_string);
// 			return (NULL);
// 		}
// 		free(g_string);
// 		g_string = temp;
// 		if (ft_strchr(read_data, '\n') != NULL)
// 			break ;
// 		n_bytes_read = read(fd, read_data, BUFFER_SIZE);
// 	}
// 	free(read_data);
// 	if (g_string == NULL || *g_string == '\0')
// 	{
// 		free(g_string);
// 		g_string = NULL;
// 		return (NULL);
// 	}
// 	while (g_string[i] != '\0' && g_string[i] != '\n')
// 		i++;
// 	if (g_string[i] == '\n')
// 		i++;
// 	line = malloc((i + 1) * sizeof(char));
// 	if (line == NULL)
// 		return (NULL);
// 	while (j < i)
// 	{
// 		line[j] = g_string[j];
// 		j++;
// 	}
// 	line[j] = '\0';
// 	temp = ft_strdup(g_string + i);
// 	if (temp == NULL)
// 		return (NULL);
// 	free(g_string);
// 	g_string = temp;
// 	return (line);
// }


// Return value Read line: correct behavior
// NULL: there is nothing else to read, or an error
// occurred
// External functs. read, malloc, free
// Description Write a function that returns a line read from a
// file descriptor


static char *read_buffer(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL){
		printf("buf1 = %s\n", buf);
		return (NULL);
	}
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			printf("buf2 = %s\n", buf);

			free(buf);

			return (NULL);
		}
		buf[bytes] = '\0';
		printf("buf3 = %s\n", buf);

		stash = ft_strjoin(stash, buf);
		printf("staah1 = %s\n", stash);

		if (stash == NULL)
		{
			printf("staah2 = %s\n", stash);
			
			free(buf);
			return (NULL);
		}
	}
	printf("staah3 = %s\n", stash);
	
	free(buf);
	return (stash);
}

static char	*extract_line(char *stash)
{
	int	i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

static char *clean_stash(char *stash)
{
	int		i;
	char	*rest;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	rest = ft_substr(stash, i + 1, ft_strlen(stash));
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		printf("invalid fd or buffersize");
		return (NULL);
	}
	printf("stash = %s\n", stash);
	stash = read_buffer(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
	printf("line = %s\n", line);

	stash = clean_stash(stash);
	return (line);
}