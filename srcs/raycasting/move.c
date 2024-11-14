/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:42:43 by hguillau          #+#    #+#             */
/*   Updated: 2024/11/13 14:23:41 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	ft_move_player(t_data *data, double move_x, double move_y)
{
	double	new_pos_x;
	double	new_pos_y;
	int		map_x;
	int		map_y;

	new_pos_x = roundf(data->p.pos_x + move_x);
	new_pos_y = roundf(data->p.pos_y + move_y);
	map_x = (new_pos_x / TILE_SIZE);
	map_y = (new_pos_y / TILE_SIZE);
	if (data->map.map[map_y][map_x] == '0' &&
	data->map.map[map_y][(int)data->p.pos_x / TILE_SIZE] == '0' &&
	data->map.map[(int)data->p.pos_y / TILE_SIZE][map_x] == '0')
	{
		data->p.pos_x = new_pos_x;
		data->p.pos_y = new_pos_y;
	}
}

void	ft_move(t_data *data, int keycode)
{
	data->move_x = 0;
	data->move_y = 0;
	if (keycode == 97)
	{
		data->move_x = cos(data->p.a - M_P2) * MOVE_SPEED;
		data->move_y = -sin(data->p.a - M_P2) * MOVE_SPEED;
	}
	if (keycode == 100)
	{
		data->move_x = cos(data->p.a + M_P2) * MOVE_SPEED;
		data->move_y = -sin(data->p.a + M_P2) * MOVE_SPEED;
	}
	if (keycode == 119)
	{
		data->move_x = cos(data->p.a) * MOVE_SPEED;
		data->move_y = -sin(data->p.a) * MOVE_SPEED;
	}
	if (keycode == 115)
	{
		data->move_x = -cos(data->p.a) * MOVE_SPEED;
		data->move_y = sin(data->p.a) * MOVE_SPEED;
	}
	ft_move_player(data, data->move_x, data->move_y);
}
