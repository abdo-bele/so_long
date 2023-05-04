/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:35 by aarchtou          #+#    #+#             */
/*   Updated: 2023/02/09 16:33:12 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map3(t_data *data, int i, int j)
{
	if (data->map[j][i] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->mur, i * 64, j * 64);
	if (data->map[j][i] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, i * 64, j * 64);
}

void	draw_map2(t_data *data, int i, int j)
{
	draw_map3(data, i, j);
	if (data->map[j][i] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, i * 64, j * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			data->player, i * 64, j * 64);
				data->y_p = j * 64;
				data->x_p = i * 64;
	}
	if (data->map[j][i] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, i * 64, j * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			data->exite, i * 64, j * 64);
	}
	if (data->map[j][i] == 'L')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, i * 64, j * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			data->enmi, i * 64, j * 64);
	}
}

int	draw_map(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	data->count = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			draw_map2(data, i, j);
			if (data->map[j][i] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->ground, i * 64, j * 64);
				mlx_put_image_to_window(data->mlx, data->win,
					data->colect, i * 64, j * 64);
				data->count++;
			}
			i++;
		}
		j++;
	}
	return (0);
}
