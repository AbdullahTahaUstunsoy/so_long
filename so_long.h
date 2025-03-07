/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:40:55 by austunso          #+#    #+#             */
/*   Updated: 2025/03/05 18:41:00 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*ground;
	void	*wall;
	void	*coin;
	void	*exit;
}			t_mlx;

typedef struct s_map
{
	char	**map;
	char	**copy_map;
	char	*map_name;
	
	int		map_width;
	int		map_height;
	int		fd;
	int		player;
	int		coins;
	int		exit;
	int		p_xloc;
	int		p_yloc;
	int		e_xloc;
	int		e_yloc;
	int		moves;
	t_mlx	*mlx;
}			t_map;

void		print_error(char *str, t_map *data);
char		*control_map_name(t_map *data, char *arg);
void		make_map_array(t_map *data);
void 		make_copy_map_array(t_map *data);
void		map_control(t_map *data);
void		free_items(t_map *data);
void		is_rectengular(t_map *data);
void		is_valid(t_map *data);
void		is_everywhere_reachable(t_map *data, int p_xloc, int p_yloc);
void		find_location(t_map *data);
void		check_reachability(t_map *data);
void		create_window(t_map *data);
void		free_items2(t_map *data);
void		put_images(t_map *data);
int			input_handler(int code, t_map *data);
void		game_won();
int			close_window();

#endif