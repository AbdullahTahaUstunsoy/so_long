/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:41:57 by austunso          #+#    #+#             */
/*   Updated: 2025/03/05 18:42:01 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectengular(t_map *data)
{
	int	i;

	i = 0;
	data->map_width = (int)ft_strlen(data->map[0]);
	while (i < data->map_height -1)                           
	{
		if ((int)ft_strlen(data->map[i]) != data->map_width)
			print_error("Map is not rectengular!", data);
		i++;
	}
	if ((int)ft_strlen(data->map[data->map_height -1] ) + 1 != data->map_width)
		print_error("Map is not rectengular!", data);
}

void	is_valid(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
        j = 0;
        while (data->map[i][j] != '\0')
        {
            if (data->map[i][j] != '1' && data->map[i][j] != '0' && data->map[i][j] != 'P' && data->map[i][j] != 'E' && data->map[i][j] != 'C' && data->map[i][j] != '\n')
                print_error ("Invalid characters!",data);
            if (data->map [i][j] == 'P')
                data->player++;
            if (data->map[i][j] == 'E')
				data->exit++;
			if (data->map[i][j] == 'C')
				data->coins++;
            j++;    
        }
        i++;
	}
	if (data->player != 1 || data->exit != 1 || data->coins == 0)
		print_error ("The map must contain exactly one player, one exit, and at least one coin!",data);
}

void make_copy_map_array(t_map *data)
{
	char	*line;
	int		i;

	i = 0;
	data->fd = open(data->map_name, O_RDONLY);
	line = get_next_line(data->fd);
	data->copy_map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (data->copy_map == NULL)
		print_error("Memory error!\n",data);
	while (line != NULL)
	{
		data->copy_map[i] = line;
		line = get_next_line(data->fd);
		i++;
	}
	free (line);
	data->copy_map[i] = NULL;
	close(data->fd);
}
