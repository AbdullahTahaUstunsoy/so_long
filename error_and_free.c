/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:42:55 by austunso          #+#    #+#             */
/*   Updated: 2025/03/05 18:42:58 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_items2(t_map *data)
{
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->player);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->coin);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->wall);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->ground);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->exit);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->mlx->mlx_ptr);
	free(data->mlx);
}
void free_items(t_map *data)
{
	int i;

	i = 0;
	while(i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	free (data->map[i]);
	free(data->map);

	i = 0;
	while (i < data->map_height)
	{
		free(data->copy_map[i]);
		i++;
	}
	free (data->copy_map[i]);
	free(data->copy_map);
	free (data);
}


void	print_error(char *str, t_map *data)
{
	ft_printf("%s", str);
	if (data == NULL)
		exit (0);
	else if (data->map == NULL)
	{
		free(data);
		exit(0);
	}
	else if(data->copy_map == NULL)
	{
		free(data);
		exit(0);
	}
	else	
		free_items(data);
	exit(0);
}