/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 02:02:55 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/23 00:51:39 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map)
	{
		while (data->map.map[i])
		{
			free(data->map.map[i]);
			i++;
		}
		free(data->map.map);
		data->map.map = NULL;
	}
}

void	free_paths(t_data *data)
{
	int	i;

	if (data->paths.pc)
		free(data->paths.pc);
	if (data->paths.pf)
		free(data->paths.pf);
	if (data->paths.pn)
		free(data->paths.pn);
	if (data->paths.ps)
		free(data->paths.ps);
	if (data->paths.pw)
		free(data->paths.pw);
	if (data->paths.pe)
		free(data->paths.pe);
	if (data->t.bc == 1)
		free(data->t.rgbc);
	if (data->t.bf == 1)
		free(data->t.rgbf);
}

void	free_tmp(t_data *data)
{
	int	i;

	i = 0;
	if (data->bool == 1)
	{
		while (data->tmp[i])
		{
			free(data->tmp[i]);
			i++;
		}
		free(data->tmp);
	}
}

int	ft_exit(t_data *data, char *err)
{
	int	i;

	i = 0;
	if (err != NULL)
		printf("%s\n", err);
	if (data->bfile == 1)
	{
		while (data->file[i])
		{
			free(data->file[i]);
			i++;
		}
		free(data->file);
	}
	free_map(data);
	free_tmp(data);
	free_paths(data);
	exit (0);
}
