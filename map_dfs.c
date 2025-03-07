/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:43:15 by austunso          #+#    #+#             */
/*   Updated: 2025/03/05 18:43:18 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_location(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				data->p_yloc = i;
				data->p_xloc = j;
			}
			if (data->map[i][j] == 'E')
			{
				data->e_xloc = j;
				data->e_yloc = i;
			}
			j++;
		}
		i++;
	}
}

void	is_everywhere_reachable(t_map *data, int p_xloc, int p_yloc)
{
	if (data->copy_map[p_yloc][p_xloc] == '1'  || data->copy_map[p_yloc][p_xloc] == 'a' || data->copy_map[p_yloc][p_xloc] == 'E')
		return ;
	data->copy_map[p_yloc][p_xloc] = 'a';
	is_everywhere_reachable(data, p_xloc, p_yloc + 1);
	is_everywhere_reachable(data, p_xloc, p_yloc - 1);
	is_everywhere_reachable(data, p_xloc + 1, p_yloc);
	is_everywhere_reachable(data, p_xloc - 1, p_yloc);
}

void	check_reachability(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width - 1)
		{
			if (data->copy_map[i][j] == 'C')
				print_error("Unreachable items on the map!\n", data);
			if (data->copy_map[i][j] == 'E')
			{
				if (data->copy_map[i][j + 1] != 'a' && data->copy_map[i][j - 1] != 'a' && data->copy_map[i + 1][j] != 'a' && data->copy_map[i -1 ][j] != 'a')
					print_error("Unreachable Exit!\n", data);
			}
			j++;
		}
		i++;
	}
}
