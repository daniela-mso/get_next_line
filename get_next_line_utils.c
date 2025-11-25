/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:35:03 by danielad          #+#    #+#             */
/*   Updated: 2025/11/25 22:10:58 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const char	*n1;
	const char	*n2;
	char		*str;
	int			i;

	n1 = s1;
	n2 = s2;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (*n1)
	{
		str[++i] = *n1;
		n1++;
	}
	while (*n2)
	{
		str[++i] = *n2;
		n2++;
	}
	str[i + 1] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
