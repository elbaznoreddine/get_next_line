/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:53:29 by noel-baz          #+#    #+#             */
/*   Updated: 2024/12/02 00:59:41 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_line(char *buffer)
{
	int i;
	char    *new_buffer;

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
char *update_buffer(char *buffer)
{
	int i;
	char *new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i]) 
		i++;
	new_buffer = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	return (new_buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *temp;
	char *line;
	int bytes_read;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	temp = malloc((size_t)BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (1)
	{  
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (free(temp), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(temp);
	if ((bytes_read == 0) && (!buffer || buffer[0] == '\0'))
	{
		free(buffer);
		buffer = NULL;
		return NULL;
	}
	line = ft_get_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}

