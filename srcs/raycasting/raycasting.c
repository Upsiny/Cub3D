/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:13:11 by hguillau          #+#    #+#             */
/*   Updated: 2024/11/19 06:55:19 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

int	unit_circle(double angle, char c)
{
	if (c == 'h')
	{
		if (angle > M_P2 && angle < M_P3)
			return (1);
	}
	if (c == 'v')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	return (0);
}

int	hit_wall(t_data *data, double x, double y)
{
	int	x_map;
	int	y_map;

	if (x < 0 || y < 0)
		return (0);
	x_map = floor(x / TILE_SIZE);
	y_map = floor(y / TILE_SIZE);
	if (x_map >= data->map.width || y_map >= data->map.length)
		return (0);
	if (data->map.map[y_map] && x_map <= (int)ft_strlen(data->map.map[y_map]))
	{
		if (data->map.map[y_map][x_map] == '1')
			return (0);
	}
	return (1);
}

double	get_h_inter(t_data *data, double angle)
{
	double	h_y;
	int		is_top;

	is_top = 0;
	data->r.step_y = TILE_SIZE;
	if (angle > 0 && angle < M_PI)
	{
		h_y = (floor(data->p.pos_y / TILE_SIZE) * TILE_SIZE);
		data->r.step_y *= -1;
		is_top = 1;
	}
	else
		h_y = (floor(data->p.pos_y / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
	data->r.h_x = data->p.pos_x + (data->p.pos_y - h_y) / tan(angle);
	data->r.step_x = TILE_SIZE / tan(angle);
	if ((unit_circle(angle, 'h') && data->r.step_x > 0)
		|| (!unit_circle(angle, 'h') && data->r.step_x < 0))
		data->r.step_x *= -1;
	while (hit_wall(data, data->r.h_x, h_y - is_top))
	{
		data->r.h_x += data->r.step_x;
		h_y += data->r.step_y;
	}
	return (sqrt(pow(data->r.h_x - data->p.pos_x, 2)
			+ pow(h_y - data->p.pos_y, 2)));
}

double	get_v_inter(t_data *data, double angle)
{
	double	v_x;
	int		is_left;

	is_left = 0;
	data->r.step_x = TILE_SIZE;
	if (angle > M_P3 || angle < M_P2)
		v_x = (floor(data->p.pos_x / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
	else
	{
		v_x = (floor(data->p.pos_x / TILE_SIZE) * TILE_SIZE);
		data->r.step_x *= -1;
		is_left = 1;
	}
	data->r.v_y = data->p.pos_y + (data->p.pos_x - v_x) * tan(angle);
	data->r.step_y = TILE_SIZE * tan(angle);
	if ((unit_circle(angle, 'v') && data->r.step_y > 0)
		|| (!unit_circle(angle, 'v') && data->r.step_y < 0))
		data->r.step_y *= -1;
	while (hit_wall(data, v_x - is_left, data->r.v_y))
	{
		v_x += data->r.step_x;
		data->r.v_y += data->r.step_y;
	}
	return (sqrt(pow(v_x - data->p.pos_x, 2)
			+ pow(data->r.v_y - data->p.pos_y, 2)));
}

void	cast_ray(t_data *data, t_images *img)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	data->r.r_angle = data->p.a - (data->p.fov_rad / 2);
	ray = 0;
	while (ray < WIN_WIDTH)
	{
		data->r.flag = 0;
		h_inter = get_h_inter(data, nor_angle(data->r.r_angle));
		v_inter = get_v_inter(data, nor_angle(data->r.r_angle));
		if (v_inter <= h_inter)
			data->r.distance = v_inter;
		else
		{
			data->r.distance = h_inter;
			data->r.flag = 1;
		}
		draw_wall(data, ray, img);
		ray++;
		data->r.r_angle += data->p.fov_rad / WIN_WIDTH;
	}
}
