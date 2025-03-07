/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:41:47 by austunso          #+#    #+#             */
/*   Updated: 2025/03/05 18:41:52 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*control_map_name(t_map *data, char *arg)
{
	int	len;
	char *line;

	data->fd = open(arg, O_RDONLY);
	if (data->fd == -1)
		print_error("No such file or directory!", data);
	len = ft_strlen(arg);
	if (arg[len - 1] != 'r' || arg[len - 2] != 'e' || arg[len - 3] != 'b'
		|| arg[len - 4] != '.')
	{
		print_error("File extension must be .ber!", data);
	}
	line = get_next_line (data->fd);
	if (line == NULL){
		ft_printf ("Empty file!\n");
		free(data);
		exit (0);
	}
	free(line);
	close(data->fd);
	return (arg);
}

static void	find_height(t_map *data)
{
	char	*line;

	data->fd = open(data->map_name, O_RDONLY);
	line = get_next_line(data->fd);
	while (line)
	{
		data->map_height++;
		free(line);
		line = get_next_line(data->fd);
	}
	free (line);
	close(data->fd);
}

void	make_map_array(t_map *data)
{
	char	*line;
	int		i;

	i = 0;
	find_height(data);
	data->fd = open(data->map_name, O_RDONLY);
	line = get_next_line(data->fd);
	data->map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (data->map == NULL)
		print_error("Memory error!\n",data);
	while (line != NULL)
	{
		data->map[i] = line;
		line = get_next_line(data->fd);
		i++;
	}
	free (line);
	data->map[i] = NULL;
	close(data->fd);
	make_copy_map_array(data);
}

static void	are_walls_just_one(t_map *data)
{
	int	i;

	i = 0;
	while (i < data->map_width - 1) 
	{
		if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1') 
			print_error("Walls are not just 1!", data);
		i++;
	}
	i = 0;
	while (i < data->map_height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->map_width - 2] != '1')
			print_error("Walls are not just 1!", data);
		i++;
	}
}

void	map_control(t_map *data)
{
	is_rectengular(data);
	are_walls_just_one(data);
	is_valid(data);
}
