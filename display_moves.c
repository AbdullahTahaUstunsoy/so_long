/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:42:45 by austunso          #+#    #+#             */
/*   Updated: 2025/03/05 18:42:50 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_left(t_map *data)
{
	if (data->map[data->p_yloc][data->p_xloc - 1] != '1')
	{
		if (data->map[data->p_yloc][data->p_xloc - 1] == 'E' && data->coins > 0)
			return;
		ft_printf("Steps: %d\n", data->moves++);
		if (data->map[data->p_yloc][data->p_xloc - 1] == 'C')
			data->coins--;
		if (data->map[data->p_yloc][data->p_xloc - 1] == 'E' && data->coins == 0)
			game_won(data);
		else
		{
			data->map[data->p_yloc][data->p_xloc] = '0';
			data->p_xloc--;
			data->map[data->p_yloc][data->p_xloc] = 'P';
		}
	}
}

static void move_right (t_map *data)
{
	if (data->map[data->p_yloc][data->p_xloc + 1] != '1')
	{
		if (data->map[data->p_yloc][data->p_xloc + 1] == 'E' && data->coins > 0)
			return;
		ft_printf("Steps: %d\n", data->moves++);
		if (data->map[data->p_yloc][data->p_xloc + 1] == 'C')
			data->coins--;
		if (data->map[data->p_yloc][data->p_xloc + 1] == 'E' && data->coins == 0)
			game_won(data);
		else
		{
			data->map[data->p_yloc][data->p_xloc] = '0';
			data->p_xloc++;
			data->map[data->p_yloc][data->p_xloc] = 'P';
		}
	}
}

static void move_down (t_map *data)
{
	if (data->map[data->p_yloc + 1][data->p_xloc] != '1')
	{
		if (data->map[data->p_yloc + 1][data->p_xloc] == 'E' && data->coins > 0)
			return;
		ft_printf("Steps: %d\n", data->moves++);
		if (data->map[data->p_yloc + 1][data->p_xloc] == 'C')
			data->coins--;
		if (data->map[data->p_yloc + 1][data->p_xloc] == 'E' && data->coins == 0)
			game_won(data);
		else
		{
			data->map[data->p_yloc][data->p_xloc] = '0';
			data->p_yloc++;
			data->map[data->p_yloc][data->p_xloc] = 'P';
		}
	}
}


static void move_up (t_map *data)
{
	if (data->map[data->p_yloc - 1][data->p_xloc] != '1')
	{
		if (data->map[data->p_yloc - 1][data->p_xloc] == 'E' && data->coins > 0)
			return;
		ft_printf("Steps: %d\n", data->moves++);
		if (data->map[data->p_yloc - 1][data->p_xloc] == 'C')
			data->coins--;
		if (data->map[data->p_yloc - 1][data->p_xloc] == 'E' && data->coins == 0)
			game_won(data);
		else
		{
			data->map[data->p_yloc][data->p_xloc] = '0';
			data->p_yloc--;
			data->map[data->p_yloc][data->p_xloc] = 'P';
		}
	}
}

int input_handler(int code, t_map *data)
{
    if (code == 65307)
        close_window(data);
    if (code == 97 || code == 65361)
        move_left(data);
    if (code == 100 || code == 65363)
        move_right(data);
    if (code == 115 || code == 65364)
        move_down(data);
    if (code == 119 || code == 65362)
        move_up(data);
    put_images(data);
    return (0);
}