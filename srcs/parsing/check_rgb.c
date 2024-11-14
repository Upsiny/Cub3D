/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:41:56 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/23 00:34:05 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

int	check_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != ',' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_rgb(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->t.rgbc[i] < 0 || data->t.rgbc[i] > 255
			|| data->t.rgbf[i] < 0 || data->t.rgbf[i] > 255)
			exit (ft_exit(data, "Error: RGB format not respected"));
		i++;
	}
	return (1);
}

void	check_f(t_data *data)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (data->paths.pf[i])
	{
		if (data->paths.pf[i] == ',')
			c++;
		i++;
	}
	if (c != 2)
	{
		exit (ft_exit(data, "Error: RGB format not respected"));
	}
	if (check_number(data->paths.pf) == 0)
	{
		exit (ft_exit(data, "Error: RGB format not respected"));
	}
}

// verif 3 nombres dans rgb toit

void	check_c(t_data *data)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (data->paths.pc[i])
	{
		if (data->paths.pc[i] == ',')
			c++;
		i++;
	}
	if (c != 2)
	{
		exit (ft_exit(data, "Error: RGB format not respected"));
	}
	if (check_number(data->paths.pc) == 0)
	{
		exit (ft_exit(data, "Error: RGB format not respected"));
	}
}

int	*convert_rgb(char *d, t_data *data)
{
	char	**tmp;
	int		*rgb;
	int		i;

	i = 0;
	tmp = ft_split(d, ',');
	while (tmp[i])
		i++;
	if (i != 3)
	{
		free_tmp_int(tmp);
		exit(ft_exit(data, "Error: RGB format not respected"));
	}
	rgb = malloc(sizeof(int) * 3);
	i = 0;
	while (i != 3)
	{
		rgb[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
		i++;
	}
	free (tmp);
	return (rgb);
}
