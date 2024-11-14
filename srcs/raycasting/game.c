/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:49:34 by hguillau          #+#    #+#             */
/*   Updated: 2024/11/13 13:36:53 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	fill_background(t_data *data, t_images *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (WIN_HEIGHT / 2))
	{
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, data->t.rgbc_hex);
			x++;
		}
		x = 0;
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, data->t.rgbf_hex);
			x++;
		}
		x = 0;
		y++;
	}
}

int	game_loop(t_data *data)
{
	t_images	img;

	img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	if (!img.img || !img.addr)
	{
		printf("Error: Image creation failed.\n");
		return (1);
	}
	fill_background(data, &img);
	cast_ray(data, &img);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img.img, 0, 0);
	mlx_destroy_image(data->mlx, img.img);
	return (0);
}
