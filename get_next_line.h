/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:15:29 by noel-baz          #+#    #+#             */
/*   Updated: 2024/12/14 14:01:59 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char	*s, unsigned int index, size_t	bytes);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*ft_get_line(char *buffer);
char	*update_buffer(char *buffer);
char	*read_line(int fd, char *buffer);

#endif