/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tols_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:42 by aarchtou          #+#    #+#             */
/*   Updated: 2023/02/13 12:28:43 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft(nb + 48);
}

void	chek_pl_ex(char	*ab, t_data *data)
{
	int	i;

	i = 0;
	while (ab[i])
	{
		if (ab[i] == 'P')
			data->pl++;
		if (ab[i] == 'E')
			data->ex++;
		if (ab[i] == 'P' || ab[i] == 'E')
		{
			if (ab[i] == 'E' && data->ex != 1)
			{
				write(1, "Error\nmore E", 12);
				exit(1);
			}
			if (ab[i] == 'P' && data->pl != 1)
			{
				write(1, "Error\nmore P", 12);
				exit(1);
			}
		}
		i++;
	}
}

int	ft_exit(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	write(1, "you exit", 8);
	exit(1);
	return (0);
}

void	ft_check_data(t_data *data)
{
	if (!data->exite || !data->enmi || !data->player
		|| !data->colect || !data->mur || !data->ground)
	{
		write(1, "Error\nimage error", 17);
		exit(1);
	}
}
