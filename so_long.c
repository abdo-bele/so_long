/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:52 by aarchtou          #+#    #+#             */
/*   Updated: 2023/02/14 14:39:22 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		write(1, "you exit", 8);
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

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w * 64, data->h * 64, "bele");
	data->exite = mlx_xpm_file_to_image(data->mlx, "xpm/exit.xpm", &data->w,
			&data->h);
	data->enmi = mlx_xpm_file_to_image(data->mlx, "xpm/enmi1.xpm", &data->w,
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
	parcing(&data, ac);
	init(&data);
	draw_map(&data);
	mlx_hook(data.win, 2, 1L << 0, move_player, &data);
	mlx_hook(data.win, 17, 1L << 0, ft_exit, &data);
	mlx_loop(data.mlx);
	free_map(data.map);
	return (0);
}
