/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:47:19 by akunegel          #+#    #+#             */
/*   Updated: 2024/11/21 13:10:02 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

/*void	print_map(t_data *data) //debug
{
	int	i = 0;
	int	j = 0;
	
	while(data->map.map[i])
	{
		j = 0;
		while(data->map.map[j])
		{
			printf("%c", data->map.map[i][j]);
			j++;
		}
		printf("%c", '\n');
		i++;
	}
	printf("%c", '\n');printf("%c", '\n');printf("%c", '\n');
}*/

char	**invert_map(t_data *data)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char *) * data->map.length + 1);
	while (data->map.map[i])
	{
		tmp[i] = malloc(sizeof(char *) * data->map.width + 1);
		k = ft_strlen(data->map.map[i]);
		j = 0;
		while (data->map.map[i][j])
		{
			tmp[i][j] = data->map.map[i][k - 1];
			k--;
			j++;
		}
		tmp[i][j] = '\0';
		i++;
	}
	tmp[i] = NULL;
	free_map(data);
	return (tmp);
}

void	cpy_map(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 6;
	while (data->tmp[j])
	{
		k = 0;
		while (k < get_longest_line(data->tmp))
		{
			if (data->tmp[j][k] == ' ' || !data->tmp[j][k])
				data->map.map[i][k] = '2';
			else if (data->tmp[j][k] == '2')
				data->map.map[i][k] = '3';
			else
				data->map.map[i][k] = data->tmp[j][k];
			k++;
		}
		data->map.map[i][k] = '\0';
		i++;
		j++;
	}
	data->map.map[i] = NULL;
}

int	get_map_lines(char **file)
{
	int	i;

	i = 6;
	while (file[i])
	{
		i++;
	}
	return (i - 6);
}

int	get_longest_line(char **file)
{
	int	i;
	int	j;
	int	c;

	i = 6;
	c = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j] != '\0')
			j++;
		if (j > c)
			c = j;
		i++;
	}
	return (c);
}

void	get_map(t_data *data)
{
	int	i;
	int	j;

	data->map.map = malloc(sizeof(char *)
			* (get_map_lines(data->tmp) + 1));
	if (!data->map.map)
		exit(ft_exit(data, "Error: Malloc error"));
	i = get_longest_line(data->tmp);
	j = 0;
	while (j < get_map_lines(data->tmp))
	{
		data->map.map[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (data->map.map[j] == NULL)
		{
			while (j > 0)
				free(data->map.map[--j]);
			free(data->map.map);
			exit(ft_exit(data, "Error: Malloc error"));
		}
		j++;
	}
	data->map.map[j] = NULL;
	cpy_map(data);
	data->map.map = invert_map(data);
}
