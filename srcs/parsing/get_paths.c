/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:47:32 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/19 00:43:17 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	extract_frgb(t_data *data, char *line, int i, int c)
{
	if (!data->paths.pf)
	{
		data->paths.pf = malloc(sizeof(char) * (c + 1));
		c = 0;
		while (line[i])
		{
			data->paths.pf[c] = line[i];
			c++;
			i++;
		}
		data->paths.pf[c] = '\0';
	}
}

void	extract_rgb(t_data *data, char pre, char *line, int i)
{
	int	c;

	c = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\f'
		|| line[i] == '\v' || line[i] == '\r' || line[i] == '\n')
		i++;
	while (line[i + c])
		c++;
	if (pre == 'C' && !data->paths.pc)
	{
		data->paths.pc = malloc(sizeof(char) * (c + 1));
		c = 0;
		while (line[i])
		{
			data->paths.pc[c] = line[i];
			c++;
			i++;
		}
		data->paths.pc[c] = '\0';
	}
	else
		extract_frgb(data, line, i, c);
}

void	extract_path(t_data *data, char *line)
{
	int		i;
	char	p[3];

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\f'
		|| line[i] == '\v' || line[i] == '\r' || line[i] == '\n')
		i++;
	if ((line[i] == 'C' || line[i] == 'F') && line[i + 1])
	{
		extract_rgb(data, line[i], line, i + 1);
	}
	else
	{
		if (line[i + 1] && line[i + 2])
		{
			p[0] = line[i];
			p[1] = line[i + 1];
			p[2] = '\0';
			extract_xpm(data, p, line, i + 2);
		}
		else
			exit(ft_exit(data, "Error: Path unreadable"));
	}
}

void	get_paths(t_data *data)
{
	int	i;

	i = 0;
	while (data->tmp[i] && i < 6)
	{
		extract_path(data, data->tmp[i]);
		i++;
	}
}
