/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:52:38 by aarchtou          #+#    #+#             */
/*   Updated: 2023/02/18 15:07:18 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_player(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		write (1, "you exit", 8);
		mlx_clear_window(data->mlx, data->win);
		exit(1);
	}
	if (keycode == 13 || keycode == 126)
		up(data);
	if (keycode == 0 || keycode == 123)
		l(data);
	if (keycode == 1 || keycode == 125)
		down(data);
	if (keycode == 2 || keycode == 124)
		r(data);
	return (0);
}

void	print_coll(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
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
}

int	coll_img(t_data *data)
{
	static int	a;

	if (a == 30)
		a = 0;
	if (a == 0)
		data->colect = mlx_xpm_file_to_image(data->mlx, "xpm/collect1.xpm",
				&data->w, &data->h);
	if (a == 8)
		data->colect = mlx_xpm_file_to_image(data->mlx, "xpm/collect2.xpm",
				&data->w, &data->h);
	if (a == 16)
		data->colect = mlx_xpm_file_to_image(data->mlx, "xpm/collect3.xpm",
				&data->w, &data->h);
	if (a == 24)
		data->colect = mlx_xpm_file_to_image(data->mlx, "xpm/collect4.xpm",
				&data->w, &data->h);
	data->count = 0;
	ft_check_data(data);
	print_coll(data);
	a++;
	return (0);
}

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w * 64, data->h * 64, "bele");
	data->exite = mlx_xpm_file_to_image(data->mlx, "xpm/exit.xpm", &data->w,
			&data->h);
	data->enmi = mlx_xpm_file_to_image(data->mlx, "xpm/enmi.xpm", &data->w,
			&data->h);
	data->player = mlx_xpm_file_to_image(data->mlx, "xpm/player_sk.xpm",
			&data->w, &data->h);
	data->ground = mlx_xpm_file_to_image(data->mlx, "xpm/ground.xpm", &data->w,
			&data->h);
	data->mur = mlx_xpm_file_to_image(data->mlx, "xpm/mur.xpm", &data->w,
			&data->h);
	data->colect = mlx_xpm_file_to_image(data->mlx, "xpm/collect1.xpm",
			&data->w, &data->h);
	ft_check_data(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.path = av[1];
	data.khtawi = 0;
	parcing_b(&data, ac);
	init(&data);
	draw_map(&data);
	mlx_loop_hook(data.mlx, coll_img, &data);
	mlx_hook(data.win, 2, 1L << 0, move_player, &data);
	mlx_hook(data.win, 17, 1L << 0, ft_exit, &data);
	mlx_loop(data.mlx);
	free_map(data.map);
	return (0);
}
