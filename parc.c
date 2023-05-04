/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:20 by aarchtou          #+#    #+#             */
/*   Updated: 2023/02/17 13:54:14 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		free(map[j]);
		j++;
	}
	free(map);
}

void	parsing2(t_data	*data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[0][i] && i < data->w)
	{
		if (data->map[0][i] != '1' || data->map[data->h - 1][i] != '1')
		{
			write (1, "lhit", 4);
			exit(1);
		}
		i++;
	}
	while (data->map[j] && j < data->h)
	{
		if (data->map[j][data->w - 1] != '1' || data->map[j][0] != '1')
		{
			write (1, "lhit", 4);
			exit(1);
		}
		j++;
	}
}

int	ft_check_collect_number(t_data *data)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	j = 0;
	b = 0;
	while (data->map[i] && i < data->h)
	{
			j = 0;
		while (data->map[i][j] && j < data->w)
		{
			if (data->map[i][j] == 'C')
				b++;
			j++;
		}
		i++;
	}
	return (b);
}
