/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:48:32 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/23 00:24:33 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	affiliate_ea(t_data *data, char *line, int *tmp)
{
	if (data->paths.pe)
		exit(ft_exit(data, "Error: Same path has multiple declaration"));
	data->paths.pe = (char *)malloc(sizeof(char) * (tmp[1] + 1));
	tmp[1] = 0;
	while (line[tmp[0]])
	{
		data->paths.pe[tmp[1]] = line[tmp[0]];
		tmp[1]++;
		tmp[0]++;
	}
	data->paths.pe[tmp[1]] = '\0';
}

void	affiliate_we_ea(t_data *data, char *pre, char *line, int *tmp)
{
	if (ft_strcmp(pre, "WE") == 0)
	{
		if (data->paths.pw)
			exit(ft_exit(data, "Error: Same path has multiple declaration"));
		data->paths.pw = (char *)malloc(sizeof(char) * (tmp[1] + 1));
		tmp[1] = 0;
		while (line[tmp[0]])
		{
			data->paths.pw[tmp[1]] = line[tmp[0]];
			tmp[1]++;
			tmp[0]++;
		}
		data->paths.pw[tmp[1]] = '\0';
	}
	else
		affiliate_ea(data, line, tmp);
}

void	affiliate_so(t_data *data, char *line, int *tmp)
{
	if (data->paths.ps)
		exit(ft_exit(data, "Error: Same path has multiple declaration"));
	data->paths.ps = (char *)malloc(sizeof(char) * (tmp[1] + 1));
	tmp[1] = 0;
	while (line[tmp[0]])
	{
		data->paths.ps[tmp[1]] = line[tmp[0]];
		tmp[1]++;
		tmp[0]++;
	}
	data->paths.ps[tmp[1]] = '\0';
}

void	affiliate_no_so(t_data *data, char *pre, char *line, int *tmp)
{
	if (ft_strcmp(pre, "NO") == 0)
	{
		if (data->paths.pn)
			exit(ft_exit(data, "Error: Same path has multiple declaration"));
		data->paths.pn = (char *)malloc(sizeof(char) * (tmp[1] + 1));
		tmp[1] = 0;
		while (line[tmp[0]])
		{
			data->paths.pn[tmp[1]] = line[tmp[0]];
			tmp[1]++;
			tmp[0]++;
		}
		data->paths.pn[tmp[1]] = '\0';
	}
	else
		affiliate_so(data, line, tmp);
}

void	extract_xpm(t_data *data, char *pre, char *line, int i)
{
	int	c;
	int	tmp[2];

	c = 0;
	while (line[i] == ' ' || line[i] == '\n' || line[i] == '\f'
		|| line[i] == '\t' || line[i] == '\v' || line[i] == '\r')
		i++;
	c = ft_strlen(line) - i;
	tmp[0] = i;
	tmp[1] = c;
	if (ft_strcmp(pre, "NO") == 0 || ft_strcmp(pre, "SO") == 0)
		affiliate_no_so(data, pre, line, tmp);
	else if (ft_strcmp(pre, "WE") == 0 || ft_strcmp(pre, "EA") == 0)
		affiliate_we_ea(data, pre, line, tmp);
	else
		exit(ft_exit(data, "Error: Path unreadable"));
}
