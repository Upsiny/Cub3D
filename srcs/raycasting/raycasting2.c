/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:19:48 by hguillau          #+#    #+#             */
/*   Updated: 2024/11/13 14:27:40 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

double	nor_angle(double angle)
{
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle <= 0)
		angle += 2 * M_PI;
	return (angle);
}

int	get_wall_color(t_data *data, int flag)
{
	data->r.r_angle = nor_angle(data->r.r_angle);
	if (flag == 0)
	{
		if (data->r.r_angle > M_P2 && data->r.r_angle < M_P3)
			return (PURPLE);
		else
			return (BLUE);
	}
	else
	{
		if (data->r.r_angle > 0 && data->r.r_angle < M_PI)
			return (GREEN);
		else
			return (WHITE);
	}
}
/*
int get_textures(t_data *data, int flag)
{
	data->r.r_angle = nor_angle(data->r.r_angle);
	if (flag == 0)
	{
		if (data->r.r_angle > M_P2 && data->r.r_angle < M_P3)
			return (data->tex_ea); // east
		else
			return (data->tex_we); // west
	}
	else
	{
		if (data->r.r_angle > 0 && data->r.r_angle < M_PI)
			return (data->tex_no); //north
		else
			return (data->tex_so); // south
	}
}*/

void	color_wall(t_data *data, int ray, t_images *img)
{
	int	color;

	color = get_wall_color(data, data->r.flag);
	while (data->r.b_px < data->r.t_px)
		my_mlx_pixel_put(img, ray, data->r.b_px++, color);
}

void	draw_wall(t_data *data, int ray, t_images *img)
{
	double	wall_h;

	data->r.t_px = 0;
	data->r.b_px = 0;
	data->r.distance *= fabs(cos(nor_angle(data->r.r_angle - data->p.a)));
	wall_h = (TILE_SIZE / data->r.distance) * (WIN_WIDTH / 2)
		/ tan(data->p.fov_rad / 2);
	data->r.t_px = (WIN_HEIGHT / 2) + (wall_h / 2);
	data->r.b_px = (WIN_HEIGHT / 2) - (wall_h / 2);
	if (data->r.t_px > WIN_HEIGHT)
		data->r.t_px = WIN_HEIGHT;
	if (data->r.b_px < 0)
		data->r.b_px = 0;
	color_wall(data, ray, img);
}
