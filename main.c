/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:43:01 by austunso          #+#    #+#             */
/*   Updated: 2025/03/05 18:58:14 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_won(t_map *data)
{
	free_items2(data);
	free_items(data);
	ft_printf("\n\t\t\t\tCONGRATULATIONS, YOU ARE VICTORIOUS!\t\t\t\t\n");
	exit (0);
}

int	close_window(t_map *data)
{
	free_items2(data);
	free_items(data);
	ft_printf("Window closed\n");
	exit(0);
}

static void	stack_init(t_map *data)
{
	data->map = NULL;
	data->mlx = NULL;
	data->e_xloc = 0;
	data->e_yloc = 0;
	data->p_xloc = 0;
	data->p_yloc = 0;
	data->map_height = 0;
	data->map_width = 0;
	data->player = 0;
	data->exit = 0;
	data->coins = 0;
	data->moves = 1;
}

int	main(int argc, char **argv)
{
	t_map	*data;

	data = malloc(sizeof(t_map));
	if (data == NULL)
	{
		print_error("Memory Error!", data);
	}
	stack_init(data);
	if (argc != 2)
		print_error("Please insert a map!", data);
	data->map_name = control_map_name(data, argv[1]);
	make_map_array(data);
	map_control(data);
	find_location(data);
	is_everywhere_reachable(data, data->p_xloc, data->p_yloc);
	check_reachability(data);
	create_window(data);
	mlx_key_hook(data->mlx->win_ptr, input_handler, data);
	mlx_hook(data->mlx->win_ptr, 17, 0, close_window, data);
	mlx_loop(data->mlx->mlx_ptr);
}
