/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:57:16 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/20 19:31:44 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	check_rgb(t_data *data)
{
	data->t.rgbc = convert_rgb(data->paths.pc, data);
	data->t.bc = 1;
	data->t.rgbf = convert_rgb(data->paths.pf, data);
	data->t.bf = 1;
	check_c(data);
	check_f(data);
	check_valid_rgb(data);
	data->t.rgbc_hex = rgb_to_hex(data->t.rgbc);
	data->t.rgbf_hex = rgb_to_hex(data->t.rgbf);
}

void	check_t_paths(t_data *data)
{
	int	len;

	if (!data->paths.pn || !data->paths.ps
		|| !data->paths.pw || !data->paths.pe)
		exit(ft_exit(data, "Error: Didn't find all textures"));
	if (!data->paths.pc || !data->paths.pf)
		exit(ft_exit(data, "Error: Missing RGB"));
	len = ft_strlen(data->paths.pn);
	if (data->paths.pn[len - 4] != '.' || data->paths.pn[len - 3] != 'x'
		|| data->paths.pn[len - 2] != 'p' || data->paths.pn[len - 1] != 'm')
		exit(ft_exit(data, "Error: Missing .xpm extension"));
	len = ft_strlen(data->paths.ps);
	if (data->paths.ps[len - 4] != '.' || data->paths.ps[len - 3] != 'x'
		|| data->paths.ps[len - 2] != 'p' || data->paths.ps[len - 1] != 'm')
		exit(ft_exit(data, "Error: Missing .xpm extension"));
	len = ft_strlen(data->paths.pw);
	if (data->paths.pw[len - 4] != '.' || data->paths.pw[len - 3] != 'x'
		|| data->paths.pw[len - 2] != 'p' || data->paths.pw[len - 1] != 'm')
		exit(ft_exit(data, "Error: Missing .xpm extension"));
	len = ft_strlen(data->paths.pe);
	if (data->paths.pe[len - 4] != '.' || data->paths.pe[len - 3] != 'x'
		|| data->paths.pe[len - 2] != 'p' || data->paths.pe[len - 1] != 'm')
		exit(ft_exit(data, "Error: Missing .xpm extension"));
}
