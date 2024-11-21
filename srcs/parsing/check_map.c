/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:41:49 by akunegel          #+#    #+#             */
/*   Updated: 2024/11/21 13:10:40 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	verify_map_leaks(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (i >= get_map_lines(data->tmp) - 1
					|| j >= get_longest_line(data->tmp) - 1 || i == 0 || j == 0)
					exit(ft_exit(data, "Error: Map is opened"));
				if (map[i + 1][j] == '2' || map[i - 1][j] == '2'
					|| map[i][j + 1] == '2' || map[i][j - 1] == '2')
					exit(ft_exit(data, "Error: Map is opened"));
			}
			j++;
		}
		i++;
	}
}

void	verify_if_player_stuck(t_data *data)
{
	if (data->map.map[data->p.x - 1][data->p.y] != '0'
		&& data->map.map[data->p.x + 1][data->p.y] != '0'
		&& data->map.map[data->p.x][data->p.y - 1] != '0'
		&& data->map.map[data->p.x][data->p.y + 1] != '0' )
		exit(ft_exit(data, "Error: Player surrounded by walls"));
}

void	check_map_playable(t_data *data, int x, int y)
{
	if (get_map_lines(data->tmp) < 3)
		exit(ft_exit(data, "Error: Map unplayable"));
	if (!data->p.dir)
		exit (ft_exit(data, "Error: Player missing"));
	(void)y;
	(void)x;
	data->map.width = get_longest_line(data->tmp);
	data->map.length = get_map_lines(data->tmp);
	verify_map_leaks(data->map.map, data);
	verify_if_player_stuck(data);
}

void	check_dir(t_data *data)
{
	if (!data->p.dir)
		exit (ft_exit(data, "Error: Player missing"));
}

void	check_map_chars(t_data *data, int i)
{
	int	j;

	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == '2' || data->map.map[i][j] == '1'
				|| data->map.map[i][j] == '0')
				j++;
			else if ((data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S'
				|| data->map.map[i][j] == 'W' || data->map.map[i][j] == 'E')
				&& data->p.x == -1)
				check_map_chars_extended(data, i, j);
			else
				exit(ft_exit(data, "Error: Wrong map format"));
		}
		i++;
	}
	if (data->p.x == -1)
		exit(ft_exit(data, "Error: Player missing"));
}
