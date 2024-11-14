/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 02:04:24 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/13 02:05:57 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[0] == '\n' || line[0] == '\t' || line[0] == '\v'
			|| line[0] == ' ' || line[i] == '\r' || line[i] == 'f')
		{
			while (line[i] == ' ' || line[i] == '\t'
				|| line[i] == '\n' || line[i] == '\v'
				|| line[i] == '\r' || line[i] == 'f')
			{
				if (line[i] == '\n')
					return (0);
				i++;
			}
		}
		return (1);
	}
	return (0);
}

int	get_line_nb(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	data->fd = open(data->paths.pfile, O_RDONLY);
	line = get_next_line(data->fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
	if (i < 6)
		exit(ft_exit(data, "Error: Missing content in file"));
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n != 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	r = malloc(count * size);
	if (!r)
		return (NULL);
	ft_bzero(r, size * count);
	return (r);
}
