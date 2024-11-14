/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:52:31 by hguillau          #+#    #+#             */
/*   Updated: 2024/09/26 16:56:09 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	ft_rotate_left(t_data *data)
{
	data->p.a -= ROT_SPEED;
	if (data->p.a < 0)
		data->p.a += (2 * M_PI);
}

void	ft_rotate_right(t_data *data)
{
	data->p.a += ROT_SPEED;
	if (data->p.a > (2 * M_PI))
		data->p.a -= (2 * M_PI);
}

void	ft_mov_cam(t_data *data, int key)
{
	if (key == 65363)
		ft_rotate_right(data);
	if (key == 65361)
		ft_rotate_left(data);
}
