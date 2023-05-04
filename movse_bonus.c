/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:48:53 by aarchtou          #+#    #+#             */
/*   Updated: 2023/02/18 15:05:25 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_collect(t_data *data)
{
	if (data->map[data->y_p / 64][data->x_p / 64] == 'C')
	{
			data->count--;
			data->map[data->y_p / 64][data->x_p / 64] = '0';
	}
	if (data->map[data->y_p / 64][data->x_p / 64] == 'E')
	{
		write(1, "you win", 8);
		exit(0);
	}
	if (data->map[data->y_p / 64][data->x_p / 64] == 'L')
	{
		write(1, "you lose", 8);
		exit(1);
	}
}

int	up(t_data	*data)
{
	char	*khtawi;

	if (data->map[data->y_p / 64 - 1][data->x_p / 64] != '1')
	{
		if (data->map[data->y_p / 64 - 1][data->x_p / 64] == 'E'
			&& data->count > 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, data->x_p, data->y_p);
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, data->x_p, data->y_p - 64);
		mlx_put_image_to_window(data->mlx, data->win,
			data->player, data->x_p, data->y_p - 64);
		data->y_p -= 64;
		(*data).khtawi++;
		khtawi = ft_itoa(data->khtawi);
		mlx_put_image_to_window(data->mlx, data->win, data->mur, 0, 0);
		mlx_string_put(data->mlx, data->win, 22, 15,
			0xffffff, khtawi);
		free(khtawi);
		check_collect(data);
	}
	return (0);
}

int	l(t_data *data)
{
	char	*khtawi;

	if (data->map[data->y_p / 64][data->x_p / 64 - 1] != '1')
	{
		if (data->map[data->y_p / 64][data->x_p / 64 - 1] == 'E'
			&& data->count > 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, data->x_p, data->y_p);
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, data->x_p - 64, data->y_p);
		mlx_put_image_to_window(data->mlx, data->win,
			data->player, data->x_p - 64, data->y_p);
		data->x_p -= 64;
		(*data).khtawi++;
		khtawi = ft_itoa(data->khtawi);
		mlx_put_image_to_window(data->mlx, data->win, data->mur, 0, 0);
		mlx_string_put(data->mlx, data->win, 22, 15,
			0xffffff, khtawi);
		free(khtawi);
		check_collect(data);
	}
	return (0);
}

int	down(t_data	*data)
{
	char	*khtawi;

	if (data->map[data->y_p / 64 + 1][data->x_p / 64] != '1')
	{
		if (data->map[data->y_p / 64 + 1][data->x_p / 64] == 'E'
			&& data->count > 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, data->x_p, data->y_p);
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, data->x_p, data->y_p + 64);
		mlx_put_image_to_window(data->mlx, data->win,
			data->player, data->x_p, data->y_p + 64);
		data->y_p += 64;
		(*data).khtawi++;
		khtawi = ft_itoa(data->khtawi);
		mlx_put_image_to_window(data->mlx, data->win, data->mur, 0, 0);
		mlx_string_put(data->mlx, data->win, 22, 15,
			0xffffff, khtawi);
		free(khtawi);
		check_collect(data);
	}
	return (0);
}

int	r(t_data *data)
{
	char	*khtawi;

	if (data->map[data->y_p / 64][data->x_p / 64 + 1] != '1')
	{	
		if (data->map[data->y_p / 64][data->x_p / 64 + 1] == 'E'
			&& data->count > 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, data->x_p + 64, data->y_p);
		mlx_put_image_to_window(data->mlx, data->win,
			data->ground, data->x_p, data->y_p);
		mlx_put_image_to_window(data->mlx, data->win,
			data->player, data->x_p + 64, data->y_p);
		data->x_p += 64;
		(*data).khtawi++;
		khtawi = ft_itoa(data->khtawi);
		mlx_put_image_to_window(data->mlx, data->win, data->mur, 0, 0);
		mlx_string_put(data->mlx, data->win, 22, 15,
			0xffffff, khtawi);
		free(khtawi);
		check_collect(data);
	}
	return (0);
}
