/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:53:32 by noel-baz          #+#    #+#             */
/*   Updated: 2024/12/01 23:04:00 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE
# define FT_GET_NEXT_LINE

#ifndef	BUFFER_SIZE
# define	BUFFER_SIZE 1
#endif

# include <libc.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_substr(char	*s, unsigned int index, size_t	bytes);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s);
char *ft_get_line(char *buffer);
char *update_buffer(char *buffer);

#endif