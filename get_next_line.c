/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:07:31 by danielad          #+#    #+#             */
/*   Updated: 2025/11/21 14:43:13 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char **stash)
{
	char	*buf;
	ssize_t	bytes_read;
	char	*temp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		temp = ft_strjoin(*stash, buf);
		free(*stash);
		*stash = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	if (bytes_read < 0)
		return (NULL);
	return (*stash);
}

static char	*extract_line(char **stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (((*stash)[i] != '\0') && ((*stash)[i] != '\n'))
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = (*stash)[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static void	clean_stash(char **stash)
{
	int		i;
	char	*temp;
	char	*rest;

	i = 0;
	temp = *stash;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	rest = ft_strdup(temp + i);
	free(*stash);
	*stash = rest;
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	 
	if (fd < 0)
		return (NULL);
	if (stash == NULL)
		stash = ft_strdup("");
	if (read_buffer(fd, &stash) == NULL)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (stash != NULL && *stash != '\0')
	{
		line = extract_line(&stash);
		clean_stash(&stash);
		return (line);
	}
	free(stash);
	stash = NULL;
	return (NULL);
}

//     if (stash != NULL && *stash != '\0') 
//     {
//         line = extract_line(&stash);  // Extract line from stash
//         if (!line)  // Check if line allocation was unsuccessful
//         {
//             free(stash); // Free stash to avoid leaks
// 			free(line);
//             stash = NULL; // Set stash to NULL after freeing
//             return (NULL);
//         }

//         clean_stash(&stash);  // Clean up stash
//         return (line);  // Return the line
//     }

//     free(stash);  // Free stash if it's empty
//     stash = NULL; // Set stash to NULL to avoid dangling pointer
//     return (NULL);
// }

