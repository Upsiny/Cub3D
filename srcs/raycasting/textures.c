/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:14:41 by hguillau          #+#    #+#             */
/*   Updated: 2024/11/19 06:41:59 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	get_images_ea_we(t_data *data)
{
	int	h;
	int	w;

	data->images.we.img = mlx_xpm_file_to_image(data->mlx,
			data->paths.pw, &w, &h);
	if (!data->images.we.img)
		exit(ft_exit(data, "Error: Xpm file not found"));
	data->images.we.addr = mlx_get_data_addr(data->images.we.img,
			&data->images.we.bits_per_pixel, &data->images.we.line_length,
			&data->images.we.endian);
	data->images.we.width = w;
	data->images.we.height = h;
	data->images.ea.img = mlx_xpm_file_to_image(data->mlx,
			data->paths.pe, &w, &h);
	if (!data->images.ea.img)
		exit(ft_exit(data, "Error: Xpm file not found"));
	data->images.ea.addr = mlx_get_data_addr(data->images.ea.img,
			&data->images.ea.bits_per_pixel, &data->images.ea.line_length,
			&data->images.ea.endian);
	data->images.ea.width = w;
	data->images.ea.height = h;
}

void	get_images(t_data *data)
{
	int	w;
	int	h;

	data->images.no.img = mlx_xpm_file_to_image(data->mlx,
			data->paths.pn, &w, &h);
	if (!data->images.no.img)
		exit(ft_exit(data, "Error: Xpm file not found"));
	data->images.no.addr = mlx_get_data_addr(data->images.no.img,
			&data->images.no.bits_per_pixel, &data->images.no.line_length,
			&data->images.no.endian);
	data->images.no.width = w;
	data->images.no.height = h;
	data->images.so.img = mlx_xpm_file_to_image(data->mlx,
			data->paths.ps, &w, &h);
	if (!data->images.so.img)
		exit(ft_exit(data, "Error: Xpm file not found"));
	data->images.so.addr = mlx_get_data_addr(data->images.so.img,
			&data->images.so.bits_per_pixel, &data->images.so.line_length,
			&data->images.so.endian);
	data->images.so.width = w;
	data->images.so.height = h;
	get_images_ea_we(data);
}

int	get_color_from_texture(t_texture *t, int x, int y)
{
	char	*pixel;

	if ((x <= WIN_HEIGHT || x >= 0) && (y <= WIN_WIDTH || y >= 0))
		pixel = t->addr + (y * t->line_length + x
				* (t->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	get_text_x(t_data *data, t_texture *t)
{
	if (data->r.flag)
		data->r.wall_x = ((int)data->r.h_x % TILE_SIZE);
	else
		data->r.wall_x = ((int)data->r.v_y % TILE_SIZE);
	data->r.text_x = (data->r.wall_x / TILE_SIZE) * t->width;
}
