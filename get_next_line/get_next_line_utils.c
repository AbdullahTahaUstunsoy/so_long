/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:47:02 by austunso          #+#    #+#             */
/*   Updated: 2025/02/24 19:06:35 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	_ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*_ft_strjoin(char *buffer, char *temp_buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		buffer[0] = '\0';
	}
	if (!buffer || !temp_buffer)
		return (NULL);
	new_buffer = malloc(sizeof(char) * (_ft_strlen(buffer)
				+ _ft_strlen(temp_buffer) + 1));
	i = -1;
	j = 0;
	while (buffer[++i])
		new_buffer[i] = buffer[i];
	while (temp_buffer[j])
		new_buffer[i++] = temp_buffer[j++];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

int	found_new_line(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_new_line(char *buffer)
{
	char	*line;
	int		i;
	int		new_line;

	new_line = found_new_line(buffer);
	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1 + new_line));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_new_buffer(char *buffer)
{
	char	*updated_buffer;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	updated_buffer = malloc(sizeof(char) * (_ft_strlen(buffer) - i + 1));
	if (!updated_buffer)
		return (NULL);
	while (buffer[i])
		updated_buffer[j++] = buffer[i++];
	updated_buffer[j] = '\0';
	free(buffer);
	return (updated_buffer);
}
