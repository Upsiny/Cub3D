/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:58:30 by akunegel          #+#    #+#             */
/*   Updated: 2024/11/15 18:37:07 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3d.h"

void	clean_paths(t_data *data)
{
	data->t.bc = 0;
	data->t.bf = 0;
	data->bfile = 0;
	data->paths.pn = NULL;
	data->paths.pe = NULL;
	data->paths.ps = NULL;
	data->paths.pw = NULL;
	data->paths.pc = NULL;
	data->paths.pf = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.bool = 0;
	data.map.map = NULL;
	clean_paths(&data);
	if (argc != 2)
		return (ft_exit(&data, "Error : Expected exactly 1 argument"));
	data.paths.pfile = argv[1];
	parsing(&data);
	start_mlx(&data);
	return (ft_exit(&data, "Game closed"));
}
