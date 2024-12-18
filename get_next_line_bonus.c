/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:24:08 by noel-baz          #+#    #+#             */
/*   Updated: 2024/12/16 22:42:58 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*new_buffer;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	new_buffer = ft_substr(buffer, 0, i);
	return (new_buffer);
}

char	*update_buffer(char *buffer)
{
	int		i;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i])
		i++;
	new_buffer = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	return (new_buffer);
}

char	*read_line(int fd, char *buffer)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	temp = malloc((size_t)BUFFER_SIZE + 1);
	if (!temp)
		return (free(buffer), buffer = NULL, NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp), free(buffer), buffer = NULL, NULL);
		if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer || ft_strchr(buffer, '\n'))
			break ;
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd] || buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}
