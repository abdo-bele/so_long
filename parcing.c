/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:16 by aarchtou          #+#    #+#             */
/*   Updated: 2023/02/17 14:00:08 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_path(t_data *data)
{
	char	*path;
	int		i;
	int		a;

	path = ".ber";
	a = ft_strlen(path) - 1;
	i = ft_strlen(data->path) - 1;
	while (i >= 0 && a >= 0)
	{
		if (data->path[i] != path[a] || a == i)
			return (0);
		i--;
		a--;
	}
	return (1);
}

static int	chek_map(char *ab, int a)
{
	int	i;

	i = 0;
	if (a == 1)
	{
		while (ab[i])
		{
			if (ab[i] != '1' && ab[i] != '0' && ab[i] != 'C'
				&& ab[i] != 'E' && ab[i] != 'P'
				&& ab[i] != '\n')
				return (0);
			i++;
		}
	}
	if (a == 0)
	{
		while (ab[i] != '\0' && ab[i] != '\n')
		{
			if (ab[i] != '1' && ab[i] != '0' && ab[i] != 'C'
				&& ab[i] != 'E' && ab[i] != 'P')
				return (0);
			i++;
		}
	}
	return (i);
}

static void	ft_cpy_map(t_data *data)
{
	char	*ab;
	char	*line;
	char	**mapcpy;

	ab = strdup("");
	data->fd = open(data->path, O_RDONLY);
	line = get_next_line(data->fd);
	while (line)
	{
		ab = ft_strjoinn(ab, line);
		free (line);
		if (chek_map(ab, 1) == 0)
		{
			free(ab);
			exit(1);
		}
		line = get_next_line(data->fd);
	}
	free(line);
	chek_pl_ex(ab, data);
	data->map = ft_split(ab, '\n');
	mapcpy = ft_split(ab, '\n');
	parsing2(data);
	backtrack(data, mapcpy);
	free (ab);
}

static int	ft_check_map(t_data	*data)
{
	char	*line;
	int		i;

	i = 0;
	data->fd = open(data->path, O_RDONLY);
	line = get_next_line(data->fd);
	data->w = ft_strlen(line) - 1;
	data->h = 0;
	while (line)
	{
		i = chek_map(line, 0);
		if (i != data->w || line == NULL)
			return (free(line), 0);
		free (line);
		line = get_next_line(data->fd);
		(*data).h++;
	}
	free (line);
	if (data->w == data->h || data->h < 3 || data->w == 0)
		return (0);
	close(data->fd);
	ft_cpy_map(data);
	return (1);
}

void	parcing(t_data *data, int ac)
{
	data->pl = 0;
	data->ex = 0;
	if (ac != 2)
	{
		write(1, "Error\nUsage: ./so_long map.ber", 31);
		exit(1);
	}
	if (ft_check_path(data) == 0)
	{
		write(1, "Error\nInvalid path", 19);
		exit(1);
	}
	if (ft_check_map(data) == 0)
	{
		write(1, "Error\nInvalid map", 18);
		exit(1);
	}
	if (ft_check_collect_number(data) == 0)
	{
		write(1, "Error\nNo collect", 16);
		exit(1);
	}
}
