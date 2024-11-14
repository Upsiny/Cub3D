/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:43:15 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/23 00:47:14 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

int	get_width(t_data *data)
{
	int	w;
	int	i;
	int	j;

	w = 0;
	i = 0;
	while (data->file[i])
	{
		if (line_is_empty(data->file[i]) == 1)
		{
			j = 0;
			while (data->file[i][j])
				j++;
			if (j > w)
				w = j;
		}
		i++;
	}
	return (w);
}

int	get_length(char **file, t_data *data)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (file[i])
	{
		if (c < 7)
			c += line_is_empty(file[i]);
		else
			c++;
		i++;
	}
	if (c < 7)
		exit(ft_exit(data, "Error: Missing file content"));
	return (c);
}

void	remove_empty_lines(t_data *data)
{
	int	i;

	i = 0;
	data->map.length = get_length(data->file, data);
	data->tmp = ft_calloc(data->map.length + 1, sizeof(char *));
	if (data->tmp == NULL)
		exit(ft_exit(data, "Malloc error"));
	data->map.width = get_width(data);
	data->tmp[data->map.length] = NULL;
	while (i < data->map.length)
	{
		data->tmp[i] = ft_calloc(data->map.width + 1, sizeof(char *));
		i++;
	}
}

void	get_clean_file(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	remove_empty_lines(data);
	while (data->file[i])
	{
		if (line_is_empty(data->file[i]) == 0 && j < 7)
			i++;
		else
		{
			cpy_tmp_file(data, i, j);
			j++;
			i++;
		}
	}
	data->tmp[j] = NULL;
	data->bool = 1;
}

void	get_file(t_data *data)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = get_next_line(data->fd);
	while (line != NULL)
	{
		data->file[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->file[i])
			exit(ft_exit(data, "Error: Malloc error"));
		while (line[j] != '\0' && line[j] != '\n')
		{
			data->file[i][j] = line[j];
			j++;
		}
		data->file[i][j] = '\0';
		j = 0;
		free(line);
		line = get_next_line(data->fd);
		i++;
	}
	data->bfile = 1;
}
