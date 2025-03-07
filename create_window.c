/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:42:35 by austunso          #+#    #+#             */
/*   Updated: 2025/03/05 18:42:37 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_images(t_map *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
			mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
				data->mlx->wall, j * 64, i * 64);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->ground, j * 64, i * 64);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->player, j * 64, i * 64);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->coin, j * 64, i * 64);	
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->exit, j * 64, i * 64);
			j++;
		}
	i++;
	}
}

static void check_images(t_map *data)
{
	if (data->mlx->player == NULL || data->mlx->wall == NULL
		|| data->mlx->ground == NULL || data->mlx->coin== NULL
		|| data->mlx->exit == NULL)
		print_error("Missing image file!", data);
}

static void load_images(t_map *data)
{
	
	int width;
	int height;

	data->mlx->player = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
		"images/player.xpm", &width, &height);
	data->mlx->ground = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
		"images/ground.xpm",  &width, &height);
	data->mlx->wall = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
		 "images/wall.xpm", &width, &height);
	data->mlx->coin = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
		 "images/coin.xpm", &width, &height);
	data->mlx->exit = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
		 "images/exit.xpm", &width, &height);
	check_images(data);
	put_images(data);
}

void create_window(t_map *data)
{
    data->mlx = (t_mlx *)malloc(sizeof(t_mlx));
    if (data->mlx == NULL)
		print_error("Memory error !", data);
	data->mlx->mlx_ptr = NULL;
	data->mlx->win_ptr = NULL;
	data->mlx->mlx_ptr = mlx_init();
	data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr, (data->map_width- 1) * 64, data->map_height * 64, "so_long");
	load_images(data);
}