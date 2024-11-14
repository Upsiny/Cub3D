/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:44:18 by hguillau          #+#    #+#             */
/*   Updated: 2024/11/14 13:03:15 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	my_mlx_pixel_put(t_images *img, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(ft_exit(data, "Game closed"));
	return (0);
}

/*
keycode :
	a = 97
	s = 115
	d = 100
	w = 119
	esc = 65'307
	-> = 65'363
	<- = 65'361
	tab = 65'289
	m = 109
*/

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data, "Game closed");
	if (keycode == 119 || keycode == 115 || keycode == 100 || keycode == 97)
		ft_move(data, keycode);
	if (keycode == 65361 || keycode == 65363)
		ft_mov_cam(data, keycode);
	return (0);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data ->p.dir == 'N')
		data->p.a = M_P2 + EPSILON;
	else if (data->p.dir == 'S')
		data->p.a = M_P3 + EPSILON;
	else if (data->p.dir == 'W')
		data->p.a = 0 + EPSILON;
	else if (data->p.dir == 'E')
		data->p.a = M_PI + EPSILON;
	data->p.fov_rad = (FOV * M_PI) / 180;
	data->p.pos_x = (data->p.y + 0.5) * TILE_SIZE;
	data->p.pos_y = (data->p.x + 0.5) * TILE_SIZE;
}

void	start_mlx(t_data *data)
{
	init_mlx(data);
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_keypress, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}
