/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:05:52 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/17 17:08:12 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free_join(char *current_buffer, char *buffer)
{
	char	*buffer_to_join;

	buffer_to_join = ft_strjoin(current_buffer, buffer);
	free(current_buffer);
	return (buffer_to_join);
}

static char	*ft_read_file(int fd, char *current_buffer)
{
	char	*buffer;
	int		nb_bytes_read;
	int		check_charset;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	nb_bytes_read = 1;
	check_charset = 1;
	while (nb_bytes_read > 0 && check_charset)
	{
		nb_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes_read < 0)
		{
			free(buffer);
			free(current_buffer);
			return (0);
		}
		buffer[nb_bytes_read] = 0;
		current_buffer = ft_free_join(current_buffer, buffer);
		if (ft_strchr(buffer, '\n'))
			check_charset = 0;
	}
	free(buffer);
	return (current_buffer);
}

static char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	line = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!line)
		return (0);
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = 0;
	free(buffer);
	return (line);
}

static char	*ft_set_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] != '\n')
		line = malloc((i + 1) * sizeof(char));
	else
		line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*current_buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!current_buffer[fd])
	{
		current_buffer[fd] = malloc(1);
		if (!current_buffer[fd])
			return (0);
		current_buffer[fd][0] = 0;
	}
	current_buffer[fd] = ft_read_file(fd, current_buffer[fd]);
	if (!current_buffer[fd])
		return (0);
	line = ft_set_line(current_buffer[fd]);
	current_buffer[fd] = ft_next_line(current_buffer[fd]);
	return (line);
}
